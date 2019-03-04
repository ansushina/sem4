#include"io.h"
#include"process.h"
#include"errors.h"
#include<stdio.h>
#include<math.h>

#define FROM -0
#define TO 1.6
#define STEP 0.4
#define filename "t.txt"

double func(double x, double y)
{
	//return cos(x) - x;
	return x*x + y*y;
}

void tabl1()
{
	FILE *file = fopen(filename, "w");
	if (file)
	{
		printf("Входная таблица:\n\n");
		for(double i = FROM; i <= TO; i += STEP)
		{
			for(double j = FROM; j <= TO; j += STEP)
			{
			    fprintf(file, "%10f %10f %10f\n", i, j, func(i,j));
			    if ((-FROM + TO)/STEP < 40)
			        printf("%10f %10f %10f\n", i, j, func(i,j));
			}
		}
		fclose(file);
		printf("\n");
	}
	else 
	{
		printf("Can't open file!\n");
	}
}

int main(int argc, char *argv[])
{
	setbuf(stdout, NULL);
	
	int rc = OK;
	double *all[3];
	int all_count, nx, ny;
	double main_x, main_y;
	
	struct point **tabl;
	printf("Программа выполняет интерполяцию функции поленоном Ньютона\n");
	tabl1();
	
	rc = read_all(filename, all, &all_count, &nx, &ny, &main_x, &main_y);
	if (rc == OK)
	{
		//printf("Lets go!");
		//double *x, *y;
		int cx, cy;
		
                //print_tabl(all,all_count);
		
		//int make_tabl(struct point ***tabl, double **all, int count_all, int *cx, int *cy)
		rc = make_tabl(&tabl, all, all_count, &cx, &cy);
		if (rc == OK)
		{
                        struct point **new;
			rc = make_new_tabl(nx, ny, main_x, main_y, &new, tabl, cx, cy);
			if (rc == OK)
			{
				printf("ok");
                                double answer;
                                rc = process(new, main_x, main_y, nx, ny, &answer);
                                if (!rc)
                                {
                                    printf("\n %lf \n", answer);
                                }
                                else
                                {
                                    printf("error");
                                }
			}
			else 
			{
				printf("MEMORY ERROR\n");
			}
                        free_matrix(tabl, cx);
			
		}
		else if (rc == ERR_MEMORY)
		{
			printf("MEMORY ERROR\n");
		}
		else if (rc == ERR)
		{
			printf("Недостаточно точек для подсчета\n");
		}
		else
		{
			printf("something goes wrong 2\n");
		}
		
		free(all[0]);
		free(all[1]);
		free(all[2]);
	}
	else if (rc == ERR_FILE)
	{
		printf("Can_t open file!\n");
	}
	else if (rc == ERR_IO)
	{
		printf("INPUT ERROR\n");
	}
	else if (rc == ERR_MEMORY)
	{
		printf("MEMORY ERROR\n");
	}
	else 
	{
		printf("somethig goes wrong");
	}
	return rc;
}
