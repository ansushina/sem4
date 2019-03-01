#ifndef __IO_H__
#define __IO_H__

#include<stdio.h>
#include<stdlib.h>


int read_tab(char *fname, double **all_x, double **all_y, int *all_count);

int read_input( double *x);

int read_all(char *fname, double **all_x, double **all_y, int *all_count, double *x);


#endif