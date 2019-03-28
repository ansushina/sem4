#include "io.h"

#include <iostream>

void free_matrix(int **mat, int n)
{
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

int **allocate_matrix(size_t n)
{
    if (!n)
        return nullptr;
    int **new_matrix =(int **)calloc(n, sizeof(int *));
    if (!new_matrix)
        return nullptr;
    for (size_t i = 0; i < n; i++)
    {
        new_matrix[i] = (int *)calloc(n, sizeof(int));
        if (!new_matrix[i])
        {
            free_matrix(new_matrix, i);
            return nullptr;
        }
    }
    return new_matrix;
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
    struct point p;
    struct point *buf = (struct point *)malloc(n* sizeof(struct point *));
    if (!buf)
        return NULL;
    for (size_t i = 0; i < n; i++)
    {
        if (fscanf(f, "%d %lf %lf %lf",&p.n, &p.x, &p.y, &p.z) != 4)
        {
            free(buf);
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

}

int read_from_file(FILE *f, struct figure &fig)
{
    std::cout << "in_read"<<std::endl;
    if (!f)
        return 1;

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
        free(fig.mas);
        return 4;
    }

    for (size_t i = 0; i < fig.n; i++)
    {
        std::cout << fig.mas[i].x << fig.mas[i].y <<  fig.mas[i].z << fig.mas[i].n <<std::endl;
    }
    return 0;
}
