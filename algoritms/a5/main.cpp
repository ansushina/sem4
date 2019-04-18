#include <iostream>
#include "io.h"
#include <math.h>
#include "gauss.h"
using namespace std;

#define P1 3
#define P2 25
#define EPS 0.01
#define N 40

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
    double matrix[6][7] = {{1,-1,1},{1,0,-1,1},{1,0,0,-1,1},
                           {1,0,0,0,-1,1}};
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
        matrix[0][6] = -(v+x[1]+x[0] - log(K[0]));
        matrix[1][6] = -(v+x[2]+x[1] - log(K[1]));
        matrix[2][6] = -(v+x[3]+x[2] - log(K[2]));
        matrix[3][6] = -(v+x[4]+x[3] - log(K[3]));
        matrix[4][6] = -(exp(v)
                -Z[1]*exp(x[1])
                -Z[2]*exp(x[2])
                -Z[3]*exp(x[3])
                -Z[4]*exp(x[4]));
        matrix[5][6] = -(7242*p/t +alpha - exp(v)
                         -exp(x[0])-exp(x[1])-exp(x[2])
                -exp(x[3])-exp(x[4]));
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

int process(double t0, double tw, int m, double pn, double tn)
{
    double p1 = P1;
    double p2 = P2;

    while (p2-p1 > EPS)
    {
        double p = (p2+p1)/2;
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
            nt[i] *= pow(10, -18);
        }
        double integral = Simpson_method(nt);
        double f = F(integral,pn,tn);
        if (f > 0)
        {
            p2 = p;
        }
        else
        {
            p1 = p;
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
