#ifndef MESCENE_H
#define MESCENE_H
#include<QGraficsScene>

typedef struct myscene myscene_t;

struct myscene
{
    QGraficsScene *scene;
};


rc_type draw_line_scene(myscene_t scene, point_t p1, point_t p2);

#endif // MESCENE_H
