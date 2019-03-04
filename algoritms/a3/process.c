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
                        new[i - begx][j-begy].x = tabl[i][j].x;
                        new[i - begx][j-begy].y = tabl[i][j].y;
                        new[i - begx][j-begy].z = tabl[i][j].z;
                        printf("%lf %lf %lf   ", new[i - begx][j-begy].x , new[i - begx][j-begy].y, new[i - begx][j-begy].z);
		}
                printf("\n");
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
    printf("FInd pos x\n");
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
        printf("%d\n", pos);
	return pos;
}

int find_pos_y(double mx, struct point **all, int cx)
{
    printf("FInd pos y\n");
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
        printf("%d\n", pos);
	return pos;
}

// найдем начало и конец массива для копирования
int find_beg_end(int pos, int *b, int *e, int cx, int n)
{
    printf("find beg end ");
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
        printf("%d %d\n", begin, end);
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
	
        copy_tabl(all, bx, ex+1, by, ey+1, n);
	
	*new = n;
	
	return OK;
}

int process(struct point **tabl, double mx, double my, int nx, int ny, double *a)
{
   double new_y[nx+1];
   double y[ny+1];
   double z[ny+1];
   double answ;
   int rc = OK;

    for (int i = 0; i < nx+1; i++)
    {

        for (int j = 0; j < ny+1; j++)
        {
            y[j] = tabl[i][j].y;
            z[j] = tabl[i][j].z;
        }
        rc = polenom_method(ny, my, y, z, &answ);
        if (rc)
            return rc;
        new_y[i] = answ;
    }

    double x[nx+1];
    for ( int i = 0; i < nx+1; i++)
    {
        x[i] = tabl[i][0].x;
    }

    rc = polenom_method(nx, mx, x, new_y, &answ);
    *a = answ;
    return rc;
}

int polenom_method(int n, double x, double *new_x, double *new_y, double *answ)
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
}
