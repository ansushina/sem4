#include"io.h"
#include"process.h"
#include"errors.h"

int count_all(FILE *f)
{
	double x, y;
	int i = 0;
	while (fscanf(f, "%lf %lf", &x, &y) == 2)
	{
		i++;
		//printf("%lf %lf \n", x, y);
	}
	rewind(f);
	//printf("%d", i);
	return i;
}

int read_tab(char *fname, double **all_x, double **all_y, int *all_count)
{
	FILE *f = fopen(fname, "r");
	int rc = OK;
	if (f)
	{
		int n = count_all(f);
		//printf("%d", n);
	    double *x = malloc(n * sizeof(double));
		if (x)
		{
		    double *y = malloc(n * sizeof(double));
			if (y)
			{
				for (int i = 0; i < n; i++)
				{
					if (fscanf(f, "%lf %lf", &x[i], &y[i]) != 2)
						rc = ERR;
				}
				if (rc == OK)
				{
					*all_x = x;
					*all_y = y;
					*all_count = n;
				}
				else
				{
					free(y);
					free(x);
				}
			}
			else
			{
				rc = ERR_MEMORY;
				free(x);
			}
		}
		else 
		{
			rc = ERR_MEMORY;
		}
		fclose(f);
	}
	else
		rc = ERR_FILE;
	return rc;
}

int read_input(int *n, double *x)
{
	printf("Введите N (N>=0): ");
	if (scanf("%d", n) == 1 && *n >= 0)
	{
		printf("Введите x: ");
		if (scanf("%lf", x) != 1)
		{
			return ERR_IO;
		}
	}
	else
	{
		return ERR_IO;
	}
	return OK;
}

int read_all(char *fname, double **all_x, double **all_y, int *all_count, int *n, double *x)
{
	int rc = read_tab(fname, all_x, all_y, all_count);
	if (rc == OK)
	{
		rc = read_input(n, x);
	}
	return rc;
}