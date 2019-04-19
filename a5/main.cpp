#include <iostream>
#include "io.h"
#include <math.h>
#include "gauss.h"
#include "interpolation.h"
using namespace std;

#define P1 3
#define P2 25
#define EPS 0.01
#define N 40

const double QT[] = {2000,4000,6000,8000,10000,12000,14000,16000,18000,20000,22000,24000,26000};
const double Q1[] = {1,1,1,1.0001, 1.0025, 1.0198, 1.0895, 1.2827, 1.6973, 2.4616, 3.6552, 5.3749, 7.6838};
const double Q2[] = {4,4,4.1598, 4.3006, 4.4392, 4.5662, 4.6817, 4.7923, 4.9099,5.0511, 5.2354, 5.4841, 5.8181};
const double Q3[] = {5.5,5.5,5.5116, 5.9790, 6.4749, 6.9590, 7.4145, 7.8370, 8.2289, 8.5970, 8.9509, 9.3018, 9.6621};
const double Q4[] = {11,11,11,11,11,11,11,11,11,11,11,11,11};
const double Q5[] = {15,15,15,15,15,15,15,15,15,15,15,15,15};

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

const double Z[5] = {0,1,2,3,4};


double n_2(double p, double t)
{
    double x[5] = {2,-1,10,-25,-35};
    double v = -1;
    double deltav, deltax[5];

    double m1[7] = {1,-1,1};
    double m2[7] = {1, 0,-1,1};
    double m3[7] = {1,0,0,-1,1};
    double m4[7] = {1,0,0,0,-1,1};
    double m5[7],m6[7];
    double *matrix[6];
    matrix[0] = m1;
    matrix[1] = m2;
    matrix[2] = m3;
    matrix[3] = m4;
    matrix[3] = m5;
    matrix[4] = m6;

    double alpha = 0;
    double gamma = 0;
    double deltaE, K[4], Q;
    while (fabs(deltav/v) < 0.0001)
    {
        matrix[4][0] = exp(v);
        matrix[5][0] = exp(v);
        for (int i = 0; i < 5; i++)
        {
            matrix[4][i+1]= Z[i]*exp(x[i]);
            matrix[5][i+1] = exp(x[i]);
        }
        matrix[0][6] = -(v + x[1] + x[0] - log(K[0]));
        matrix[1][6] = -(v + x[2] + x[1] - log(K[1]));
        matrix[2][6] = -(v + x[3] + x[2] - log(K[2]));
        matrix[3][6] = -(v + x[4] + x[3] - log(K[3]));
        matrix[4][6] = -(exp(v) - Z[1]*exp(x[1]) - Z[2]*exp(x[2]) - Z[3]*exp(x[3]) - Z[4]*exp(x[4]));
        matrix[5][6] = -(7242*p/t +alpha - exp(v) - exp(x[0]) - exp(x[1]) - exp(x[2]) - exp(x[3])-exp(x[4]));
        double **b = NULL;
        int rc =  do_gauss(matrix,6,7,&b);


    }
    double n[5] = {0};
    for (int i  =0; i < 5; i++)
    {
        n[i] = exp(x[i]);
    }

    double nt = 0;
    for (int i  = 0; i < 5; i++)
    {
        nt += n[i];
    }
}

double Simpson_method(double *nt)
{
    double s = 0;
    double h = 1/(double) 40;
    double z = 0;
    for (int i = 1; i < N-1; i++)
    {
        z = h*i;
        if (i % 2 == 0)
            s += 2*nt[i]*z;
        else
            s += 4*nt[i]*z;
    }
    s += nt[N-1]*h*39;
    s *= 1/(double)N/3.0;
    return s;
}

double find_f(double p, double t0, double tw, int m, double pn, double tn)
{
    double nt[N] = {0};
    double h = 1/(double)N;
    double z, t;
    for (int i = 0; i < 40; i++)
    {
        z = i * h;
        t = T(z, t0, tw, m);
        cout << z<<" "<<t<<endl;
        nt[i] = n_1(p,t);
        cout << nt[i]<<" ";
    }
    for (int i = 0; i <  N; i++)
    {
        //nt[i] *= pow(10, -18);
    }
    double integral = Simpson_method(nt);
    double f = F(integral,pn,tn);
    return f;
}

int process(double t0, double tw, int m, double pn, double tn)
{
    double p1 = P1;
    double p2 = P2;

    while (p2-p1 > EPS)
    {
        double p = (p2+p1)/2;
        double f1 = find_f(p,t0,tw,m,pn,tn);
        double f2 = find_f(p2,t0,tw,m,pn,tn);
        if (f1 * f2 < 0)
        {
            p1 = p;
        }
        else
        {
            p2 = p;
        }
    }
    cout << p2 << endl;

}

int main()
{
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
