#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


#define OK 0
#define ERR_READ 1
#define ERR_PARAM 2
#define ERR_MEMORY 3
#define ERR_NULL 4
#define ERR_RANGE 5
#define ERR_FILE 6
#define ERR_SUM 7
#define ERR_MULT 8
#define ERR_GAUSS 9


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    //QRegExp check ("[-+]?(\\d+(\\.\\d*)?|\\.\\d+)$");
    //QRegExpValidator *my_double_validator = new QRegExpValidator(check, this);
    //ui->lineEdit->setValidator(my_double_validator);
    //connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
}

double fi(int k, double x)
{
    return pow(x, k);
}

double func(double x, double *c, int n)
{
    double answ = 0;
    for (int i = 0; i < n; i++)
    {
        answ += c[i] * pow(x, i);
    }
    return answ;
}
void free_matrix(double **data, int n)
{
    //assert(data != NULL);
    //assert(n != 0);
    for (int i = 0; i < n; i++)
        free(data[i]);
    free(data);
}

double **allocate_matrix(int n, int m)
{
    if (n == 0 || m == 0)
        return NULL;
    double **data = (double **)calloc(n, sizeof(double*));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        data[i] = (double *)calloc(m, sizeof(double));

        if (!data[i])
        {
            free_matrix(data, n);

            return NULL;
        }
    }

    return data;
}


/**
 * @brief make_same
 * Заполняет матрицу б элементами матрицы а
 */
void make_same(double **a, double **b, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = a[i][j];
}
/**
 * @brief make_sort
 * Создает отсортированный массив
 */
void make_sort(int *a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = i;
}

/**
 * @brief swap1
 * Меняет местами строки
 */
void swap1(double **a, int n, int i, int j)
{
    double *swap;

    swap = a[i];
    a[i] = a[j];
    a[j] = swap;
}

/**
 * @brief swap2
 * Меняет местами столбцы
 */
void swap2(double **a, int n, int i, int j)
{
    double swap;
    for (int u = 0; u < n; u++)
    {
        swap = a[u][i];
        a[u][i] = a[u][j];
        a[u][j] = swap;
    }
}

/**
 * @brief make_diff
 * Вычитает из jой строки iую
 */
void make_diff(double **a, int m, int j, int i)
{
    double u = -a[j][i];
    //printf("u %lf ", u);
    for (int k = i; k < m; k++)
        a[j][k] += u * a[i][k];
}

/**
 * @brief make_normal
 * Нормализирует строку
 */
void make_normal(double **a, int m, int i)
{
    double d = a[i][i];
    for (int j = i; j < m; j++)
        a[i][j] /= d;
}

/**
 * @brief make_answer
 * Сичтают стоблец решений
 */
void make_answer(double **a, int n, int m, double **b, int *p2)
{
    b[p2[n - 1]][0] = a[n - 1][n];
    for (int i = n - 2; i >= 0; i--)
    {
        //printf(" %d ", i);
        for (int k = i + 1; k < n; k++)
            b[p2[i]][0] -= a[i][k] * b[p2[k]][0];
        b[p2[i]][0] += a[i][n];
    }
}

/**
 * @brief find_main
 * Поиск главного элемента(2)
 */
int find_main1(int *p2, double **a, int n, int k)
{
    int t1 = k, t2 = k;
    int swap;
    double max = a[k][k];
    for (int i = k; i < n; i++)
        for (int j = k; j < n; j++)
            if (fabs(a[i][j]) > max)
            {
                max = fabs(a[i][j]);
                t1 = i;
                t2 = j;
            }
    if (fabs(max) < 0.000000001)
        return ERR_GAUSS;

    swap = p2[k];
    p2[k] = p2[t2];
    p2[t2] = swap;

    swap1(a, n, k, t1);
    swap2(a, n, k, t2);

    return OK;
}

void zero_matrix(double **a, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = 0;
}
/**
 * @brief gauss
 * Реализует метод Гаусса
 */
int gauss(double **u, int *p2, int n, int m,
    double **b)
{
    for (int i = 0; i < n; i++)
    {
        if (find_main1(p2, u, n, i) != OK)
            return ERR_GAUSS;
        make_normal(u, m, i);
        for (int j = i + 1; j < n; j++)
            make_diff(u, m, j, i);
    }
    zero_matrix(b, n, 1);
    make_answer(u, n, m, b, p2);
    return OK;
}

int do_gauss(double **a, int n, int m, double ***b)
{
    double **u;
    int *p2;
    int rc = OK;

    if (n <= 0)
        return ERR_NULL;

    if (a == NULL)
        return ERR_NULL;

    if (n != m - 1)
        return ERR_GAUSS;

    u = allocate_matrix(n, m);
    if (u)
    {
        p2 = (int*)malloc(m * sizeof(int));
        if (p2)
        {
            *b = allocate_matrix(n, 1);
            if (*b)
            {
                make_same(a, u, n, m);
                make_sort(p2, m);

                rc = gauss(u, p2, n, m, *b);
                if (rc != OK)
                    free_matrix(*b, n);
            }
            else
                rc = ERR_MEMORY;
            free(p2);
        }
        else
            rc = ERR_MEMORY;
        free_matrix(u, n);
    }
    else
        rc = ERR_MEMORY;

    return rc;
}

int read_file(FILE *f, int &n_points, double **x_mas, double **y_mas, double **w_mas)
{
    //cout<<"read";
    int count = 0;
    double x,y,w;
    while (fscanf(f,"%lf %lf %lf",&x, &y, &w) == 3)
    {
        count ++;
    }
    //cout<<"count " << count;
    rewind(f);

    double *xm = new double[count];
    double *ym = new double[count];
    double *wm = new double[count];
    cout<<"Таблица" << endl;

    for (int i = 0; i < count; i++)
    {
        if (fscanf(f,"%lf %lf %lf",&xm[i], &ym[i], &wm[i]) != 3)
        {
            delete [] xm;
            delete [] ym;
            delete [] wm;
            return 1;
        }
        cout << xm[i] <<" " << ym[i] << " " << wm[i] << endl;
    }
    cout<<" "<<endl;
    n_points = count;
    *x_mas = xm;
    *y_mas = ym;
    *w_mas = wm;
    return 0;
}

void find_a(double **matrix, int n, double *x, double *w, int x_count)
{
    double sum = 0;
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < n; j++)
        {
            sum = 0;
            for (int i = 0; i < x_count; i++)
            {
                sum += w[i] * fi(k, x[i]) * fi(j, x[i]);
            }
            matrix[k][j] = sum;
        }
    }
}

void find_b(double *mas, int n, double *x, double *y, double *w, int x_count)
{
    double sum = 0;

    for (int j = 0; j < n; j++)
    {
        sum = 0;
        for (int i = 0; i < x_count; i++)
        {
            sum += w[i] * y[i] * fi(j, x[i]);
        }
        mas[j] = sum;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
#define KXMIN 50

double mastab(double x,double xmin, double k)
{
    return round(KXMIN + (x - xmin)*k);
}

#define APP "notepad.exe"
#define DOT "C:\\Graphviz2.38\\bin\\dot.exe"
#define ME "C:\\c_prog\\un1\\my-rep\\algoritms\\a4\\"
void MainWindow::process(int n, double *x, double *y, double *w, int x_count)
{
  // cout<<"f-----";
   double **matrix = allocate_matrix(n, n+1);
   find_a(matrix, n, x, w, x_count);
   double *b = new double[n];
   find_b(b,n,x,y,w,x_count);
   //cout<<"finded";

   for (int i = 0; i < n; i++)
   {
       matrix[i][n] = b[i];
   }
   delete [] b;

   double **c_matrix = nullptr;
   int rc = do_gauss(matrix,n,n+1,&c_matrix);
   if (rc)
   {
       free_matrix(matrix, n);
      cout<<"somethig goes wrong!";
      return;
   }
      //cout<<"gauss";

   double *c = new double[n];
   for (int i = 0; i < n; i++)
   {
       c[i] = c_matrix[i][0];
       cout<<c[i]<<"  ";
   }
   cout << " " << endl;


   double xmax = x[0], xmin = x[0];
   double ymax = y[0], ymin = y[0];
   for (int i = 0; i < x_count; i++)
   {
       if (x[i] > xmax)
           xmax = x[i];
       if (y[i] > ymax)
           ymax = y[i];
       if (x[i] < xmin)
           xmin = x[i];
       if (y[i] < ymin)
           ymin = y[i];
   }
   double kx = (650-KXMIN)/(xmax - xmin);
   double ky = (650-KXMIN)/(ymax - ymin);
   double k = kx < ky ? kx:ky;

   QPen pen = QPen(Qt::red,4,Qt::SolidLine);
   //scene->addEllipse(100, 100, 1, 1, pen, QBrush(Qt::SolidPattern));
   for (int i = 0; i < x_count; i++)
   {
       scene->addEllipse(mastab(x[i],xmin,k), mastab(y[i],ymin,k), 2, 2, pen, QBrush(Qt::red,Qt::SolidPattern));
   }
   pen = QPen(Qt::black,1,Qt::SolidLine);
   double step = (xmax - xmin)/300;
   for (double j = xmin; j < xmax+step; j+= step)
   {
       //scene->addEllipse(mastab(j,xmin,k), mastab(func(j, c, n),ymin,k), 1, 1, pen, QBrush(Qt::SolidPattern));
       scene->addLine(mastab(j,xmin,k), mastab(func(j, c, n),ymin,k),mastab(j+step,xmin,k), mastab(func(j+step, c, n),ymin,k),pen);
   }
   system("start " APP " " ME "\\1.txt");
   update();
}

void MainWindow::on_pushButton_clicked()
{
    //cout<<"hiiii" << std::endl;
    QString l_n = ui->lineEdit->text();
    QStringList u_n = l_n.split(" ", QString::SkipEmptyParts);

    if (u_n.count() != 1)
    {
        ui->lineEdit->clear();
        return;
    }
    int n = u_n[0].toInt();
    int points_count = 0;
    double *x, *y, *w;
    //cout<<"hiiii" << std::endl;
    FILE *file = fopen("C:/c_prog/un1/my-rep/algoritms/a4/1.txt", "r");
        //cout<<"hiiii" << std::endl;
    if (file)
    {
        //cout<<"hi" << std::endl;
        int rc = read_file(file, points_count, &x, &y, &w);
        //cout<<"hiiii" << std::endl;
        if (rc == 0)
        {
            process(n + 1, x, y, w,points_count);
            delete [] x;
            delete [] y;
            delete [] w;
        }
        else
        {
            cout<<"read error";
        }
        fclose(file);
    }
    else
    {
        cout<<"file error";
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    scene->clear();
}
