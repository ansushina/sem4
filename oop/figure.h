#ifndef FIGURE_H
#define FIGURE_H

#include "points.h"
#include "matrix.h"

typedef struct figure figure_t;

struct figure
{
    struct point *mas;
    size_t n;
    int **matrix;
};

size_t &get_fig_n(struct figure &fig);
int is_empty(struct figure &fig);
void free_fig(struct figure &fig);
figure_t init_fig();
int get_matrix_el(figure_t fig, size_t i, size_t j);

#endif // FIGURE_H
