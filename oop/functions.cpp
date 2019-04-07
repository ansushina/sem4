#include "process.h"
#include "io.h"
#include "mainwindow.h"
#include "functions.h"
#include "action.h"
#include "controller.h"

rc_type download_model(figure_t &fig, action_t act)
{
    const char *filename = get_filename(act);
    char fname[100] = "../oop/";
    strncat(fname, filename,100);
    stream_t stream;
    rc_type rc = open_file_read(stream, fname);
    if (rc)
        return rc;
    rc = read_from_file(stream,fig);
    close_file(stream);
    return rc;
}

void perenos(struct point &a, double dx, double dy, double dz)
{
    double x = get_point_x(a) + dx;
    double y = get_point_y(a) + dy;
    double z = get_point_z(a) + dz;
    set_point_x(a,x);
    set_point_y(a,y);
    set_point_z(a,z);
}

rc_type perenos_fig(figure_t &fig, action_t act)
{
    if (is_empty(fig))
        return ERR_EMPTY;
    double dx = get_deltax(act);
    double dy = get_deltay(act);
    double dz = get_deltaz(act);
    for (size_t i = 0; i < get_fig_n(fig); i++)
    {
        perenos(get_point(fig,i),dx,dy,dz);
    }
    return OK;
}

void pov_ax(struct point &a, struct point c, double ax)
{
    //double xc = get_point_x(c);
    double yc = get_point_y(c);
    double zc = get_point_z(c);
    //double xa = get_point_x(a);
    double ya = get_point_y(a);
    double za = get_point_z(a);
    double z = zc + (za- zc) * cos(ax * PI / 180) +
            (ya - yc) * sin(ax * PI / 180);
    double y = yc - (za - zc) * sin(ax * PI / 180) +
            (ya - yc) * cos(ax * PI / 180);
    set_point_z(a,z);
    set_point_y(a,y);
}

void pov_ay(struct point &a, struct point c, double ay)
{

    double xc = get_point_x(c);
   // double yc = get_point_y(c);
    double zc = get_point_z(c);
    double xa = get_point_x(a);
    //double ya = get_point_y(a);
    double za = get_point_z(a);
    double x = xc + (xa- xc) * cos(ay * PI / 180) +
            (za - zc) * sin(ay * PI / 180);
    double z = zc - (xa - xc) * sin(ay * PI / 180) +
            (za - zc) * cos(ay * PI / 180);
    set_point_x(a,x);
    set_point_z(a,z);
}
void pov_az(struct point &a, struct point c, double az)
{
    double xc = get_point_x(c);
    double yc = get_point_y(c);
    //double zc = get_point_z(c);
    double xa = get_point_x(a);
    double ya = get_point_y(a);
   // double za = get_point_z(a);
    double x = xc + (xa- xc) * cos(az * PI / 180) +
            (ya - yc) * sin(az * PI / 180);
    double y = yc - (xa - xc) * sin(az * PI / 180) +
            (ya - yc) * cos(az * PI / 180);
    set_point_x(a,x);
    set_point_y(a,y);
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

rc_type povorot_fig(figure_t &fig, action_t act)
{
    if (is_empty(fig))
        return ERR_EMPTY;
    double ax = get_alphax(act);
    double ay = get_alphay(act);
    double az = get_alphaz(act);

    struct point c;
    zero_point(c);
    for (size_t i = 0; i < get_fig_n(fig); i++)
    {
        povorot(get_point(fig,i),c,ax,ay,az);
    }
    return OK;
}

void mastab(struct point &a, struct point m, double k)
{
    double x = get_point_x(m) + k*(get_point_x(a) - get_point_x(m));
    double y = get_point_y(m) + k*(get_point_y(a) - get_point_y(m));
    double z = get_point_z(m) + k*(get_point_z(a) - get_point_z(m));
    set_point_x(a,x);
    set_point_y(a,y);
    set_point_z(a,z);
}

rc_type mastab_fig(figure_t &fig, action_t act)
{
    if (is_empty(fig))
        return ERR_EMPTY;
    double k = get_k(act);
    struct point m;
    zero_point(m);
    for (size_t i = 0; i < get_fig_n(fig); i++)
    {
        mastab(get_point(fig,i),m,k);
    }
    return OK;

}
rc_type clear_fig(figure_t &fig)
{
    free_fig(fig);
    return OK;
}
rc_type draw_fig(figure_t &fig, myscene_t scene)
{
    clear_scene(scene);
    draw_model(fig,scene);
    return OK;
}
