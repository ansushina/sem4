#ifndef __PROCESS_H__
#define __PROCESS_H__

#include<stdio.h>
#include<stdlib.h>

int make_new_mas(int n, double main_x, double **x, double **y, double *all_x, 
    double *all_y, int all_count);

int process(int n, double x, double *new_x, double *new_y, double *answ);

#endif