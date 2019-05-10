#include <iostream>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

#define START 1
#define END 10
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
        real_mas[i] = F_pr();
    }
    return real_mas;
}

void print_line(const char *str, double *mas, int n)
{
    printf("%15s",str);
    for (int i = 0; i < n; i++)
    {
        printf("%10f", mas[0]);

    }
    printf("\n");
}
int main()
{
    cout << "Hello World!" << endl;
    //20-10-10-10-10
    printf("%15s","x:");
    int n = (END-START)/STEP;
    double x[n];
    double y[n];
    int j = 0;
    for (double i = START; i < END; i+=STEP)
    {
        x[j++] = i;
        printf("%10f ", i);
    }
    printf("\n");
    printf("%15s","y:");
    j = 0;
    for (double i = START; i < END; i+=STEP)
    {
        y[j++] = F(i);
        printf("%10f", F(i));

    }
    printf("\n");
    print_line("real:", real(x,y,n),n);




    return 0;
}
