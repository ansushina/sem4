#ifndef CONTROLLER_H
#define CONTROLLER_H

#define POVOROT_NUMBER 3
#define MASTAB_NUMBER 2
#define PERENOS_NUMBER 1
#define DOWNLOAD 4
#define DELETE_NUMBER 5
#define DRAW_NUMBER 6

#include"myscene.h"
#include"action.h"
#include"figure.h"

void draw_model(figure_t fig, myscene_t scene);

void controller(myscene_t scene, int act_number, action_t act);

#endif // CONTROLLER_H
