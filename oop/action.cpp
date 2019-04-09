#include "action.h"
#include "figure.h"

struct point &get_point(struct figure &fig, int i)
{
    return fig.arr[i];
}

double get_alphax(struct data &d)
{
    return d.rotation.ax;
}
double get_alphay(struct data &d)
{
    return d.rotation.ay;
}
double get_alphaz(struct data &d)
{
    return d.rotation.az;
}

double get_deltax(struct data &d)
{
    return d.move.dx;
}
double get_deltay(struct data &d)
{
    return d.move.dy;
}
double get_deltaz(struct data &d)
{
    return d.move.dy;
}
double get_k(struct data &d)
{
    return d.scale.k;
}

const char *get_filename(struct data &d)
{
    return d.filename;
}
