#ifndef ACTION_H
#define ACTION_H

#include "points.h"

typedef struct data action_t;

struct data
{
    const char *filename;
    struct
    {

        double ax;
        double ay;
        double az;
    } pov;
    struct
    {
        double k;
    } mast ;
    struct
    {

        double dx;
        double dz;
        double dy;
    } per;
};

struct point &get_point(struct figure &fig, int i);
double get_alphax(struct data &d);
double get_alphay(struct data &d);
double get_alphaz(struct data &d);
double get_deltax(struct data &d);
double get_deltay(struct data &d);
double get_deltaz(struct data &d);
double get_k(struct data &d);
const char *get_filename(struct data &d);

#endif // DATA_H
