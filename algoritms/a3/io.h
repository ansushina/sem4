#ifndef __IO_H__
#define __IO_H__

#include<stdio.h>
#include<stdlib.h>


int read_all(char *fname, double **all, int *all_count, int *nx, int *ny, double *x, double *y);

void print_tabl(double **all, int n);
#endif