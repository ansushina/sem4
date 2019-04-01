#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"
#include "matrix.h"

typedef struct figure figure_t;

struct figure
{
    struct point *mas;
    size_t n;

    int **matrix;
};

size_t &get_fig_n(struct figure &fig);
point_t ()

#endif // FIGURE_H
