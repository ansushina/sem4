#ifndef PROCESS_H
#define PROCESS_H

#define POVOROT_NUMBER 3
#define MASTAB_NUMBER 2
#define PERENOS_NUMBER 1
#define DOWNLOAD 4
#define DELETE 5
#include <QGraphicsScene>

int do_process(int number, struct data d, struct figure &fig, QGraphicsScene *scene);

#endif // PROCESS_H