#include <stdio.h>
#include <stdlib.h>

#define START 2
#define END 8
#define STEP 1

double F(double x)
{
    return 5 * x + 1/x/x;
}

double F_pr(double x)
{
    return 5 - 2/x/x/x;
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
    double *mas = (double *)calloc(n, sizeof(double));
    for (int i = 1; i < n-1; i++)
    {
        mas[i] = (y[i+1] - y[i-1])/h/2;
    }
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
    print_line("right sub:", right_sub(x,y,n,h),n);
    print_line("left sub:", left_sub(x,y,n,h),n);
    print_line("central sub:", central_sub(x,y,n,h),n);
    print_line("bounds:", bounds(x,y,n,h),n);




    return 0;
}

