#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <math.h>
#include<QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
   color(Qt::black),
   bg_color(Qt::white),
   flag(false),
   f(false)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cda(QPainter &paint, double x1, double y1, double x2, double y2, QColor color)
{
    paint.setPen(QPen(color,1,Qt::SolidLine));
    double dx = x2-x1;
    double dy = y2-y1;
    double l;
    if (fabs(dx) > fabs(dy))
    {
        l = fabs(dx);
    }
    else
        l = fabs(dy);
    double sx = dx/l;
    double sy = dy/l;
    double x = x1;
    double y = y1;
    for(int i = 0; i <= l; i++)
    {
        paint.drawPoint(int(round(x)), int(round(y)));
        x += sx;
        y += sy;
    }
}

#define EPS 0.00000001
int s(double x)
{
    if (x > 0)
        return 1;
    if (fabs(x) < EPS)
        return 0;
    return -1;
}

void MainWindow::br_1(QPainter &paint, double x1, double y1, double x2, double y2, QColor color)
{
    paint.setPen(QPen(color,1,Qt::SolidLine));
    double x = x1;
    double y = y1;
    double dx = x2-x1;
    double dy = y2-y1;
    double sx = s(dx);
    double sy = s(dy);
    dx = fabs(dx);
    dy = fabs(dy);
    int obmen;
    if (dx>dy)
        obmen = 0;
    else
    {
        obmen = 1;
        double t = dx;
        dx = dy;
        dy = t;
    }
    double m = dy/dx;
    double l = m - 0.5;
    for (int i = 0; i <= dx; i++)
    {
        paint.drawPoint(int(x), int(y));
        if (l >= 0)
        {
            if (obmen == 0)
                y +=sy;
            else
                x +=sx;
            l--;
        }
        if (l < 0)
        {
            if (obmen == 0)
               x +=sx;
            else
               y +=sy;
        }
        l +=m;
    }

}

void MainWindow::br_2(QPainter &paint, double x1, double y1, double x2, double y2, QColor color)
{
    paint.setPen(QPen(color,1,Qt::SolidLine));
    int x = int(x1);
    int y = int(y1);
    int dx = int(x2-x1);
    int dy = int(y2-y1);
    int sx = s(dx);
    int sy = s(dy);
    dx = abs(dx);
    dy = abs(dy);
    int obmen;
    if (dx>dy)
        obmen = 0;
    else
    {
        obmen = 1;
        int t = dx;
        dx = dy;
        dy = t;
    }
    //double m = dy/dx;
    int l = 2*dy - dx;
    for (int i = 0; i <= dx; i++)
    {
        paint.drawPoint(x, y);
        if (l >= 0)
        {
            if (obmen == 0)
                y +=sy;
            else
                x +=sx;
            l -= 2*dx;
        }
        if (l < 0)
        {
            if (obmen == 0)
               x +=sx;
            else
               y +=sy;
        }
        l +=2*dy;
    }

}
void MainWindow::br_3(QPainter &paint, double x1, double y1, double x2, double y2, QColor color)
{
    paint.setPen(QPen(color,1,Qt::SolidLine));
    double I = 200;
    double x = x1;
    double y = y1;
    double dx = x2-x1;
    double dy = y2-y1;
    double sx = s(dx);
    double sy = s(dy);
    dx = fabs(dx);
    dy = fabs(dy);
    int obmen;
    if (dx>dy)
        obmen = 0;
    else
    {
        obmen = 1;
        double t = dx;
        dx = dy;
        dy = t;
    }
    double m = dy/dx;
    m = m * I;
    double l = I/2;
    double W = I - m;
    color.setAlpha(int(l));
    paint.setPen(color);


    paint.drawPoint(int(x), int(y));

    for (int i = 0; i <= dx; i++)
    {
        //paint.d
        if (l <= W)
        {
            if (obmen == 0)
                x +=sx;
            else
                y +=sy;
            l += m;
        }
        if (l > W)
        {
            x +=sx;
            y +=sy;
            l -= W;
        }


        color.setAlpha(int(l));
        paint.setPen(color);

        paint.drawPoint(int(x), int(y));

    }

}

typedef struct point p;

struct point
{
    double x;
    double y;

    point() : x(0), y(0){}
};

#define PI 3.14

void povorot(p &a, double xc, double yc, double alpha)
{
    double new_x = xc + (a.x - xc) * cos(alpha * PI / 180) + (a.y - yc) * sin(alpha * PI / 180);
    a.y = yc - (a.x - xc) * sin(alpha * PI / 180) + (a.y - yc) * cos(alpha * PI / 180);
    a.x = new_x;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter paint(this);

    paint.setPen(QPen(Qt::black,1,Qt::SolidLine));
    paint.setBrush(Qt::white);
    paint.drawRect(0,17,770,717);
    if (i == 1)
        cda(paint,x1,y1,x2,y2,color);
    if (i == 2)
        br_1(paint,x1,y1,x2,y2,color);
    if (i == 3)
        br_2(paint,x1,y1,x2,y2,color);
    if (i == 4)
        br_3(paint,x1,y1,x2,y2,color);
    if (i == 5)
    {
        paint.setPen(QPen(color,1,Qt::SolidLine));
        paint.drawLine(int(x1),int(y1),int(x2),int(y2));
    }
    if (f)
    {
        for(int i = 0; i < 180; i+=10)
        {
            printf("s s ");
            p p1,p2;
            p1.x = x1;
            p1.y = y1;
            p2.x = x2;
            p2.y = y2;
            povorot(p1,(x2+x1)/2,(y2+y1)/2, i);
            povorot(p2,(x2+x1)/2,(y2+y1)/2, i);

            printf("%d %d; ", p1.x, p1.y);

            if (i == 1)
                cda(paint,p1.x,p1.y,p2.x,p2.y,color);
            else if (i == 2)
                br_1(paint,p1.x,p1.y,p2.x,p2.y,color);
            else if (i == 3)
                br_2(paint,p1.x,p1.y,p2.x,p2.y,color);
            else if (i == 4)
                br_3(paint,p1.x,p1.y,p2.x,p2.y,color);
            else if (i == 5)
            {
                paint.setPen(QPen(color,1,Qt::SolidLine));
                paint.drawLine(int(p1.x),int(p1.y),int(p2.x),int(p2.y));
            }
        }
    }
    if (flag)
    {
        paint.setPen(QPen(bg_color,1,Qt::SolidLine));
        if (bg_i == 1)
            cda(paint,bg_x1,bg_y1,bg_x2,bg_y2,bg_color);
        if (bg_i == 2)
            br_1(paint,bg_x1,bg_y1,bg_x2,bg_y2,bg_color);
        if (bg_i == 3)
            br_2(paint,bg_x1,bg_y1,bg_x2,bg_y2,bg_color);
        if (bg_i == 4)
            br_3(paint,bg_x1,bg_y1,bg_x2,bg_y2,bg_color);
        if (bg_i == 5)
        {
            paint.setPen(QPen(color,1,Qt::SolidLine));
            paint.drawLine(int(x1),int(y1),int(x2),int(y2));
        }
    }
    paint.setPen(QPen(Qt::lightGray,1,Qt::SolidLine));
    paint.setBrush(Qt::lightGray);
    paint.drawRect(0,0,1050,17);
    paint.drawRect(770,0,400,900);
    paint.drawRect(0,717,1050,300);

    paint.setBrush(color);
    paint.drawRect(830,457,40,40);
}

void MainWindow::on_pushButton_clicked()
{
    f = false;
    flag = false;
    QString x = ui->x1->text();
    QStringList u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->x1->clear();
        return;
    }
     x1 = u[0].toDouble();
    x = ui->x2->text();
    u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->x2->clear();
        return;
    }
     x2 = u[0].toDouble();
    x = ui->y1->text();
    u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->y1->clear();
        return;
    }
    y1 = u[0].toDouble();
    x = ui->y2->text();
    u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->y2->clear();
        return;
    }
     y2 = u[0].toDouble();

     if (ui->radioButton->isChecked())
         i = 1;

     if (ui->radioButton_2->isChecked())
         i = 2;
     if (ui->radioButton_3->isChecked())
         i = 3;
     if (ui->radioButton_4->isChecked())
         i = 4;
     if (ui->radioButton_5->isChecked())
         i = 5;
     update();

}

void MainWindow::on_pushButton_3_clicked()
{
    QColor col = QColorDialog::getColor();
    if (!col.isValid() ) {
        return;
    }
    color = col;
}

void MainWindow::on_pushButton_2_clicked()
{
    f = false;
    flag = true;
    QString x = ui->x1->text();
    QStringList u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->x1->clear();
        return;
    }
     bg_x1 = u[0].toDouble();
    x = ui->x2->text();
    u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->x2->clear();
        return;
    }
     bg_x2 = u[0].toDouble();
    x = ui->y1->text();
    u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->y1->clear();
        return;
    }
    bg_y1 = u[0].toDouble();
    x = ui->y2->text();
    u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->y2->clear();
        return;
    }
     bg_y2 = u[0].toDouble();
    if (ui->radioButton->isChecked())
        bg_i = 1;
    if (ui->radioButton_2->isChecked())
        bg_i = 2;
    if (ui->radioButton_3->isChecked())
        bg_i = 3;
    if (ui->radioButton_4->isChecked())
        bg_i = 4;
    if (ui->radioButton_5->isChecked())
        bg_i = 5;
    update();
}

void MainWindow::on_pushButton_5_clicked()
{
    f = true;
}
