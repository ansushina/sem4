#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef int ** matrix_t;

void free_matrix(matrix_t mat, size_t n);
matrix_t allocate_matrix(size_t n);


#endif // MATRIX_H
