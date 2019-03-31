#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "process.h"
#include "io.h"
#include "mainwindow.h"
#include "structs.h"

struct point &get_point(struct figure &fig, int i);
double &get_point_x(struct point &a);
double &get_point_y(struct point &a);
double &get_point_z(struct point &a);
int &get_point_n(struct point &a);
size_t &get_fig_n(struct figure &fig);
double get_alpha(struct data &d, int i);
double get_delta(struct data &d, int i);
double get_k(struct data &d);
const char *get_filename(struct data &d);
int get_matrix_el(struct figure &fig, int i, int j);
void perenos(struct point &a, double dx, double dy, double dz);
void perenos_all(struct figure &fig, double dx, double dy, double dz);
void mastab(struct point &a, struct point m, double k);
void mastab_all(struct figure &fig, double k);
void povorot(struct point &a, struct point c, double ax, double ay, double az);
void povorot_all(struct figure &fig, double ax, double ay,double az);

#endif // FUNCTIONS_H
