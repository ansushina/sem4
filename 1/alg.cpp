#include "alg.h"
#include <iostream>

int find_kosat(cent c1, cent c2, double r1, double r2, line_t *l)
{
    //ax+by+c=0 -касательная
    //a2+b2=1 - нормализация
    //ax1 + by1 + c = r1 и ax2 + by2 + c = r2
    //aΔx + bΔy = Δr

    double d = (c1.x-c2.x)*(c1.x-c2.x) + (c1.y-c2.y)*(c1.y-c2.y);
    if (d <= 0)
        return 1;
    d = sqrt(d);
    //aX + bY = R
    //a2 + b2 = 1
    double x = (c2.x-c1.x)/d;
    double y = (c2.y-c1.y)/d;
    double r = (r2-r1)/d;

    if (1-r*r < 0)
        return 1;

    l->a = r*x - y*sqrt(1-r*r);
    l->b = r*y + x*sqrt(1-r*r);
    l->c = r1 - (l->a*c1.x + l->b*c1.y );

    std::cout <<"a b c "<< l->a <<" "<< l->b<< " " << l->c << std::endl;
    return 0;
}

void find_point(cent c, line_t l, cent *p)
{
    double k = -l.a/l.b;
    double b = -l.c/l.b;

    p->x = -(-c.x + k * b - k * c.y)/(1 + k*k);
    p->y = k * p->x + b;
    std::cout <<"x y "<< p->x <<" "<< p->y << std::endl;
}

int find_s(cent c1, double r1, cent c2, double r2, double *s)
{
    double a = sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y)); // расстояние между центрами
    double h = a*a - (r2-r1)*(r2-r1);// теорема Пифагора
    if (h <= 0) //треугольника не существует
        return 1;
    //std::cout << h <<"r "<< r1 << r2 << std::endl;
    h = sqrt(h);
    *s = h*(r1+r2)/2; //найдем площадь
    //std::cout << h << std::endl;
    return 0;
}

int find_circle(cent p1, cent p2, cent p3, cent *c1, double *r)
{
    double a = 2*(p2.x-p1.x);
    double b = 2*(p2.y-p1.y);
    double c = p2.x*p2.x - p1.x * p1.x + p2.y*p2.y - p1.y * p1.y;
    double d = 2*(p3.x - p2.x);
    double e = 2*(p3.y - p2.y);
    double f = p3.x * p3.x - p2.x * p2.x + p3.y * p3.y - p2.y * p2.y;
    double p = a*e-d*b;
    if (fabs(p) < EPS)
        return 1;
    c1->x=(c*e-b*f)/p;
    c1->y=(a*f-c*d)/p;
    *r = sqrt((p1.x - c1->x)*(p1.x-c1->x)+(p1.y - c1->y)*(p1.y - c1->y));
    return 0;
}
