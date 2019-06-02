#include "alg.h"
#include <vector>

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



int is_visible(point p, std::vector<double> top, std::vector<double> down)
{
    if (p.y() < top[p.x()] && p.y() > down[p.x()]) return 0;
    if (p.y() >= top[p.x()]) return 1;
    return -1;
}

void horizon(int x1, int y1, int x2, int y2, std::vector<double> top, std::vector<double> down, QPainter &painter)
{
    if (x2 < x1)
    {
        std::swap(x1,x2);
        std::swap(y1,y2);
    }
    if (x2 == x1)
    {
        top[x2] = top[x2]>y2?top[x2]:y2;
        down[x2 ] = down[x2]<y2?down[x2]:y2;
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
        for (int x = x1; x < x2; x++)
        {
            int y = round(m * (x - x1)+y1);
            top[x] = top[x]>y?top[x]:y;
            down[x] = down[x]<y?down[x]:y;
            if (x >= 0 && x <= WINDOW_WIDTH)
            {
                painter.drawLine(x_prev, y_prev,x,y);
            }
        }
    }
}

void EdgeWhatcher(point &p, point &pedge,  std::vector<double> top, std::vector<double> down, QPainter &painter)
{

    if (pedge.x() != -1)
    {
        horizon(pedge.x(),pedge.y(),p.x(),p.y(),top,down,painter);
    }
    pedge = p;
}




point FindIntersection(point p1, point p2, std::vector<double> vector)
{
    point a(p1);
    double dx = p2.x() - p1.x();
    double dy = p2.y() - p1.y();

    double vx1 = vector[p1.x()];
    double vx2 = vector[p2.x()];
     double dy_p = vx2- vx1;
    double m = dy/dx;
    if (dx == 0)
    {
        a.setX(p2.x());
        a.setY(vector[p2.x()]);
    }
    else if (p1.y() == vx1  && p2.y() == vx2)
    {
        a = p1;
    }
    else
    {
        if (dy != dy_p)
        {
            a.setX(p1.x() - round(dx*(p1.y() - vx1)/(dy - dy_p)));
            a.setY(round((a.x() - p1.x())*m + p1.y()));
        }
    }
    return a;
}

void rotation_ax(struct point &a,  double ax)
{
    double yc = 0;
    double zc = 0;
    double ya = a.y();
    double za = a.z();
    double alpha = ax * PI / 180;
    double cosa = cos(alpha);
    double sina = sin(alpha);
    double z = zc + (za- zc) * cosa + (ya - yc) * sina;
    double y = yc - (za - zc) * sina + (ya - yc) * cosa;
    a.setY(y);
    a.setZ(z);
}

void rotation_ay(struct point &a, double ay)
{
    double xc = 0;
    double zc = 0;
    double xa = a.x();
    double za = a.z();
    double alpha = ay * PI / 180;
    double cosa = cos(alpha);
    double sina = sin(alpha);
    double x = xc + (xa- xc) * cosa + (za - zc) * sina;
    double z = zc - (xa - xc) * sina + (za - zc) * cosa;
    a.setX(x);
    a.setZ(z);
}
void rotation_az(struct point &a, double az)
{
    double xc = 0;
    double yc = 0;
    double xa = a.x();
    double ya = a.y();
    double alpha = az * PI / 180;
    double cosaz = cos(alpha);
    double sinaz = sin(alpha);

    double x = xc + (xa- xc) * cosaz + (ya - yc) * sinaz;
    double y = yc - (xa - xc) * sinaz + (ya - yc) * cosaz;
    a.setX(x);
    a.setY(y);
}
point rotation(point &b, params p)
{
    double xc = WINDOW_WIDTH/2;
    double yc = WINDOW_WIDTH/2;

    double ax = p.alphax;
    double ay = p.alphay;
    double az = p.alphaz;
    point a = b;
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

    b.setX(round(a.x()*50 + xc));
    b.setY(round(a.y()*50 + yc));
    return b;
}

void begin_trasform(params &p)
{
    double xc = WINDOW_WIDTH/2;
    double yc = WINDOW_WIDTH/2;
    p.xbegin *= 50;
    p.zbegin *= 50;
    p.zend *= 50;
    p.xend *= 50;
    p.xdelta *= 50;
    p.zdelta *= 50;

    p.xbegin += xc;
    p.xend += xc;
    p.zbegin += yc;
    p.zend += yc;
}

void horizon_alg(params Params, QPainter &painter)
{
    std::vector<double> top(WINDOW_WIDTH, 0);
    std::vector<double> down(WINDOW_WIDTH, WINDOW_WIDTH);


    double x;
    point prev,left(-1,-1),right(-1,-1),i;
    for(double z = Params.zend; z >= Params.zbegin; z -= Params.zdelta)
    {
        double y_p = Params.func(Params.xbegin,z);
        point p(Params.xbegin,y_p,z);
        prev = rotation(p,Params);
        EdgeWhatcher(prev,left,top,down,painter);
        int P = is_visible(prev,top,down);
        for (x = Params.xbegin; x < Params.xend; x += Params.xdelta)
        {
            point curr(0,0);
            y_p = Params.func(x,z);
            point p(x,y_p,z);
            curr = rotation(p,Params);
            int V = is_visible(curr,top,down);
            if (V == P)
            {
                if (P)
                {
                    horizon(prev.x(), prev.y(),curr.x(),curr.y(),top,down,painter);
                }
            }
            else if (!V)
            {
                if (P == 1)
                {
                    i = FindIntersection(prev,curr,top);
                }
                else
                {
                    i = FindIntersection(prev,curr,down);
                }
                horizon(prev.x(), prev.y(),i.x(),i.y(),top,down,painter);
            }
            else if (V == 1)
            {
                if (P == 0)
                {
                     i = FindIntersection(prev,curr,top);
                     horizon(prev.x(), prev.y(),i.x(),i.y(),top,down,painter);
                }
                else
                {
                    i = FindIntersection(prev,curr,top);
                    horizon(prev.x(), prev.y(),i.x(),i.y(),top,down,painter);
                    i = FindIntersection(prev,curr,top);
                    horizon(prev.x(), prev.y(),curr.x(),curr.y(),top,down,painter);
                }
            }
            else
            {
                if (P == 0)
                {
                     i = FindIntersection(prev,curr,top);
                     horizon(prev.x(), prev.y(),i.x(),i.y(),top,down,painter);
                }
                else
                {
                    i = FindIntersection(prev,curr,top);
                    horizon(prev.x(), prev.y(),i.x(),i.y(),top,down,painter);
                    i = FindIntersection(prev,curr,top);
                    horizon(prev.x(), prev.y(),curr.x(),curr.y(),top,down,painter);
                }
            }
            P = V;
            prev = curr;
        }

    }

}




