#ifndef __PROCESS_H__
#define __PROCESS_H__

#include<stdio.h>
#include<stdlib.h>

struct point 
{
	double x;
	double y;
	double z;
};

int make_tabl(struct point ***tabl, double **all, int count_all, int *cx, int *cy);
int make_new_tabl(int nx, int ny, double mx, double my, struct point ***new, struct point **all, int cx, int cy);
int process(struct point **tabl, double mx, double my, int nx, int ny, double *a);
void free_matrix(struct point **p, int nx);
int polenom_method(int n, double x, double *new_x, double *new_y, double *answ);

#endif
