#ifndef ALG_H
#define ALG_H
#include <vector>
#include <QPainter>

struct line_t
{
    line_t(): x1(0), x2(0), y1(0), y2(0) {};
    line_t(int x1, int x2, int y1, int y2): x1(x1), x2(x2), y1(y1), y2(y2){}
    int x1;
    int x2;
    int y1;
    int y2;
};

typedef struct point point_t;
struct point
{
    point():X(0),Y(0){}
    point(double x, double y):X(x),Y(y){}
    double X;
    double Y;

    double x() const {return this->X;}
    double y() const {return this->Y;}
    void setY(double y){this->Y = y;}
    void setX(double x){this->X = x;}

    point_t& operator =(const point_t &p)
    {
        this->X = p.x();
        this->Y = p.y();
        return *this;
    }
};



bool is_convex(std::vector<line_t> egles, int &obhod);

void alg(point p1, point p2, int obhod, std::vector<line_t> &egles, QPainter &painter);


#endif // ALG_H
