#ifndef INTERPOLATION_H
#define INTERPOLATION_H


int make_new_mas(int n, double main_x, double **x, double **y,const  double *all_x,
    const double *all_y, int all_count);

int interpolation(int n, double x, double *new_x, double *new_y, double *answ);

#endif // INTERPOLATION_H
