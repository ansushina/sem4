#ifndef PROCESS_H
#define PROCESS_H

#define POVOROT_NUMBER 3
#define MASTAB_NUMBER 2
#define PERENOS_NUMBER 1
#define DOWNLOAD 4
#define DELETE_NUMBER 5

#define PI 3.14


#include <QGraphicsScene>

#include "structs.h"

int download_model( struct figure &fig, const char *filename);
void draw_model(figure fig, QGraphicsScene *scene);
int is_empty(struct figure &fig);
int do_process(int number, struct data d, struct figure &fig, QGraphicsScene *scene);
#endif // PROCESS_H
