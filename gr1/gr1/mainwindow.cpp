#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include "alg.h"
#include <QLabel>
#include <QMessageBox>
#include <math.h>
#include <QString>
#include <QFont>

#define KXMAX 680
#define KYMAX 700
#define KXMIN 20
#define KYMIN 40
#define MAX 700


void MainWindow::mashtab()
{
    double xmax,ymax,xmin,ymin;
    if (answ.c1.x + answ.r1 > answ.c2.x + answ.r2)
    {
        xmax = answ.c1.x + answ.r1;
    }
    else {
        xmax = answ.c2.x + answ.r2;
    }
    if (answ.c1.y + answ.r1 > answ.c2.y + answ.r2)
    {
        ymax = answ.c1.y + answ.r1;
    }
    else {
        ymax = answ.c2.y + answ.r2;
    }
    if (answ.c1.x - answ.r1 < answ.c2.x - answ.r2)
    {
        xmin = answ.c1.x - answ.r1;
    }
    else {
        xmin = answ.c2.x - answ.r2;
    }
    if (answ.c1.y - answ.r1 < answ.c2.y - answ.r2)
    {
        ymin = answ.c1.y - answ.r1;
    }
    else {
        ymin = answ.c2.y - answ.r2;
    }

    double kx,ky;

    kx = (KXMAX-KXMIN)/(xmax - xmin);
    ky = (KYMAX-KYMIN)/(ymax - ymin);

    double k = kx < ky ? kx:ky;

    answ.c1.x = round(KXMIN + (answ.c1.x - xmin)*k);
    answ.c1.y = round(KYMIN + (ymax - answ.c1.y)*k);

    answ.c2.x = round(KXMIN + (answ.c2.x - xmin)*k);
    answ.c2.y = round(KYMIN + (ymax - answ.c2.y)*k);

    answ.o1.p1.x = round(KXMIN + (answ.o1.p1.x - xmin)*k);
    answ.o1.p1.y = round(KYMIN + (ymax - answ.o1.p1.y)*k);

    answ.o1.p2.x = round(KXMIN + (answ.o1.p2.x - xmin)*k);
    answ.o1.p2.y = round(KYMIN + (ymax - answ.o1.p2.y)*k);

    answ.o1.p3.x = round(KXMIN + (answ.o1.p3.x - xmin)*k);
    answ.o1.p3.y = round(KYMIN + (ymax - answ.o1.p3.y)*k);

    answ.o2.p1.x = round(KXMIN + (answ.o2.p1.x - xmin)*k);
    answ.o2.p1.y = round(KYMIN + (ymax - answ.o2.p1.y)*k);

    answ.o2.p2.x = round(KXMIN + (answ.o2.p2.x - xmin)*k);
    answ.o2.p2.y = round(KYMIN + (ymax - answ.o2.p2.y)*k);

    answ.o2.p3.x = round(KXMIN + (answ.o2.p3.x - xmin)*k);
    answ.o2.p3.y = round(KYMIN + (ymax - answ.o2.p3.y)*k);

    answ.p1.x = round(KXMIN + (answ.p1.x - xmin)*k);
    answ.p1.y = round(KYMIN + (ymax - answ.p1.y)*k);

    answ.p2.x = round(KXMIN + (answ.p2.x - xmin)*k);
    answ.p2.y = round(KYMIN + (ymax - answ.p2.y)*k);
    answ.r1 *= k;
    answ.r2 *= k;
}

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
    int rc = 0;
    if (rc == 0)
    {
        draw_circle(paint, answ.c1, answ.r1);
        draw_o(paint, answ.o1,1);
        draw_circle(paint, answ.c2, answ.r2);
        draw_o(paint, answ.o2,2);
        paint.setPen(QPen(Qt::green,3,Qt::SolidLine));

        paint.drawLine(int(answ.p1.x),int(answ.p1.y),int(answ.p2.x),int(answ.p2.y));
        paint.drawLine(int(answ.c1.x),int(answ.c1.y), int(answ.c2.x),int(answ.c2.y));
        paint.drawLine(int(answ.c1.x),int(answ.c1.y), int(answ.p1.x),int(answ.p1.y));
        paint.drawLine(int(answ.p2.x),int(answ.p2.y), int(answ.c2.x),int(answ.c2.y));

        paint.setPen(QPen(Qt::black,3,Qt::SolidLine));
        char l1[30+1];
        snprintf(l1,31,"(%.2f;%.2f)",answ1.p1.x,answ1.p1.y);
        QString s1 = QString(l1);
        snprintf(l1,31,"(%.2f;%.2f)",answ1.p2.x,answ1.p2.y);
        QString s8 = QString(l1);
        snprintf(l1,31,"(%.2f;%.2f)",answ1.c1.x,answ1.c1.y);
        QString s9 = QString(l1);
        snprintf(l1,31,"(%.2f;%.2f)",answ1.c2.x,answ1.c2.y);
        QString s10 = QString(l1);
        std::cout<< l1<< std::endl;
        snprintf(l1,31,"%d (%.2f;%.2f)",answ1.o1.n1,answ1.o1.p1.x,answ1.o1.p1.y);
        QString s2 = QString(l1);
        snprintf(l1,31,"%d (%.2lf;%.2lf)",answ1.o1.n2,answ1.o1.p2.x,answ1.o1.p2.y);
        QString s3 = QString(l1);
        snprintf(l1,31,"%d (%.2lf;%.2lf)",answ1.o1.n3,answ1.o1.p3.x,answ1.o1.p3.y);
        QString s4 = QString(l1);
        snprintf(l1,31,"%d (%.2lf;%.2lf)",answ1.o2.n1,answ1.o2.p1.x,answ1.o2.p1.y);
        QString s5 = QString(l1);
        snprintf(l1,31,"%d (%.2lf;%.2lf)",answ1.o2.n2,answ1.o2.p2.x,answ1.o2.p2.y);
        QString s6 = QString(l1);
        snprintf(l1,31,"%d (%.2lf;%.2lf)",answ1.o2.n3,answ1.o2.p3.x,answ1.o2.p3.y);
        QString s7 = QString(l1);
        QFont f("Times");
        f.setPixelSize(11);
        paint.setFont(f);
        paint.drawText(int(answ.p1.x + 10),int(answ.p1.y + 5), s1);
        paint.drawText(int(answ.p2.x + 10),int(answ.p2.y + 5), s8);
        paint.drawText(int(answ.c1.x + 10),int(answ.c1.y + 5), s9);
        paint.drawText(int(answ.c2.x + 10),int(answ.c2.y + 5), s10);
        paint.drawText(int(answ.o1.p1.x+10),int(answ.o1.p1.y+5), s2);
        paint.drawText(int(answ.o1.p2.x+10),int(answ.o1.p2.y+5), s3);
        paint.drawText(int(answ.o1.p3.x+10),int(answ.o1.p3.y+5), s4);
        paint.drawText(int(answ.o2.p1.x+10),int(answ.o2.p1.y+5), s5);
        paint.drawText(int(answ.o2.p2.x+10),int(answ.o2.p2.y+5), s6);
        paint.drawText(int(answ.o2.p3.x+10),int(answ.o2.p3.y+5), s7);
    }
}

void MainWindow::draw_o(QPainter &paint, struct okr o, int i)
{
    if (i == 1)
    {
        paint.setPen(QPen(Qt::red,10,Qt::SolidLine));
    }
    else
    {
        paint.setPen(QPen(Qt::blue,10,Qt::SolidLine));
    }
    paint.drawPoint(int(o.p1.x),int(o.p1.y));
    paint.drawPoint(int(o.p2.x),int(o.p2.y));
    paint.drawPoint(int(o.p3.x),int(o.p3.y));
}

void MainWindow::draw_circle(QPainter &paint, cent c, double r)
{
    paint.setPen(QPen(Qt::black,1,Qt::SolidLine));
    paint.drawEllipse(int(c.x-r),int(c.y-r),int(2*r), int(2*r));
    paint.drawPoint(int(c.x),int(c.y));
}

void MainWindow::init()
{
    answ.s = 0;
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

void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    points.clear();
    init();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->listWidget_2->clear();
    points2.clear();
    init();
}

void MainWindow::on_pushButton_3_clicked()
{
    init();
    cent c;

    double r = 0;
    struct okr o1;
    unsigned long long int p = points.size();
    unsigned long long int p2 = points2.size();
    if (p < 3 || p2 < 3)
    {
        QMessageBox msgBox;
        msgBox.setText("Недостаточно точек для решения задачи.");
        msgBox.exec();
        return;
    }
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
     if (answ.s == 0.0)
     {
         QMessageBox msgBox;
         msgBox.setText("Невозможно найти подходящую пару окружностей!");
         msgBox.exec();
         return;
     }

     QMessageBox msgBox;
     char l[300];
     snprintf(l,300,"Первая окружность:\n "
                   "%d (%lf;%lf)\n "
                   "%d (%lf;%lf)\n "
                   "%d (%lf;%lf)\n "
                   "Вторая окружность:\n "
                   "%d (%lf;%lf)\n"
                   "%d (%lf;%lf)\n"
                   "%d (%lf;%lf)\n"
                   "Площадь фигуры: "
                   "s = %lf",
              answ.o1.n1,answ.o1.p1.x,answ.o1.p1.y,
              answ.o1.n2,answ.o1.p2.x,answ.o1.p2.y,
              answ.o1.n3,answ.o1.p3.x,answ.o1.p3.y,
              answ.o2.n1,answ.o2.p1.x,answ.o2.p1.y,
              answ.o2.n2,answ.o2.p2.x,answ.o2.p2.y,
              answ.o2.n3,answ.o2.p3.x,answ.o2.p3.y,
              answ.s);
     QString s6 = QString(l);
     line_t l1;
     int rc = find_kosat(answ.c1, answ.c2, answ.r1, answ.r2, &l1);
     if (rc == 0)
     {
         find_point(answ.c1, l1, &(answ.p1), answ.r1);
         find_point(answ.c2,l1,&(answ.p2), answ.r2);
         answ1 = answ;
         mashtab();
         update();
         msgBox.setText(l);
         msgBox.exec();
     }
     else
     {
         QMessageBox msgBox;
         msgBox.setText("Для данных окружностей невозможно построить касательную!");
         msgBox.exec();
     }

}

void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void MainWindow::on_lineEdit_2_returnPressed()
{
    on_pushButton_4_clicked();
}

void MainWindow::on_pushButton_6_clicked()
{
   //QList<QListWidgetItem *> a = ui->listWidget->selectedItems();
   QListWidgetItem *b = ui->listWidget->currentItem();
   QString s = b->text();
   QStringList u = s.split(" ", QString::SkipEmptyParts);

   cent a;
   a.x = u[0].toDouble();
   a.y = u[1].toDouble();
   ui->listWidget->takeItem(int(ui->listWidget->row(ui->listWidget->currentItem())));

   int k;
   for(unsigned int i = 0; i < points.size(); i++)
   {
       if (points[i].x == a.x && points[i].y == a.y)
       {
           k = i;
           break;
       }
   }

   for (unsigned int i = k; i < points.size()-1; i++)
   {
       points[i] = points[i+1];
   }
   points.pop_back();

   //std::cout << ui->listWidget->takeItem(1)->text().toStdString() << std::endl;
}

void MainWindow::on_pushButton_7_clicked()
{
    QListWidgetItem *b = ui->listWidget_2->currentItem();
    QString s = b->text();
    QStringList u = s.split(" ", QString::SkipEmptyParts);

    cent a;
    a.x = u[0].toDouble();
    a.y = u[1].toDouble();
    ui->listWidget_2->takeItem(int(ui->listWidget_2->row(ui->listWidget_2->currentItem())));

    int k;
    for(unsigned int i = 0; i < points2.size(); i++)
    {
        if (points2[i].x == a.x && points2[i].y == a.y)
        {
            k = i;
            break;
        }
    }

    for (unsigned int i = k; i < points2.size()-1; i++)
    {
        points2[i] = points2[i+1];
    }
    points2.pop_back();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //int row = ui->listWidget->currentIndex().row();
     //QModelIndex index = Model->index(row);
     //ui->listWidget->setCurrentIndex(index);
    // ui->listWidget->edit();

}
