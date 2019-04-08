#include "io.h"
#include "process.h"
#include "matrix.h"
#include "points.h"
#include "figure.h"

#include <iostream>


rc_type open_file_read(stream_t &stream, const char *filename)
{
     FILE *file = fopen(filename, "r");
     if (!file)
     {
         return ERR_OPEN_FILE;
     }
     stream  = file;
     return OK;
}
void close_file(stream_t stream)
{
    fclose(stream);
}

rc_type read_line_point(stream_t f, point_t &p)
{
   int n;
   double x,y,z;
   if (fscanf(f, "%d %lf %lf %lf",&n, &x, &y, &z) == 4)
   {
       set_point(p,x,y,z,n);
       return OK;
   }
   return ERR_INPUT;
}

rc_type read_line_mt_el(stream_t f, int &mi, int &mj)
{
   if (fscanf(f, "%d->%d",&mi, &mj) == 2)
       return OK;
   return ERR_INPUT;
}

size_t count_points(stream_t f)
{
    if (!f)
        return 0;
    struct point p;
    size_t n = 0;
    while (read_line_point(f,p) == OK)
    {
        n++;
    }
    rewind(f);
    return n;
}

struct point *create_mas(stream_t f, size_t n)
{
    if (!f || !n)
        return nullptr;
    struct point p;
    struct point *buf = new struct point[n]; //(struct point *)malloc(n* sizeof(struct point *));
    if (buf)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (read_line_point(f,p) != OK)
            {
                delete [] buf;
                break;
            }

            copy_point(buf[i],p);
            //std::cout << buf[i].x << buf[i].y <<  buf[i].z << buf[i].n <<std::endl;
        }
    }
    return buf;
}

int **create_matrix(stream_t f, size_t n)
{
    if (!f || !n)
        return nullptr;

    int mi,mj;
    int **mt = allocate_matrix(n);
    if (mt)
    {
        while (read_line_mt_el(f,mi,mj) == OK)
        {
            mt[mi-1][mj-1] = 1;
            mt[mj-1][mi-1] = 1;
            std::cout << mi<<"->"<<mj<<std::endl;
        }
    }
    return mt;
}

int read_from_file(stream_t f, struct figure &fig)
{
//    std::cout << "readed file: "<<std::endl;
    if (!f)
        return ERR_EMPTY;

    free_fig(fig);

    rc_type rc = OK;
    size_t n = count_points(f);

    if (n <= 0) return ERR_INPUT;




     set_fig_n(fig, n);
     point_t *mas = create_mas(f,fig.n);
     if (mas)
     {
         set_fig_mas(fig,mas);
         matrix_t matrix = create_matrix(f,fig.n);
         if (matrix)
         {
             set_fig_matrix(fig,matrix);
         }
         else
         {
            delete [] fig.mas;
            rc = ERR_MEMORY;
         }
     }
     else
     {
        rc = ERR_MEMORY;
     }


    return rc;
}
