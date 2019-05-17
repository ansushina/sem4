#include <stdio.h>
#include <stdlib.h>

#define START 2
#define END 8
#define STEP 1

static double a0 = 1;
static double a1 = 2;
static double a2 = 3;

double F(double x)
{
    return (a0 * x) / (a1 + a2 * x);
}

double F_pr(double x)
{
    return (a0 * a1) / pow((a1 + a2 * x), 2);
}

double ksi(double x)
{
    return 1/x;
}

double ksi_x(double x)
{
    return -1/x/x;
}

double eta_y(double y)
{
    return -1/y/y;
}

double eta_ksi_diff()
{
    return a1/a0;
}

double * real(double *x, double *y, int n)
{
    double *real_mas = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        real_mas[i] = F_pr(x[i]);
    }
    return real_mas;
}

double *right_sub(double *x, double *y, int n, int h)
{
    double *mas = (double *)calloc(n, sizeof(double));
    for (int i = 0; i < n-1; i++)
    {
        mas[i] = (y[i+1] - y[i])/h;
    }
    return mas;
}
double *left_sub(double *x, double *y, int n, int h)
{
    double *mas = (double *)calloc(n, sizeof(double));
    for (int i = 1; i < n; i++)
    {
        mas[i] = (y[i] - y[i-1])/h;
    }
    return mas;
}
double *central_sub(double *x, double *y, int n, int h)
{
    double *mas = (double *)calloc(n, sizeof(double));
    for (int i = 1; i < n-1; i++)
    {
        mas[i] = (y[i+1] - y[i-1])/h/2;
    }
    return mas;
}

double *runge(double *x, double *y, int n, int h)
{
    double *mas2 = left_sub(x,y,n,h);
    double zn = 1;
    double *mas = (double *)calloc(n, sizeof(double));
    for (int i = 2; i < n; i++)
    {
        mas[i] = (y[i] - y[i-2])/h/2;
    }
    for (int i = 0; i < 2; i++)
    {
        //mas[i] = (y[i+2] - y[i])/h/2;
    }

    double *res = (double *)calloc(n, sizeof(double));

    for (int i = 2; i < n; i++)
    {
        res[i] = mas2[i] + (mas2[i] - mas[i])/zn;
    }
    free(mas);
    free(mas2);
    return res;
}
double *align(double *x, double *y, int n, int h)
{
    double *mas = (double *)calloc(n, sizeof(double));
    double tmp[n];
    for (int i = 1; i < n; i++)
    {
        tmp[i] = ksi(x[i]);
    }
    double *newtmp = left_sub(x,tmp,n,h);
    double ksi_derivate = newtmp[0];

    for (int i = 0; i < n; i++ )
    {
        if (x[i] == 0)
            mas[i] = 0;
        else
            mas[i] = (ksi_x(x[i])/eta_y(y[i]))*eta_ksi_diff();
    }
    free(newtmp);
    return mas;
}

double *bounds(double *x, double *y, int n, int h)
{
    double *mas = (double *)calloc(n, sizeof(double));
    mas[0] = (-3 *y[0] + 4*y[1] - y[2])/2/h;
    mas[n-1] = (y[n-3] - 4*y[n-2] + 3*y[n-1])/2/h;
    return mas;
}
void print_line(const char *str, double *mas, int n)
{
    printf("%15s",str);
    for (int i = 0; i < n; i++)
    {
        printf("%10f", mas[i]);

    }
    printf("\n");
    free(mas);
}
int main()
{
    printf("Hello World!\n");
    //20-10-10-10-10
    printf("%15s","x:");
    int n = (END-START)/STEP;
    int h = 1;
    double x[n];
    double y[n];
    int j = 0;
    for (double i = START; i < END; i+=STEP)
    {
        x[j] = i;
        j++;
        printf("%10f", i);
    }
    printf("\n");
    printf("%15s","y:");
    j = 0;
    for (double i = START; i < END; i+=STEP)
    {
        y[j] = F(i);
        j++;
        printf("%10f", F(i));

    }
    printf("\n");
    print_line("real:", real(x,y,n),n);
    printf("\n");
    print_line("right sub:", right_sub(x,y,n,h),n);
    print_line("left sub:", left_sub(x,y,n,h),n);
    print_line("central sub:", central_sub(x,y,n,h),n);
    print_line("bounds:", bounds(x,y,n,h),n);
    print_line("runge:", runge(x,y,n,h),n);
    print_line("align:", align(x,y,n,h),n);





    return 0;
}

