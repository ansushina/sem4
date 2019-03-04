#include"io.h"
#include"process.h"
#include"errors.h"

int count_all(FILE *f)
{
	double x, y, z;
	int i = 0;
	while (fscanf(f, "%lf %lf %lf", &x, &y, &z) == 3)
	{
		i++;
		//printf("%lf %lf \n", x, y);
	}
	rewind(f);
	//printf("%d", i);
	return i;
}

int read_tab(char *fname, double **all_x, double **all_y, double **all_z, int *all_count)
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
				double *z = malloc(n * sizeof(double));
				if (z)
				{
				    for (int i = 0; i < n; i++)
			    	{
			    		if (fscanf(f, "%lf %lf %lf", &x[i], &y[i], &z[i]) != 3)
			    			rc = ERR;
			    	}
			    	if (rc == OK)
			    	{
				    	*all_x = x;
				    	*all_y = y;
						*all_z = z;
				    	*all_count = n;
				    }
			     	else
			    	{
			    		free(y);
			    		free(x);
						free(z);
			     	}
				}
				else
				{
					rc = ERR_MEMORY;
				    free(x);
					free(y);
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

int read_input(int *nx, int *ny, double *x, double *y)
{
	printf("Введите Nx (Nx>=0): ");
	if (scanf("%d", nx) != 1 || *nx < 0)
	{
		return ERR_IO;
	}
	printf("Введите Ny (Ny>=0):");
	if (scanf("%d", ny) != 1 || *ny < 0)
	{
		return ERR_IO;
	}
	
	printf("Введите x: ");
	if (scanf("%lf", x) != 1)
	{
		return ERR_IO;
	}
	
	printf("Введите y: ");
	if (scanf("%lf", y) != 1)
	{
		return ERR_IO;
	}

	return OK;
}

int read_all(char *fname, double **all, int *all_count, int *nx, int *ny, double *x, double *y)
{
	int rc = read_tab(fname, &all[0], &all[1], &all[2], all_count);
	if (rc == OK)
	{
		rc = read_input(nx, ny, x, y);
	}
	return rc;
}

void print_tabl(double **all, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%lf %lf %lf\n", all[0][i], all[1][i], all[2][i]);
	}
}