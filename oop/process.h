#ifndef PROCESS_H
#define PROCESS_H

#define POVOROT_NUMBER 3
#define MASTAB_NUMBER 2
#define PERENOS_NUMBER 1
#define DOWNLOAD 4
#define DELETE_NUMBER 5


#include <QGraphicsScene>

int do_process(int number, struct data d, struct figure &fig, QGraphicsScene *scene);

void free_fig(struct figure &fig);

#endif // PROCESS_H
