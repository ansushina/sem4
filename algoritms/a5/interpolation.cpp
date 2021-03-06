#include "interpolation.h"
#include "stdlib.h"

#define OK 0
#define ERR_IO 1
#define ERR_FILE 2
#define ERR_PROC 3
#define ERR 4
#define ERR_MEMORY 5

void copy_mas(double *x, double *y, const double *ax, const double *ay, int beg, int end)
{
    int j = 0;
    for (int i = beg; i <= end; i++)
    {
        x[j] = ax[i];
        y[j] = ay[i];
        j++;
    }
}
// поиск позиции
int find_pos(double main_x,const double *all_x, int all_count)
{
    int pos;
    int i;
    if (main_x > all_x[0]) //значения в таблице по возрастанию
    {
        for (i = 0; i < all_count && main_x >= all_x[i]; i++);
    }
    else // случай убывания
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

// найдем начало и конец массива для копирования
int find_beg_end(int pos, int *b, int *e, int all_count, int n)
{
    int j = 1;
    int p = 1;
    int begin = pos, end = pos;
    if (all_count < n + 1)
    {
        return ERR;
    }
    while (j != n + 1) // пока не наберем n+1
    {
        if (pos + p < all_count ) // берем строку снизу
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
        if (pos - p < 0 && pos + p > all_count) // если недостаточно точек, выходим из цикла
            break;
        //printf(" %d %d \n", begin, end);
    }
    if (j != n + 1)// вернем ошибку, если недостаточно точек
        return ERR;
    *b = begin;
    *e = end;
    return OK;
}

int make_new_mas(int n, double main_x, double **x, double **y,const  double *all_x,
    const double *all_y, int all_count)
{
    // найдем позицию
    int pos = find_pos(main_x, all_x, all_count);

    double *nx = (double *)malloc((n + 1) * sizeof(double));
    if (!nx)
        return ERR_MEMORY;
    double *ny = (double *)malloc((n + 1) * sizeof(double));
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
    //printf("Отрезок: [%lf; %lf]\n\n", all_x[begin], all_x[end]);
    // сформируем новую таблицу
    copy_mas(nx, ny, all_x, all_y, begin, end);

    *x = nx;
    *y = ny;

    return OK;
}

// интерполяция
int interpolation(int n, double x, double *new_x, double *new_y, double *answ)
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
            //printf("%lf ", a[count]);
        }
        raz[j] = a[0];
       // printf("\n");
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
