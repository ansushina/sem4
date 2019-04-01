#include "process.h"
#include "io.h"
#include "mainwindow.h"
#include "functions.h"

struct point &get_point(struct figure &fig, int i)
{
    return fig.mas[i];
}




double get_alpha(struct data &d, int i)
{
    return d.pov.alpha[i];
}

double get_delta(struct data &d, int i)
{
    return d.per.delta[i];
}

double get_k(struct data &d)
{
    return d.mast.k;
}

const char *get_filename(struct data &d)
{
    return d.filename;
}



void perenos(struct point &a, double dx, double dy, double dz)
{
    get_point_x(a) += dx;
    get_point_y(a) += dy;
    get_point_z(a) += dz;
}

void perenos_all(struct figure &fig, double dx, double dy, double dz)
{
    if (is_empty(fig))
        return;
    for (size_t i = 0; i < get_fig_n(fig); i++)
    {
        perenos(get_point(fig,i),dx,dy,dz);
    }
}

void mastab(struct point &a, struct point m, double k)
{
    get_point_x(a) = get_point_x(m) + k*(get_point_x(a) - get_point_x(m));
    get_point_y(a) = get_point_y(m) + k*(get_point_y(a) - get_point_y(m));
    get_point_z(a) = get_point_z(m) + k*(get_point_z(a) - get_point_z(m));
}

void mastab_all(struct figure &fig, double k)
{
    if (is_empty(fig))
        return;
    struct point m;
    get_point_n(m) = 0;
    get_point_x(m) = 0;
    get_point_y(m) = 0;
    get_point_z(m) = 0;
    for (size_t i = 0; i < get_fig_n(fig); i++)
    {
        mastab(get_point(fig,i),m,k);
    }
}

void pov_ax(struct point &a, struct point c, double ax)
{
    double new_z = get_point_z(c) + (get_point_z(a) - get_point_z(c)) * cos(ax * PI / 180) +
            (get_point_y(a) - get_point_y(c)) * sin(ax * PI / 180);
    get_point_y(a) = get_point_y(c) - (get_point_z(a) - get_point_z(c)) * sin(ax * PI / 180) +
            (get_point_y(a) - get_point_y(c)) * cos(ax * PI / 180);
    get_point_z(a) = new_z;
}

void pov_ay(struct point &a, struct point c, double ay)
{
    double new_x = get_point_x(c) + (get_point_x(a) - get_point_x(c)) * cos(ay * PI / 180) +
            (get_point_z(a) - get_point_z(c)) * sin(ay * PI / 180);
    get_point_z(a) = get_point_z(c) - (get_point_x(a) - get_point_x(c)) * sin(ay * PI / 180) +
            (get_point_z(a) - get_point_z(c)) * cos(ay * PI / 180);
    get_point_x(a) = new_x;
}
void pov_az(struct point &a, struct point c, double az)
{
    double new_x = get_point_x(c) + (get_point_x(a) - get_point_x(c)) * cos(az * PI / 180) +
            (get_point_y(a) - get_point_y(c)) * sin(az * PI / 180);
    get_point_y(a) = get_point_y(c) - (get_point_x(a) - get_point_x(c)) * sin(az * PI / 180) +
            (get_point_y(a) - get_point_y(c)) * cos(az * PI / 180);
    get_point_x(a) = new_x;
}
void povorot(struct point &a, struct point c, double ax, double ay, double az)
{
    if (az != 0)
    {
         pov_az(a,c,az);
    }
    if (ax != 0)
    {
         pov_ax(a,c,ax);
    }
    if (ay != 0)
    {
         pov_ay(a,c,ay);
    }
}

void povorot_all(struct figure &fig, double ax, double ay,double az)
{
    if (is_empty(fig))
        return;
    struct point c;
    get_point_n(c) = 0;
    get_point_x(c) = 0;
    get_point_y(c) = 0;
    get_point_z(c) = 0;
    for (size_t i = 0; i < get_fig_n(fig); i++)
    {
        povorot(get_point(fig,i),c,ax,ay,az);
    }
}
