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

size_t count_points(stream_t f)
{
    if (!f)
        return 0;
    struct point p;
    size_t n = 0;
    while (fscanf(f, "%d %lf %lf %lf",&p.n, &p.x, &p.y, &p.z) == 4)
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
            if (fscanf(f, "%d %lf %lf %lf",&p.n, &p.x, &p.y, &p.z) != 4)
            {
                delete [] buf;
                break;
            }

            buf[i].x = p.x;
            buf[i].y = p.y;
            buf[i].z = p.z;
            buf[i].n = p.n;
            std::cout << buf[i].x << buf[i].y <<  buf[i].z << buf[i].n <<std::endl;
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
        while (fscanf(f, "%d->%d",&mi, &mj) == 2)
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
    std::cout << "readed file: "<<std::endl;
    if (!f)
        return ERR_EMPTY;

    free_fig(fig);

    rc_type rc = OK;
    fig.n = count_points(f);
    if (fig.n > 0)
    {
        fig.mas = create_mas(f,fig.n);
        if (fig.mas)
        {
            fig.matrix = create_matrix(f,fig.n);
            if (!fig.matrix)
            {
                delete [] fig.mas;
                rc = ERR_MEMORY;
            }
        }
        else
        {
            rc = ERR_MEMORY;
        }
    }
    else
    {
        rc = ERR_INPUT;
    }

    return rc;
}
