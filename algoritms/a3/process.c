#include"io.h"
#include"process.h"
#include"errors.h"



struct point **allocate_matrix(int nx, int ny)
{
	struct point **p = malloc((nx+1) * sizeof(struct point *));
	if (!p)
		return NULL;
	for (int i = 0; i < nx + 1; i++)
	{
		p[i] = malloc((ny+1) * sizeof(struct point));
		if (!(p[i]))
			free_matrix(p,i);
	}
	return p;
}

int make_tabl(struct point ***tabl, double **all, int count_all, int *cx, int *cy)
{
	int countx = 0;
	int county = 0;

	while (all[0][countx] == all[0][0])
	{
		countx++;
	}
	
	county = count_all / countx;
	
	struct point **t = allocate_matrix(countx-1, county-1);
	if (!t)
		return ERR_MEMORY;
	
	for (int i = 0; i < countx; i++)
	{
		for (int j = 0; j < county; j++)
		{
			t[i][j].x = all[0][i*countx];
            t[i][j].y = all[1][j];
			t[i][j].z = all[2][i*countx + j];
			printf("%lf %lf %lf   ", t[i][j].x, t[i][j].y, t[i][j].z);
		}
		printf("\n");
	}
	*tabl = t;
	*cx = countx;
	*cy = county;
	return OK;
}

void copy_tabl(struct point **tabl, int begx, int endx, int begy, int endy, struct point **new)
{
	for (int i = begx; i < endx; i++)
	{
		for (int j = begy; j < endy; j++)
		{
			new[i][j].x = tabl[i][j].x;
			new[i][j].y = tabl[i][j].y;
			new[i][j].z = tabl[i][j].z;
		}
	}
}

void free_matrix(struct point **p, int nx)
{
	if (!p)
		return;
	for (int i = 0; i < nx; i++)
	{
		free(p[i]);
	}
	free(p);
}

// поиск позиции
int find_pos_x(double mx, struct point **all, int cx)
{
	int pos;
	int i;
	if (mx > all[0][0].x) //значения в таблице по возрастанию
	{
		for (i = 0; i < cx && mx >= all[i][0].x; i++);
	}
	else // случай убывания
	{
		for (i = 0; i < cx && mx < all[i][0].x; i++);
	}
	pos = i - 1;
	if (pos == -1 || (pos == cx - 1 && mx != all[cx-1][0].x))
	{
		printf("\n!!!\n ЭКСТАРПОЛЯЦИЯ \n!!!\n\n");
		if (pos == -1)
			pos = 0;
	}
	return pos;
}
int find_pos_y(double mx, struct point **all, int cx)
{
	int pos;
	int i;
	if (mx > all[0][0].y) //значения в таблице по возрастанию
	{
		for (i = 0; i < cx && mx >= all[0][i].y; i++);
	}
	else // случай убывания
	{
		for (i = 0; i < cx && mx < all[0][i].y; i++);
	}
	pos = i - 1;
	if (pos == -1 || (pos == cx - 1 && mx != all[0][cx-1].y))
	{
		printf("\n!!!\n ЭКСТАРПОЛЯЦИЯ \n!!!\n\n");
		if (pos == -1)
			pos = 0;
	}
	return pos;
}

// найдем начало и конец массива для копирования
int find_beg_end(int pos, int *b, int *e, int cx, int n)
{
	int j = 1;
	int p = 1;
	int begin = pos, end = pos;
	if (cx < n + 1)
	{
		return ERR;
	}
	
	while (j != n + 1) // пока не наберем n+1 
	{
		if (pos + p < cx ) // берем строку снизу
		{
			end++;
			j++;
		}
		if (pos - p >= 0 && j != n + 1) // берем строку сверху
		{
			begin--;
			j++;
		}
		p++;
		if (pos - p < 0 && pos + p > cx) // если недостаточно точек, выходим из цикла
			break;
		//printf(" %d %d \n", begin, end);
	}
	if (j != n + 1)// вернем ошибку, если недостаточно точек
		return ERR;
	*b = begin;
	*e = end;
	return OK;
}

int make_new_tabl(int nx, int ny, double mx, double my, struct point ***new, struct point **all, int cx, int cy)
{
	int posx = find_pos_x(mx, all, cx);
	int posy = find_pos_y(my, all, cy);
	
	struct point **n = allocate_matrix(nx, ny);
	if (!n)
		return ERR_MEMORY;
	
	int bx,ex,by,ey, rc;
	rc = find_beg_end(posx, &bx, &ex, cx, nx);
	if (rc != OK)
	{
		free_matrix(n, nx);
		return rc;
	}
	rc = find_beg_end(posy, &by, &ey, cy, ny);
	if (rc != OK)
	{
		free_matrix(n, nx);
		return rc;
	}
	
	copy_tabl(all, bx, ex, by, ey, n);
	
	*new = n;
	
	return OK;
}

/*int make_new_mas(int n, double main_x, double **x, double **y, double *all_x, 
    double *all_y, int all_count)
{
	// найдем позицию
	int pos = find_pos(main_x, all_x, all_count);
	
	double *nx = malloc((n + 1) * sizeof(double));
	if (!nx)
		return ERR_MEMORY;
	double *ny = malloc((n + 1) * sizeof(double));
	if (!ny)
	{
		free(nx);
		return ERR_MEMORY;
	}
	
	int begin, end, rc;
	//printf("\nall count %d\n", all_count);
	// найдем, какую часть таблицы нужно взять
	rc = find_beg_end(pos, &begin, &end, all_count, n);
	if (rc != OK)
	{
		free(nx);
		free(ny);
		return rc;
	}
	printf("Отрезок: [%lf; %lf]\n\n", all_x[begin], all_x[end]);
	// сформируем новую таблицу 
	copy_mas(nx, ny, all_x, all_y, begin, end);
	
	*x = nx;
	*y = ny;
	
	return OK;
}*/

// интерполяция
/*int process(int n, double x, double *new_x, double *new_y, double *answ)
{
	double raz[n + 1];// массив для хранения разностей
    double a[n + 1];// массив для промежуточных вычислений
	
	for (int i = 0; i < n + 1; i++)
	{
		a[i] = new_y[i];
	}

	int count = 0; // индекс первого икса в разности
	int pos = 0; // позиция в массиве/индекс 
	int j = 0; // номер интерации
	int flag = 1; 
	
	for (int i = 0; i < n && flag; i++)
	{
		pos = 0;
		for (count = 0; count < n - i; count++)
		{
			if (new_x[count + i + 1] - new_x[count] == 0) // проверка деления на ноль
			{
				flag = 0;
				return ERR;
			}
			a[count] = (a[pos + 1] - a[pos]) / (new_x[count + i + 1] - new_x[count]);
			pos++;
			printf("%lf ", a[count]);
		}
		raz[j] = a[0];
		printf("\n");
		//printf("\n%lf\n", raz[j]);
		j++;
	}
	
	double answer = new_y[0];
	double b; // промежуточное произведение
	for(int i = 0; i < n; i++)
	{
		b = raz[i];
		for(int j = 0; j < i + 1; j++)
		{
			b *= (x - new_x[j]);
		}
		answer += b;
	}
	//printf("answer: %lf \n", answer);
	*answ = answer;
	return OK;
}*/