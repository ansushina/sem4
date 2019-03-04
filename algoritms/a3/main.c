#include"io.h"
#include"process.h"
#include"errors.h"
#include<stdio.h>
#include<math.h>

#define FROM -5.
#define TO 5.1
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
		//printf("Входная таблица:\n\n");
		for(double i = FROM; i <= TO; i += STEP)
		{
			for(double j = FROM; j <= TO; j += STEP)
			{
			    fprintf(file, "%10f %10f %10f\n", i, j, func(i,j));
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
	printf("Программа выполняет множественную интерполяцию функции поленоном Ньютона\n");
	tabl1();
	printf("[%lf;%lf]\nstep: %lf\n\n", FROM , TO, STEP);
	rc = read_all(filename, all, &all_count, &nx, &ny, &main_x, &main_y);
	if (rc == OK)
	{
		int cx, cy;

		rc = make_tabl(&tabl, all, all_count, &cx, &cy);
		if (rc == OK)
		{
            struct point **new;
			rc = make_new_tabl(nx, ny, main_x, main_y, &new, tabl, cx, cy);
			if (rc == OK)
			{
				//printf("ok");
                double answer;
                rc = process(new, main_x, main_y, nx, ny, &answer);
                if (!rc)
                {
                    printf("\n Real : f(%lf, %lf) = %lf", main_x, main_y, func(main_x, main_y));
                    printf("\n Answer: %lf \n", answer);
                }
                else
                {
                    printf("error");
                }
                free_matrix(new, nx+1);
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
