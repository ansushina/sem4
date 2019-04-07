#include "action.h"
#include "figure.h"

struct point &get_point(struct figure &fig, int i)
{
    return fig.mas[i];
}

double get_alphax(struct data &d)
{
    return d.pov.ax;
}
double get_alphay(struct data &d)
{
    return d.pov.ay;
}
double get_alphaz(struct data &d)
{
    return d.pov.az;
}

double get_deltax(struct data &d)
{
    return d.per.dx;
}
double get_deltay(struct data &d)
{
    return d.per.dy;
}
double get_deltaz(struct data &d)
{
    return d.per.dy;
}
double get_k(struct data &d)
{
    return d.mast.k;
}

const char *get_filename(struct data &d)
{
    return d.filename;
}
