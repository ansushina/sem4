#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include "alg.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter paint(this);

    if (answ.s != 0.0)
    {
         draw_all(paint);
    }
}

void MainWindow::draw_all(QPainter &paint)
{
    draw_circle(paint, answ.c1, answ.r1);
    draw_o(paint, answ.o1,1);
    draw_circle(paint, answ.c2, answ.r2);
    draw_o(paint, answ.o2,2);
    line_t l;
    int rc = find_kosat(answ.c1, answ.c2, answ.r1, answ.r2, &l);
    if (rc == 0)
    {
        paint.setPen(QPen(Qt::blue,3,Qt::SolidLine));
        find_point(answ.c1, l, &(answ.p1), answ.r1);
        find_point(answ.c2,l,&(answ.p2), answ.r2);

        QLabel *pl1 = new QLabel();
        paint.drawLine(answ.p1.x,answ.p1.y,answ.p2.x,answ.p2.y);
        paint.drawLine(answ.c1.x,answ.c1.y, answ.c2.x,answ.c2.y);
        paint.drawLine(answ.c1.x,answ.c1.y, answ.p1.x,answ.p1.y);
        paint.drawLine(answ.p2.x,answ.p2.y, answ.c2.x,answ.c2.y);
    }
}

void MainWindow::draw_o(QPainter &paint, struct okr o, int i)
{
    if (i == 1)
    {
        paint.setPen(QPen(Qt::red,5,Qt::SolidLine));
    }
    else
    {
        paint.setPen(QPen(Qt::green,5,Qt::SolidLine));
    }
    paint.drawPoint(int(o.p1.x),int(o.p1.y));
    paint.drawPoint(int(o.p2.x),int(o.p2.y));
    paint.drawPoint(int(o.p3.x),int(o.p3.y));
}

void MainWindow::draw_circle(QPainter &paint, cent c, double r)
{
    paint.setPen(QPen(Qt::black,3,Qt::SolidLine));
    paint.drawEllipse(int(c.x-r),int(c.y-r),int(2*r), int(2*r));
    paint.drawPoint(int(c.x),int(c.y));
}

void MainWindow::init()
{
    answ.s = 0;
}

void MainWindow::on_pushButton_clicked()
{
    QString x = "";
    x = ui->lineEdit->text();
    QStringList u = x.split(" ", QString::SkipEmptyParts);
    int count = u.count();
    if (count == 2)
    {
        cent a;
        a.x = u[0].toDouble();
        a.y = u[1].toDouble();
        points.push_back(a);
        ui->listWidget->addItem(x);
        ui->lineEdit->clear();
    }
    else {
        ui->lineEdit->clear();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
    points.clear();
    init();
}

void MainWindow::do_something(cent c1, double r1, cent c2, double r2, struct okr o1, struct okr o2)
{
    double s;
    std::cout << "do something"<< std::endl;
    int rc = find_s(c1,r1,c2,r2,&s);
    if (rc == 0)
    {
        std::cout << s << std::endl;
        if (s > answ.s)
        {
            answ.o1 = o1;
            answ.o2 = o2;
            answ.s = s;
            answ.c1 = c1;
            answ.c2 = c2;
            answ.r1 = r1;
            answ.r2 = r2;
        }
    }
}

void MainWindow::find_second(cent c, double r, struct okr o)
{
    cent c1;
    double r1;
    struct okr o1;
    unsigned long long int p = points2.size();
    for (unsigned int i = 0; i < p - 2; i++)
    {
        for(unsigned int j = i + 1; j < p - 1; j++)
         {
              for(unsigned int k = j + 1; k < p; k++)
              {
                  if (find_circle(points2[i],points2[j],points2[k], &c1, &r1) == 0)
                  {
                      //std::cout << c1<<<< std::endl;
                      o1.p1 = points2[i];
                      o1.p2 = points2[j];
                      o1.p3 = points2[k];
                      o1.n1 = i;
                      o1.n2 = j;
                      o1.n3 = k;

                      do_something(c,r,c1,r1,o,o1);
                  }
              }
         }
    }
}

//int find_circle(cent p1, cent p2, cent p3, cent *c, double *r)
void MainWindow::on_pushButton_2_clicked()
{
    cent c;
    double r = 0;
    struct okr o1;
     unsigned long long int p = points.size();
     for (unsigned int i = 0; i < p - 2; i++)
     {
         for(unsigned int j = i + 1; j < p - 1; j++)
         {
             for(unsigned int k = j + 1; k < p; k++)
             {
                 if (find_circle(points[i],points[j],points[k], &c, &r) == 0)
                 {
                     std::cout <<"lalal " << c.y << r << std::endl;
                     o1.p1 = points[i];
                     o1.p2 = points[j];
                     o1.p3 = points[k];
                     o1.n1 = i;
                     o1.n2 = j;
                     o1.n3 = k;
                     find_second(c,r, o1);
                 }
             }
         }
     }
     update();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString x = "";
    x = ui->lineEdit_2->text();
    QStringList u = x.split(" ", QString::SkipEmptyParts);
    int count = u.count();
    if (count == 2)
    {
        cent a;
        a.x = u[0].toDouble();
        a.y = u[1].toDouble();
        points2.push_back(a);
        ui->listWidget_2->addItem(x);
        ui->lineEdit_2->clear();
    }
    else {
        ui->lineEdit_2->clear();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->listWidget_2->clear();
    points2.clear();
    init();
}
