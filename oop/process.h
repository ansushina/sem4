#ifndef PROCESS_H
#define PROCESS_H

#define POVOROT_NUMBER 3
#define MASTAB_NUMBER 2
#define PERENOS_NUMBER 1
#define DOWNLOAD 4
#define DELETE_NUMBER 5

#define PI 3.14


#include <QGraphicsScene>

void perenos(struct point &a, double dx, double dy, double dz);
void perenos_all(struct figure &fig, double dx, double dy, double dz);
void mastab(struct point &a, struct point m, double k);
void mastab_all(struct figure &fig, double k);
void povorot(struct point &a, struct point c, double ax, double ay, double az);
void povorot_all(struct figure &fig, double ax, double ay,double az);
int download_model( struct figure &fig, const char *filename);
void draw_model(figure fig, QGraphicsScene *scene);
int is_empty(struct figure &fig);
int do_process(int number, struct data d, struct figure &fig, QGraphicsScene *scene);
#endif // PROCESS_H
