#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "io.h"
#include "mainwindow.h"
#include "points.h"

#define PI 3.14

rc_type download_model(figure_t &fig, action_t act);
rc_type move_fig(figure_t &fig, action_t act);
rc_type rotation_fig(figure_t &fig, action_t act);
rc_type scale_fig(figure_t &fig, action_t act);
rc_type clear_fig(figure_t &fig);
rc_type draw_fig(figure_t &fig, myscene_t scene);
void move(struct point &a, double dx, double dy, double dz);
void scale(struct point &a, struct point m, double k);
void rotation(struct point &a, struct point c, double ax, double ay, double az);

void draw_model(figure_t fig, myscene_t scene);
#endif // FUNCTIONS_H
