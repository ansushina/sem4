#include "io.h"
#include "process.h"

#include <iostream>

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

size_t count_points(FILE *f)
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

struct point *create_mas(FILE *f, size_t n)
{
    if (!f || !n)
        return nullptr;
    struct point p;
    struct point *buf = new struct point[n]; //(struct point *)malloc(n* sizeof(struct point *));
    if (!buf)
        return NULL;
    for (size_t i = 0; i < n; i++)
    {
        if (fscanf(f, "%d %lf %lf %lf",&p.n, &p.x, &p.y, &p.z) != 4)
        {
            delete [] buf;
            return NULL;
        }

        buf[i].x = p.x;
        buf[i].y = p.y;
        buf[i].z = p.z;
        buf[i].n = p.n;
        std::cout << buf[i].x << buf[i].y <<  buf[i].z << buf[i].n <<std::endl;
    }
    return buf;
}

int **create_matrix(FILE *f, size_t n)
{
    if (!f || !n)
        return nullptr;

    int mi,mj;
    int **mt = allocate_matrix(n);
    if (!mt)
    {
        return NULL;
    }
    while (fscanf(f, "%d->%d",&mi, &mj) == 2)
    {
        mt[mi-1][mj-1] = 1;
        mt[mj-1][mi-1] = 1;
        std::cout << mi<<"->"<<mj<<std::endl;
    }
    return mt;
}

int read_from_file(FILE *f, struct figure &fig)
{
    std::cout << "readed file: "<<std::endl;
    if (!f)
        return 1;

    free_fig(fig);

    fig.n = count_points(f);
    if (fig.n <= 0)
        return 2;

    fig.mas = create_mas(f,fig.n);
    if (!fig.mas)
    {
       return 3;
    }

    fig.matrix = create_matrix(f,fig.n);
    if (!fig.matrix)
    {
        delete [] fig.mas;
        return 4;
    }

    return 0;
}
