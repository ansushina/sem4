#include<stdio.h>
#include<math.h>

#define FROM -30
#define TO 30
#define STEP 2

double f(double x)
{
	return x*x;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("tabl.exe filename!\n");
		return 1;
	}
	
	FILE *file = fopen(argv[1], "w");
	int rc = 0;
	if (file)
	{
		for(double i = FROM; i <= TO; i += STEP)
		{
			fprintf(file, "%10f %10f\n", i, f(i));
		}
		fclose(file);
		printf("DONE\n");
	}
	else 
	{
		printf("Can't open file!\n");
		rc = 1;
	}
	return rc;
}