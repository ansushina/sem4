#include "alg.h"
#include <vector>
#include <QPoint>
#include <QDebug>

#define WINDOW_WIDTH 700
#define PI 3.14

int sign(int n)
{
    if (n > 0)
        return 1;
    else if (n == 0)
        return 0;
    return -1;
}

int is_visible(QPoint p, std::vector<int> &top, std::vector<int> &down)
{
    if (p.x() >= WINDOW_WIDTH || p.x() < 0) return 0;
    if (p.y() < top[int(p.x())] && p.y() > down[int(p.x())]) return 0;
    if (p.y() >= top[int(p.x())]) return 1;
    return -1;
}

void horizon(int x1, int y1, int x2, int y2, std::vector<int> &top, std::vector<int> &down, QPainter &painter)
{

    if (x2 < x1)
    {
        std::swap(x1,x2);
        std::swap(y1,y2);
    }
    if (x1 > WINDOW_WIDTH || x1 < 0)
    {
        qDebug() << "вышли за границы в горизонте";
        return;
    }
    if (x2 == x1)
    {
        top[x2] = top[x2]>y2?top[x2]:y2;
        down[x2] = down[x2]<y2?down[x2]:y2;
        if (x2 >= 0 && x2 <= WINDOW_WIDTH)
        {
            painter.drawLine(x1,y1,x2,y2);
        }
    }
    else
    {
        int x_prev = x1;
        int y_prev = y1;
        double m = (y2-y1)/(double)(x2-x1);
        for (int x = x1; x < x2 && x < WINDOW_WIDTH; x++)
        {
            int y = round(m * (x - x1)+y1);
            top[x] = top[x]>y?top[x]:y;
            down[x] = down[x]<y?down[x]:y;
            if (x >= 0 && x <= WINDOW_WIDTH)
            {
                painter.drawLine(x_prev, y_prev,x,y);
            }
            //x_prev = x;
            //y_prev = y;
        }
    }
}

void EdgeWhatcher(int &x, int &y, int &edgex, int &edgey,  std::vector<int> &top, std::vector<int> &down, QPainter &painter)
{
    if (edgex != -1)
    {
        horizon(edgex,edgey,x,y,top,down,painter);
    }
    edgex = x;
    edgey = y;
}

QPoint FindIntersection(int x1, int y1, QPoint p2, std::vector<int> &vector)
{
    QPoint a(x1,y1);
    int dx = p2.x() - x1;
    int dy_c = p2.y() - y1; //сurrent
    if (x1 > WINDOW_WIDTH || p2.x() > WINDOW_WIDTH || x1 < 0 || p2.x() < 0)
    {
        qDebug() << "вышли за границы поля при поиске пересечения";
        return a;
    }
    int vx1 = vector[x1];
    int vx2 = vector[int(p2.x())];
    int dy_p = vx2- vx1; //previous
    double m = dy_c/(double)dx;
    if (dx == 0)
    {
        a.setX(p2.x());
        a.setY(vector[p2.x()]);
    }
    else if (y1 == vx1  && p2.y() == vx2)
    {
        a.setX(x1);
        a.setY(y1);
    }
    else
    {
        if (dy_c != dy_p)
        {
            a.setX(x1 - round(dx*(y1 - vx1)/(double)(dy_c - dy_p)));
            a.setY(round((a.x() - x1)*m + y1));
        }
        else
        {

            qDebug() << "dy_c == dy_p";
        }
    }
    return a;
}

void rotation_ax(struct point &a,  double ax)
{
    double ya = a.y();
    double za = a.z();
    double alpha = ax * PI / 180;
    double cosa = cos(alpha);
    double sina = sin(alpha);
    double z = za * cosa + ya * sina;
    double y = za * sina + ya * cosa;
    a.setY(y);
    a.setZ(z);
}

void rotation_ay(struct point &a, double ay)
{
    double xa = a.x();
    double za = a.z();
    double alpha = ay * PI / 180;
    double cosa = cos(alpha);
    double sina = sin(alpha);
    double x = xa* cosa + za * sina;
    double z = xa * sina + za* cosa;
    a.setX(x);
    a.setZ(z);
}
void rotation_az(struct point &a, double az)
{

    double xa = a.x();
    double ya = a.y();
    double alpha = az * PI / 180;
    double cosaz = cos(alpha);
    double sinaz = sin(alpha);

    double x = xa * cosaz + ya * sinaz;
    double y = xa * sinaz + ya * cosaz;
    a.setX(x);
    a.setY(y);
}
QPoint rotation(point &b, params p)
{
    double xc = WINDOW_WIDTH/2 - 100;
    double yc = WINDOW_WIDTH/2;

    double ax = p.alphax;
    double ay = p.alphay;
    double az = p.alphaz;
    point a(b);
    QPoint c;
    if (az != 0)
    {
         rotation_az(a,az);
    }
    if (ax != 0)
    {
         rotation_ax(a,ax);
    }
    if (ay != 0)
    {
         rotation_ay(a,ay);
    }

    c.setX(round(a.x()*20 + xc));
    c.setY(round(a.y()*20 + yc));
    return c;
}

void horizon_alg(params Params, QPainter &painter)
{
    //#define WINDOW_WIDTH 700
    std::vector<int> top(WINDOW_WIDTH, 0);
    std::vector<int> down(WINDOW_WIDTH, WINDOW_WIDTH);

    double x, y_p;
    int T, P;

    QPoint i;
    int x_prev, y_prev;
    int x_left = -1;
    int y_left = -1;
    int x_right = -1;
    int y_right = -1;

    for(double z = Params.zend; z >= Params.zbegin; z -= Params.zdelta)
    {
        y_p = Params.func(Params.xbegin,z);
        point p(Params.xbegin,y_p,z);
        QPoint pr = rotation(p,Params);
        x_prev = pr.x();
        y_prev = pr.y();
        EdgeWhatcher(x_prev,y_prev,x_left,y_left,top,down,painter);
        P = is_visible(pr,top,down);
        for (x = Params.xbegin; x < Params.xend; x += Params.xdelta)
        {
            QPoint curr(0,0);
            y_p = Params.func(x,z);
            point p(x,y_p,z);
            curr = rotation(p,Params);
            T = is_visible(curr,top,down);
            if (T == P)
            {
                if (T == 1 || T == -1)
                {
                    horizon(x_prev, y_prev, curr.x(),curr.y(),top,down,painter);
                }
            }
            else if (T == 0)
            {
                if (P == 1)
                {
                    i = FindIntersection(x_prev, y_prev,curr,top);
                }
                else
                {
                    i = FindIntersection(x_prev, y_prev,curr,down);
                }
                horizon(x_prev, y_prev,i.x(),i.y(),top,down,painter);
            }
            else if (T == 1)
            {
                if (P == 0)
                {
                     i = FindIntersection(x_prev, y_prev,curr,top);
                     horizon(x_prev, y_prev,i.x(),i.y(),top,down,painter);
                }
                else
                {
                    i = FindIntersection(x_prev, y_prev,curr,top);
                    horizon(x_prev, y_prev,i.x(),i.y(),top,down,painter);
                    i = FindIntersection(x_prev, y_prev,curr,top);
                    horizon(i.x(), i.y(),curr.x(),curr.y(),top,down,painter);
                }
            }
            else
            {
                if (P == 0)
                {
                     i = FindIntersection(x_prev, y_prev,curr,top);
                     horizon(x_prev, y_prev,i.x(),i.y(),top,down,painter);
                }
                else
                {
                    i = FindIntersection(x_prev, y_prev,curr,top);
                    horizon(x_prev, y_prev,i.x(),i.y(),top,down,painter);
                    i = FindIntersection(x_prev, y_prev,curr,top);
                    horizon(i.x(), i.y(),curr.x(),curr.y(),top,down,painter);
                }
            }
            P = T;
            x_prev = curr.x();
            y_prev = curr.y();
        }
        EdgeWhatcher(x_prev, y_prev,x_right, y_right,top,down,painter);
    }
}




