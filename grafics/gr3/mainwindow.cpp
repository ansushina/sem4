#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <math.h>

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

void MainWindow::cda(QPainter &paint)
{
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
        paint.drawPoint(round(x), round(y));
        x += sx;
        y += sy;
    }
}

int s(double x)
{
    if (x > 0)
        return 1;
    if (x == 0)
        return 0;
    return -1;
}

void MainWindow::br_1(QPainter &paint)
{
    double x = x1;
    double y = y1;
    double dx = x2-x1;
    double dy = y2-y1;
    double sx = s(dx);
    double sy = s(dy);
    dx = fabs(dx);
    dy = fabs(dy);
    double obmen;
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
        paint.drawPoint(x, y);
        if (l >= 0)
        {
            if (obmen == 0)
                y +=sy;
            else
                x +=sx;
            l--;
        }
        else
        {
            if (obmen == 0)
               x +=sx;
            else
               y +=sy;
        }
        l +=m;
    }

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter paint(this);

    paint.setPen(QPen(Qt::black,1,Qt::SolidLine));
    if (i == 1)
        cda(paint);
    if (i == 2)
        br_1(paint);
}

void MainWindow::on_pushButton_clicked()
{
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
     update();
     if (ui->radioButton_2->isChecked())
         i = 2;
}
