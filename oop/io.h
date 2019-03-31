#ifndef IO_H
#define IO_H

#include <stdlib.h>
#include <stdio.h>

#include "structs.h"

void free_fig(struct figure &fig);
void free_matrix(int **mat, int n);
int **allocate_matrix(int n);
size_t count_points(FILE *f);
struct point *create_mas(FILE *f, size_t n);
int **create_matrix(FILE *f, size_t n);
int read_from_file(FILE *f, struct figure &fig);

#endif // IO_H
