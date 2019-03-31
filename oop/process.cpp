#include "process.h"
#include "io.h"
#include "mainwindow.h"
#include <iostream>
#include <QGraphicsScene>
#include <QMessageBox>
#include <string.h>
#include <math.h>

void perenos(struct point &a, double dx, double dy, double dz)
{
    a.x += dx;
    a.y += dy;
    a.z += dz;
}

void perenos_all(struct figure &fig, double dx, double dy, double dz)
{
    for (size_t i = 0; i < fig.n; i++)
    {
        perenos(fig.mas[i],dx,dy,dz);
    }
}

void mastab(struct point &a, struct point m, double k)
{
    a.x = m.x + k*(a.x - m.x);
    a.y = m.y + k*(a.y - m.y);
    a.z = m.z + k*(a.z - m.z);
}

void mastab_all(struct figure &fig, double k)
{
    struct point m;
    m.n = 0;
    m.x = 0;
    m.y = 0;
    m.z = 0;
    for (size_t i = 0; i < fig.n; i++)
    {
        mastab(fig.mas[i],m,k);
    }
}

#define PI 3.14

void povorot(struct point &a, struct point c, double ax, double ay, double az)
{
    if (az != 0)
    {
         double new_x = c.x + (a.x - c.x) * cos(az * PI / 180) + (a.y - c.y) * sin(az * PI / 180);
         a.y = c.y - (a.x - c.x) * sin(az * PI / 180) + (a.y - c.y) * cos(az * PI / 180);
         a.x = new_x;
    }
    if (ax != 0)
    {
         double new_z = c.z + (a.z - c.z) * cos(ax * PI / 180) + (a.y - c.y) * sin(ax * PI / 180);
         a.y = c.y - (a.z - c.z) * sin(ax * PI / 180) + (a.y - c.y) * cos(ax * PI / 180);
         a.z = new_z;
    }
    if (ay != 0)
    {
         double new_x = c.x + (a.x - c.x) * cos(ay * PI / 180) + (a.z - c.z) * sin(ay * PI / 180);
         a.z = c.z - (a.x - c.x) * sin(ay * PI / 180) + (a.z - c.z) * cos(ay * PI / 180);
         a.x = new_x;
    }
}

void povorot_all(struct figure &fig, double ax, double ay,double az)
{
    struct point c;
    c.n = 0;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    for (size_t i = 0; i < fig.n; i++)
    {
        povorot(fig.mas[i],c,ax,ay,az);
    }
}

int download_model( struct figure &fig, const char *filename)
{
    char fname[100] = "../oop/";
    strncat(fname,filename,100);

    FILE *f = fopen(fname, "r");
    if (!f)
        return 1;
    int rc = read_from_file(f,fig);
    fclose(f);
    return rc;
}

void draw_model(figure fig, QGraphicsScene *scene)
{
    QPen pen = QPen(Qt::black);
    std::cout << "in draw"<<std::endl;
    for (size_t i = 0; i < fig.n; i++)
    {
        for (size_t j = 0; j < fig.n; j++)
        {

            //std::cout <<i <<j <<std::endl;
            if (fig.matrix[i][j] != 0)
            {
                double z1 = sqrt(2)/2 * fig.mas[i].z;
                double z2 = sqrt(2)/2 * fig.mas[j].z;
                //std::cout <<i <<std::endl;
                std::cout <<fig.mas[j].x<<" "<<fig.mas[j].y <<std::endl;
                scene->addLine(fig.mas[i].x - z1,-fig.mas[i].y+z1, fig.mas[j].x - z2, -fig.mas[j].y + z2);
            }
        }
    }
}

int is_empty(struct figure &fig)
{
    return !(fig.mas && fig.matrix && fig.n);
}


void free_fig(struct figure &fig)
{
    if (fig.mas)
       // free(fig.mas);
        delete [] fig.mas;
    if (fig.matrix)
        free_matrix(fig.matrix, fig.n);

    fig.n = 0;
    fig.matrix = NULL;
    fig.mas = NULL;
}

int do_process(int number, data d, struct figure &fig, QGraphicsScene *scene)
{
    if (number == DOWNLOAD)
    {
        int rc = download_model(fig, d.filename);
        if (rc)
        {
            std::cout<<"file error"<<std::endl;
            QMessageBox mbox;
            mbox.setText("При открытии файла произошла ошибка. Попробуйте еще раз.");
            mbox.exec();
        }
        scene->clear();
        draw_model(fig,scene);
    }
    else if (is_empty(fig))
    {
        QMessageBox mbox;
        mbox.setText("Не выбрана модель. Загрузите новую модель, чтобы продолжить.");
        mbox.exec();
    }
    else if (number ==  PERENOS_NUMBER)
    {
        perenos_all(fig,d.per.dx,d.per.dy,d.per.dz);
        scene->clear();
        draw_model(fig,scene);

    }
    else if (number == POVOROT_NUMBER)
    {
        povorot_all(fig,d.pov.alphax,d.pov.alphay, d.pov.alphaz);
        scene->clear();
        draw_model(fig,scene);
    }
    else if (number == MASTAB_NUMBER)
    {
        mastab_all(fig,d.mast.k);
        scene->clear();
        draw_model(fig,scene);
    }
    else if (number == DELETE_NUMBER)
    {
        scene->clear();
        free_fig(fig);
    }
    else
        return 1;
    return 0;
}


