#include "io.h"



void free_matrix(int **mat, int n)
{
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

int **allocate_matrix(int n)
{
    if (!n)
        return NULL;
    int **new_matrix =(int *)calloc(n,sizeof(int *));
    if (!new_matrix)
        return NULL;
    for (int i = 0; i < n; i++)
    {
        new_matrix[i] = (int *)calloc(n,sizeof(int));
        if (!new_matrix[i])
        {
            free_matrix(new_matrix, i);
            return NULL;
        }
    }
    return new_matrix;
}


int read_from_file(FILE *f, struct figure &fig)
{
    if (!f || !fig)
        return 1;
    struct point p;
    int n = 0;
    while (fscanf("%d %lf %lf %lf",&p.n, &p.x, &p.y, &p.z) == 3)
    {
        n++;
    }
    rewind(f);
    fig.n = n;
    struct point *buf = (struct point *)calloc(n, sizeof(struct point *));
    if (!buf)
        return 1;
    for (int i = 0; i < n; i++)
    {
        if (fscanf("%d %lf %lf %lf",&p.n, &p.x, &p.y, &p.z) != 3)
        {
            free(buf);
            return 1;
        }
        buf[i].x = p.x;
        buf[i].y = p.y;
        buf[i].z = p.z;
        buf[i].n = p.n;
    }
    fig.mas = buf;
    int mi,mj;
    int **mt = allocate_matrix(n);
    if (!mt)
    {
        free(buf);
        return NULL;
    }
    while (fscanf("%d->%d",&mi, &mj) == 2)
    {
        mt[mi][mj] = 1;
        mt[mj][mi] = 1;
    }
    fig.matrix = mt;
    return 0;
}
