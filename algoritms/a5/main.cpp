#include <iostream>
#include "io.h"
#include <math.h>
#include "gauss.h"
#include "interpolation.h"
#include "stdio.h"
using namespace std;

#define P1 3
#define P2 25
#define EPS 0.0001
#define N 40

const double E[4] = {12.13, 20.98, 31.00, 45.00};
const double Z[5] = {0,1,2,3,4};
const double QT[13] = {2000,4000,6000,8000,10000,12000,14000,16000,18000,20000,22000,24000,26000};
const double Q[5][13] = {
    {1,1,1,1.0001, 1.0025, 1.0198, 1.0895, 1.2827, 1.6973, 2.4616, 3.6552, 5.3749, 7.6838},
    {4,4,4.1598, 4.3006, 4.4392, 4.5662, 4.6817, 4.7923, 4.9099,5.0511,5.2354, 5.4841, 5.8181},
    {5.5,5.5,5.5116, 5.9790, 6.4749, 6.9590, 7.4145, 7.8370, 8.2289, 8.5970, 8.9509, 9.3018, 9.6621},
    {11,11,11,11,11,11,11,11,11,11,11,11,11},
    {15,15,15,15,15,15,15,15,15,15,15,15,15}};
void print_array(double *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%15e ", array[i]);
    printf("\n");
}

void print_mtr(double *mtr[7])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
            printf("%15e ", mtr[i][j]);
        printf("\n");
    }
}
double get_q(int i, double t)
{
    double answ;
    int n = 2;
    double *x, *y;
    make_new_mas(n, t, &x, &y, QT, Q[i], 13);
    interpolation(n, t, x, y, &answ);
    free(x);
    free(y);
    return answ;
}

double T(double z, double t0, double tw, int m)
{
    return t0+(tw-t0)*pow(z,m);
}

double F(double integral, double pn, double tn)
{
    return 7242*pn/tn - 2 * integral;
}

double n_1(double p, double t)
{
    return 7242 * p / t;
}



double find_deltae(int i, double t, double g)
{
    double g2 = g*0.5;
    double k1 = 8.61*1e-5 * t;
    return  k1 * log(((1 + Z[i+1]*Z[i+1] * g2) * (1 + g2)) / (1 + Z[i]*Z[i]*g2));
}

double find_k(int i, double t, double g)
{
    double t32 = pow(t, 1.5);
    double k1 = 4.83*1e-3;
    double k2 = 11603.0/t;
    return k1 * (get_q(i+1,t)/get_q(i,t)) * t32* exp(- E[i] + find_deltae(i,t,g)*k2);
}

double find_alpha(double t, double g)
{
    return 0.285 * 1e-11 * pow(g*t,3);
}

double gamma(double g, double v, double x[5], double t)
{
    double s = exp(v)/(1+g*0.5);

    for(int i = 1; i < 5; i++)
    {
        s+=exp(x[i])*Z[i]*Z[i]/(1+Z[i]*Z[i] * g*0.5);
    }
    s *= 5.87 * 1e10 /t/t/t;
    return g*g - s;
}

double find_gamma(double v, double x[5], double t)
{
    double g1 = 0;
    double g2 = 3;
    double g = (g2+g1)/2;

    while(fabs(g2-g1) > EPS)
    {
        g = (g2+g1)/2;
        double f1 = gamma(g,v,x,t);
        double f2 = gamma(g2,v,x,t);
        if (f1 * f2 < 0)
        {
            g1 = g;
        }
        else
        {
            g2 = g;
        }
    }
    return g;
}

void fill_matrix(double *mt[7], double *x, double v)
{
    for(int i = 0; i < 4; i++)
    {
        mt[i][0] = 1;
    }
    int j = 1;
    for (int i = 0; i < 4; i++)
    {
         mt[i][j] = -1;
         mt[i][j + 1] = 1;
         j++;
    }
    mt[4][0] = exp(v);
    for (int i = 1; i < 5; i++)
       mt[4][i + 1] = -Z[i] * exp(x[i]);
    mt[5][0] = -exp(v);
    for (int i = 0; i < 5; i++)
       mt[5][i + 1] = -exp(x[i]);
}

double n_2(double p, double t)
{
    double v = -1;
    double x[5] = {2,-1,-2,-25,-35};
    double alpha = 0;
    double gamma = 0;

    double n[5] = {0};
    for (int i  = 0; i < 5; i++)
    {
        n[i] = exp(x[i]);
    }

    double deltav,deltax1,deltax2,deltax3,deltax4,deltax5;

    double m1[7] = {1,-1,1,0,0,0};
    double m2[7] = {1,0,-1,1,0,0};
    double m3[7] = {1,0,0,-1,1,0};
    double m4[7] = {1,0,0,0,-1,1};
    double m5[7] = {0};
    double m6[7] = {0};
    double *matrix[6];
    matrix[0] = m1;
    matrix[1] = m2;
    matrix[2] = m3;
    matrix[3] = m4;
    matrix[4] = m5;
    matrix[5] = m6;


    double **delta = NULL;
    do
    {
        fill_matrix(matrix,x,v);
        for (int i = 0; i < 4; i++)
        {
            matrix[i][6] = -(v + x[i+1] - x[i] - log(find_k(i,t,gamma)));
        }

        matrix[4][6] = -(exp(v) - Z[1]*n[1] - Z[2]*n[2] - Z[3]*n[3] - Z[4]*n[4]);
        matrix[5][6] = -(7242*p/t + alpha - exp(v) - n[0] - n[1] - n[2] - n[3] - n[4]);

        int rc = do_gauss(matrix, 6, 7, &delta);
        if (rc) break;
        v = v + delta[0][0];
        deltav = delta[0][0];
        deltax1 = delta[1][0];
        deltax2 = delta[2][0];
        deltax3 = delta[3][0];
        deltax4 = delta[4][0];
        deltax5 = delta[5][0];

        for (int i = 1; i <= 5; i++)
        {
            x[i-1] = x[i-1] + delta[i][0];
        }

        for (int i  = 0; i < 5; i++)
        {
            n[i] = exp(x[i]);
        }

        gamma = find_gamma(v,x,t);
        alpha = find_alpha(t,gamma);
        free_matrix(delta,6);

        printf("v-x:\n");
        printf("%15e ", v);
        print_array(x, 5);
        printf("delta:\n");
        printf("%15e %15e %15e %15e %15e %15e\n", deltav, deltax1, deltax2, deltax3, deltax4,deltax5);
        printf("gamma = %lf\n", gamma);
        printf("matrix:\n");
        print_mtr(matrix);

    }
    while (fabs(deltav/v) > 0.0001 &&
           fabs(deltax1/x[0]) > 0.0001 &&
           fabs(deltax2/x[1]) > 0.0001 &&
           fabs(deltax3/x[2]) > 0.0001 &&
           fabs(deltax4/x[3]) > 0.0001 &&
           fabs(deltax5/x[4]) > 0.0001);

    for (int i  = 0; i < 5; i++)
    {
        n[i] = exp(x[i]);
    }
    printf("ne n1-5:\n");
    printf("%15e ", exp(v));
    print_array(n, 5);

    double nt = 0;
    for (int i  = 0; i < 5; i++)
    {
        nt += n[i];
    }
    return nt;
}

double Simpson_method(double *nt)
{
    double s = nt[0];
    for (int i = 1; i < N; i++)
    {
        if (i % 2 == 0)
            s += 2*nt[i];
        else
            s += 4*nt[i];
    }
    s += nt[N];
    s *= 1/(double)N/3.0;
    return s;
}

double find_f(double p, double t0, double tw, int m, double pn, double tn)
{
    double nt[N+1] = {0};
    double h = 1/(double)N;
    double z, t;
    for (int i = 0; i < N+1; i++)
    {
        z = i * h;
        t = T(z, t0, tw, m);
        nt[i] = n_2(p,t);
    }
    for (int i = 0; i < N+1; i++)
    {
        z = i*h;
        nt[i] *= z;
    }
    double integral = Simpson_method(nt);
    double f = F(integral,pn,tn);
    return f;
}

int process(double t0, double tw, int m, double pn, double tn)
{
    double p1 = P1;
    double p2 = P2;
    double p = (p2+p1)/2;
    double f1 = 1,f2;
    while (fabs(p2-p1) > EPS )
    {
        p = (p2+p1)/2;
        f1 = find_f(p,t0,tw,m,pn,tn);
        f2 = find_f(p2,t0,tw,m,pn,tn);
        printf("f(%e) = %e\n", p, f1);
        if (f1 * f2 < 0)
        {
            p1 = p;
        }
        else
        {
            p2 = p;
        }
    }

    cout <<"Answer is " << p << endl;
    return 0;
}

int main()
{
    setbuf(stdout, NULL);

    cout << "Hello World!" << endl;
    double t0,tw,pn,tn;
    int m;
    int rc = input_all(t0,tw,m,pn,tn);
    if (rc)
    {
        cout << "Input error" << endl;
        return 0;
    }
    rc = process(t0,tw,m,pn,tn);

    return 0;
}
