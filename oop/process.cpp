#include "process.h"
#include "io.h"
#include "mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <string.h>
#include <math.h>

#include "functions.h"

FILE *open_file_read(const char *filename)
{
    FILE *file = fopen(filename, "r");
    return file;
}

int download_model( struct figure &fig, const char *filename)
{
    if (!filename)
        return 1;

    char fname[100] = "../oop/";
    strncat(fname,filename,100);
    //std::cout<<filename<<std::endl;

    FILE *f = open_file_read(fname);
    if (!f)
        return 1;
    //std::cout<<"open"<<std::endl;
    int rc = read_from_file(f,fig);
    fclose(f);
    return rc;
}

void draw_model(figure fig, QGraphicsScene *scene)
{
    if (is_empty(fig))
        return;
    if (!scene)
        return;
    QPen pen = QPen(Qt::black);
    std::cout << "drawing"<<std::endl;
    for (size_t i = 0; i < get_fig_n(fig); i++)
    {
        for (size_t j = 0; j < i + 1; j++)
        {

            //std::cout <<i <<j <<std::endl;
            if (get_matrix_el(fig,i,j) != 0)
            {
                double z1 = sqrt(2)/2 * get_point_z(get_point(fig,i));
                double z2 = sqrt(2)/2 * get_point_z(get_point(fig,j));
                //std::cout <<i <<std::endl;
                std::cout <<get_point(fig,i).n<<"->"<<get_point(fig,j).n <<std::endl;
                scene->addLine(get_point_x(get_point(fig,i)) - z1,-get_point_y(get_point(fig,i))+z1,
                               get_point_x(get_point(fig,j)) - z2, -get_point_y(get_point(fig,j)) + z2);
            }
        }
    }
}

int is_empty(struct figure &fig)
{
    return !(fig.mas && fig.matrix && get_fig_n(fig));
}

int do_process(int number, data d, struct figure &fig, QGraphicsScene *scene)
{
    if (number == DOWNLOAD)
    {
        std::cout<<get_filename(d)<<std::endl;
        int rc = download_model(fig, get_filename(d));
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
        perenos_all(fig,get_delta(d,0),get_delta(d,1),get_delta(d,2));
        scene->clear();
        draw_model(fig,scene);

    }
    else if (number == POVOROT_NUMBER)
    {
        povorot_all(fig,get_alpha(d,0),get_alpha(d,1), get_alpha(d,2));
        scene->clear();
        draw_model(fig,scene);
    }
    else if (number == MASTAB_NUMBER)
    {
        mastab_all(fig,get_k(d));
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


