#include"io.h"
#include"process.h"
#include"errors.h"
#include<assert.h>
#include<math.h>

#define EPS 0.000001

int find_pos(double main_x,double *all_x, int all_count)
{
	int pos;
	int i;
	if (main_x > all_x[0])
	{
		for (i = 0; i < all_count && main_x >= all_x[i]; i++);
	}
	else 
	{
		for (i = 0; i < all_count && main_x < all_x[i]; i++);
	}
	pos = i - 1;
	if (pos == -1 || (pos == all_count - 1 && main_x != all_x[all_count-1]))
	{
		//printf("\n!!!\n ЭКСТАРПОЛЯЦИЯ \n!!!\n\n");
		if (pos == -1)
			pos = 0;
	}
	return pos;
}

int find_h(double *h, int n, double *x)
{
	for (int i = 1; i < n; i ++)
	{
		h[i] = x[i] - x[i - 1];
		if (fabs(h[i]) < EPS )
			return 1;
	}
	return 0;
}

void find_A(double *a, int n, double *h)
{
	for (int i = 2; i < n; i++)
	{
		a[i] = h[i-1];
	}
}

void find_B(double *b, int n, double *h)
{
	for (int i = 2; i < n; i++)
	{
		b[i] = -2 * (h[i-1] + h[1]);
	}
}

void find_D(double *d, int n, double *h)
{
	for (int i = 2; i < n; i++)
	{
		d[i] = h[i];
	}
}

void find_F(double *f, int n, double *y, double *h)
{
	for (int i = 2; i < n; i++)
	{
		f[i] = -3 * ((y[i] - y[i-1])/h[i] - (y[i-1] - y[i-2])/h[i-1]);
	}
}

int find_z(double *z, int n, double *a, double *b, double *d)
{
	for (int i = 3; i < n; i++)
	{
		if (fabs(b[i] - a[i]*z[i]) < EPS )
			return 1;
		z[i+1] = d[i]/(b[i] - a[i]*z[i]);
	}
	return 0;
}

void find_nu(double *nu, int n, double *a, double *b, double *f, double *z)
{
	for (int i = 3; i < n; i++)
	{
		nu[i+1] = (a[i] * nu[i] + f[i]) / (b[i] - a[i] * z[i]);
	}
}

void find_u(double *u, int n, double *z, double *nu)
{
	for (int i = n-1; i > 1; i--)
	{
		u[i] = z[i+1]*u[i+1] + nu[i+1];
	}
}

void find_main_a(double *a, int n, double *y)
{
	for(int i = 1; i < n; i++)
	{
		a[i] = y[i-1];
	}
}

void find_main_d(double *d, int n, double *c, double *h)
{
	for(int i = 1; i < n; i++)
	{
		d[i] = (c[i+1] - c[i])/3/h[i];
	}
}

void find_main_b(double *b, int n, double *y, double *h, double *c)
{
	for (int i = 1; i < n; i++)
	{
		b[i] = (y[i] - y[i-1])/h[i] - h[i]*(c[i+1] + 2*c[i])/3;
	}
}

int  process(int n, double main_x, double *x, double *y, double *answ)
{
	double h[n + 1];
	double big_a[n + 2];
	double big_b[n + 2];
	double big_d[n + 2];
	double big_f[n + 2];
	double z[n+2];
	double nu[n+2];
	double c[n+1];
	double a[n+1];
	double b[n+1];
	double d[n+1];
	
	if (find_h(h, n, x) != 0)
		return ERR;
	find_A(big_a, n, h);
	find_B(big_b, n, h);
	find_D(big_d, n, h);
	find_F(big_f, n, y, h);
	
	if (fabs(big_b[2]) < EPS)
		return ERR;
	z[3] = big_d[2]/big_b[2];
	nu[3] = big_f[2]/big_b[2];
	c[1] = 0;
	c[n] = 0;
	if (find_z(z, n, big_a, big_b , big_d) != 0)
		return ERR;
	find_nu(nu, n, big_a, big_b, big_f, z);
	find_u(c, n, z, nu);
	find_main_a(a, n, y);
	find_main_d(d, n, c, h);
	find_main_b(b, n , y, h, c);
	
	int pos = find_pos(main_x, x, n);
	pos++;
	
	printf("%lf %lf %lf %lf", a[pos],b[pos],c[pos],d[pos]);
	*answ = (a[pos] + b[pos]*(main_x - x[pos - 1]) + c[pos]*(main_x - x[pos - 1])*(main_x - x[pos - 1]) + 
	    (main_x - x[pos - 1])*(main_x - x[pos - 1])*(main_x - x[pos - 1])*d[pos]);
	
	
	return OK;
}