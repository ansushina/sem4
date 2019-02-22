#include"io.h"
#include"process.h"
#include"errors.h"
#include<stdio.h>
#include<math.h>

#define FROM -5.
#define TO 5.1
#define STEP 0.2
#define filename "t.txt"
    double func(double x)
{
	return x*x*x - x*x + x;
}

void tabl()
{
	FILE *file = fopen(filename, "w");
	if (file)
	{
		for(double i = FROM; i <= TO; i += STEP)
		{
			fprintf(file, "%10f %10f\n", i, func(i));
			if ( (TO - FROM)/STEP < 50)
				printf("%10f %10f\n", i, func(i));
		}
		fclose(file);
		//printf("DONE\n");
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
	double *all_x, *all_y;
	int all_count;
	double main_x, answ;
	printf("Программа выполняет интерполяцию функции сплайнами\n");
	
	printf("Отрезок: [%lf ; %lf]\n", FROM, TO);
	tabl();
	
	rc = read_all(filename, &all_x, &all_y, &all_count, &main_x);
	if (rc == OK)
	{
		//printf("Lets go!");
		rc = process(all_count, main_x, all_x, all_y, &answ);
		if (rc == OK)
		{
			printf("\nТочное значение:\n\n y(%lf) = %lf\n\nВычисленное значение:\n\n y = %lf\n\n",
			main_x, func(main_x), answ);
		}
		else 
		{
			printf("Невозможно вычислить ответ.\n\n");
		}
		free(all_x);
		free(all_y);
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
		printf("Недостаточно точек");
	}
	return rc;
}
