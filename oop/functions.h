#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "process.h"
#include "io.h"
#include "mainwindow.h"
#include "points.h"

#define PI 3.14

rc_type download_model(figure_t &fig, action_t act);
rc_type perenos_fig(figure_t &fig, action_t act);
rc_type povorot_fig(figure_t &fig, action_t act);
rc_type mastab_fig(figure_t &fig, action_t act);
rc_type clear_fig(figure_t &fig);
rc_type draw_fig(figure_t &fig, myscene_t scene);
void perenos(struct point &a, double dx, double dy, double dz);
void mastab(struct point &a, struct point m, double k);
void povorot(struct point &a, struct point c, double ax, double ay, double az);

void draw_model(figure_t fig, myscene_t scene);
#endif // FUNCTIONS_H
