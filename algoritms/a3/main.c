#include"io.h"
#include"process.h"
#include"errors.h"
#include<stdio.h>
#include<math.h>

#define FROM -0
#define TO 1.6
#define STEP 0.4
#define filename "t.txt"

double func(double x)
{
	return cos(x) - x;
	return x*x;
}

void tabl()
{
	FILE *file = fopen(filename, "w");
	if (file)
	{
		printf("Входная таблица:\n\n");
		for(double i = FROM; i <= TO; i += STEP)
		{
			fprintf(file, "%10f %10f\n", i, func(i));
			if ((-FROM + TO)/STEP < 40)
			    printf("%10f %10f\n", i, func(i));
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
	printf("Программа выполняет интерполяцию функции поленоном Ньютона\n");
	tabl();
	
	rc = read_all(filename, all, &all_count, &nx, &ny, &main_x, &main_y);
	if (rc == OK)
	{
		//printf("Lets go!");
		double *x, *y;
		/*rc = make_new_mas(n, main_x, &x, &y, all_x, all_y, all_count);
		if (rc == OK)
		{
			double answer;
			rc = process(n, main_x, x, y, &answer);
			if (rc == OK)
			{
			    printf("Точное значение:\n y(%lf) = %lf\n\nВычисленное значение:\n y = %lf\n\n",
			    main_x, func(main_x), answer);
			}
			else
			{
				printf("Невозможно вычислить.\n");
			}
			free(x);
			free(y);
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
		// поиск корня
		printf("Найдем корень функции:\n");
		rc = make_new_mas(n, 0, &x, &y, all_y, all_x, all_count);
		if (rc == OK)
		{
			double answer;
			rc = process(n, 0, x, y, &answer);
			if (rc == OK)
			{
			    printf(" Корень функции = %lf", answer);
				
				printf("cos(%lf) = %lf\n x = %lf", answer, cos(answer), answer);
			}
			else 
			{
				printf("Невозможно вычислить корень\n");
			}
			free(x);
			free(y);
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
		free(all_x);
		free(all_y);*/
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
