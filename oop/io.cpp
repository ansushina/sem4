#include "io.h"
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

void rewind_file(stream_t stream)
{
    rewind(stream);
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
    rewind_file(f);
    return n;
}

point_t *allocate_arr(size_t n)
{
    struct point *buf = new struct point[n];
    return buf;
}

rc_type create_arr(point_t *arr, size_t n, stream_t f)
{
    if (!f || !n || !arr)
        return ERR_INPUT;
    struct point p;

    rc_type rc = OK;
    for (size_t i = 0; i < n && !rc; i++)
    {
        if (read_line_point(f,p) != OK)
        {
            rc = ERR_INPUT;
        }
        else
        {
             copy_point(arr[i],p);
        }
    }
    return rc;
}

rc_type create_matrix(matrix_t mt, size_t n, stream_t f)
{
    if (!f || !n || !mt)
        return ERR_INPUT;

    int mi,mj;
    while (read_line_mt_el(f,mi,mj) == OK)
    {
        mt[mi-1][mj-1] = 1;
        mt[mj-1][mi-1] = 1;
        //std::cout << mi<<"->"<<mj<<std::endl;
    }
    return OK;
}

int read_from_file(struct figure &fig, stream_t f)
{
    if (!f)
        return ERR_EMPTY;

    rc_type rc = OK;

    size_t n = count_points(f);
    if (n <= 0) return ERR_INPUT;

    point_t *arr = allocate_arr(n);
    matrix_t matrix = allocate_matrix(n);
    if (!arr || !matrix)
    {
        delete [] arr;
        free_matrix(matrix,n);
        return ERR_MEMORY;
    }

    rc = create_arr(arr, n, f);
    if (rc == OK)
    {
        rc = create_matrix(matrix,n,f);
    }

    if (rc == OK)
    {
         free_fig(fig);
         set_fig_n(fig, n);
         set_fig_arr(fig,arr);
         set_fig_matrix(fig,matrix);
    }
    else
    {
        delete [] arr;
        free_matrix(matrix,n);
    }
    return rc;
}
