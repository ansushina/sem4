#ifndef IO_H
#define IO_H

#include <stdlib.h>
#include <stdio.h>

struct point
{
    double x;
    double y;
    double z;
    int n;
};

struct figure
{
    struct point *mas;
    size_t n;

    int **matrix;
};


void free_matrix(int **mat, int n);
int **allocate_matrix(int n);
int read_from_file(FILE *f, struct figure &fig);

#endif // IO_H
