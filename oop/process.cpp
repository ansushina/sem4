#include "process.h"
#include "io.h"

void perenos(struct point &a, double dx, double dy, double dz)
{
    a.x += dx;
    a.y += dy;
    a.z += dz;
}


void mastab(struct point &a, double xm, double ym, double zm, double k)
{
    a.x = xm + k*(a.x - xm);
    a.y = ym + k*(a.y - ym);
    a.z = zm + k*(a.z - zm);
}

/*void povorot(struct point &a, double xc, double yc, double alpha)
{
    double new_x = xc + (a.x - xc) * cos(alpha * PI / 180) + (a.y - yc) * sin(alpha * PI / 180);
    a.y = yc - (a.x - xc) * sin(alpha * PI / 180) + (a.y - yc) * cos(alpha * PI / 180);
    a.x = new_x;
}*/

void perenos_all(struct figure &fig, double dx, double dy, double dz)
{
    for (size_t i = 0; i < fig.n; i++)
    {
        perenos(fig.mas[i],dx,dy,dz);
    }
}

void mastab_all(struct figure &fig, double k)
{
    for (size_t i = 0; i < fig.n; i++)
    {
        mastab(fig.mas[i],0,0,0,k);
    }
}

int do_process(int number, struct figure &fig)
{
    if (number ==  PERENOS_NUMBER)
    {

    }
    else if (number == POVOROT_NUMBER)
    {

    }
    else if (number == MASTAB_NUMBER)
    {

    }
    else
        return 1;
    return 0;
}
\
int download_model(char *filename, struct figure &fig)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return 1;
    int rc = read_from_file(f,fig);
    fclose(f);
    return rc;
}
