#ifndef GAUSS_H
#define GAUSS_H

#include <stdlib.h>
#include <assert.h>

double **allocate_matrix(int n, int m);

void free_matrix(double **data, int n);


void make_same(double **a, double **b, int n, int m);

void make_sort(int *a, int n);

//int find_main(int *p2, double **a, int n, int k);

void make_normal(double **a, int m, int i);

void make_diff(double **a, int m, int j, int i);

void make_answer(double **a, int n, int m, double **b, int *p2);

int do_gauss(double **a, int n, int m, double ***b);

#endif // GAUSS_H
