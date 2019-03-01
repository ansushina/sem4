#ifndef ALG_H
#define ALG_H

#include <math.h>
#include <iostream>

#define EPS 0.000001

typedef struct center cent;
struct center
{
    double x;
    double y;
};

typedef struct line line_t;
struct line
{
    double a;
    double b;
    double c;
};

int find_kosat(cent c1, cent c2, double r1, double r2, line_t *l);
void find_point(cent c, line_t l, cent *p, double r);
int find_s(cent c1, double r1, cent c2, double r2, double *s);
int find_circle(cent p1, cent p2, cent p3, cent *c1, double *r);

#endif // ALG_H
