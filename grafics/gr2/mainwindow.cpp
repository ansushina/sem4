#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

#define A 350.
#define B 350.
#define R 100.
//y = c - (x-d)(x-d)
#define C 350.
#define D 350.
#define PI 3.14

double MainWindow::f(double x)
{
    //y = c - (x-d)(x-d)
    return c - (x - d)*(x - d);
}

void perenos(p &a, double dx, double dy)
{
    a.x += dx;
    a.y += dy;
}


void mastab(p &a, double xm, double ym, double kx, double ky)
{
    a.x = xm + kx*(a.x - xm);
    a.y = ym + ky*(a.y - ym);
}

void povorot(p &a, double xc, double yc, double alpha)
{
    double new_x = xc + (a.x - xc) * cos(alpha * PI / 180) + (a.y - yc) * sin(alpha * PI / 180);
    a.y = yc - (a.x - xc) * sin(alpha * PI / 180) + (a.y - yc) * cos(alpha * PI / 180);
    a.x = new_x;
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

void MainWindow::init()
{
    a = A;
    b = B;
    c = C;
    d = D;
    r = R;

    double step = 0.5;
    for (double i = a - r; i < a + r; i += step)
    {
        p p;
        p.x = i;
        p.y = b - sqrt(r*r - (i-a)*(i-a));
        okr.push_back(p);
    }
    for (double i = a + r; i >= a - r; i -= step)
    {
        p p;
        p.x = i;
        p.y = b + sqrt(r*r - (i-a)*(i-a));
        okr.push_back(p);
    }

    /*for (double i = a + r; i < a - r; i += step)
    {
        p p;
        p.x = i;
        p.y = b - sqrt(r*r - (i-a)*(i-a));
        okr.push_back(p);
    }
    for (double i = a - r; i >= a + r; i += step)
    {
        p p;
        p.x = i;
        p.y = b + sqrt(r*r - (i-a)*(i-a));
        okr.push_back(p);
    }*/

    double from = d - sqrt(2*r + c - b);
    double to = d + sqrt(2*r + c - b);
    std::cout << from << to << std::endl;
    double i;
    for(i = from; i < to; i += step)
    {
        //paint.drawLine(int(i), int(f(i)), int(i+step), int(f(i+step)));
        p a;
        a.x = i;
        a.y = f(i);
        points.push_back(a);
    }
    //paint.drawLine(int(i), int(f(i)), int(to), int(f(to)));
    p a;
    a.x = to;
    a.y = f(to);
    points.push_back(a);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter paint(this);

    paint.setPen(QPen(Qt::black,1,Qt::SolidLine));
    draw_circle(paint);
    draw_grafic(paint);
    paint.setPen(QPen(Qt::white,1,Qt::SolidLine));
    paint.setBrush(Qt::white);
    paint.drawRect(770,0,300,770);
    paint.drawRect(0,715, 1050, 50 );
    paint.drawRect(0,0,1050,15);
}

void MainWindow::draw_circle(QPainter &paint)
{
    paint.setPen(QPen(Qt::black,1,Qt::SolidLine));
    //paint.drawEllipse(int(cent.x-rad), int(cent.y-rad), int(2*rad), int(2*rad));
    for(size_t i = 0; i < okr.size() - 1; i++)
    {
        paint.drawLine(int(okr[i].x), int(okr[i].y), int(okr[i+1].x), int(okr[i+1].y));
    }
}

void MainWindow::draw_grafic(QPainter &paint)
{

    for(size_t i = 0; i < points.size() - 1; i++)
    {
        paint.drawLine(int(points[i].x), int(points[i].y), int(points[i+1].x), int(points[i+1].y));
    }
    //paint.drawLine(int(i), int(f(i)), int(to), int(f(to)));
}

void MainWindow::on_perenos_button_clicked()
{
    points_prev = points;
    okr_prev = okr;
    QString x = ui->dx->text();
    QStringList u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->dx->clear();
        return;
    }
    double dx = u[0].toDouble();
    x = ui->dy->text();
    u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->dx->clear();
        return;
    }
    double dy = u[0].toDouble();

    for (size_t i = 0; i < points.size(); i++)
    {
        perenos(points[i], dx, dy);
    }
    for (size_t i = 0; i < okr.size(); i++)
    {
        perenos(okr[i], dx, dy);
    }

   update();
    //void perenos(p &a, double dx, double dy);
}

void MainWindow::on_mastab_buttob_clicked()
{
    points_prev = points;
    okr_prev = okr;
    //void mastab(p &a, double xm, double ym, double kx, double ky)
    QString x = ui->xm->text();
    QStringList u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->xm->clear();
        return;
    }
    double xm = u[0].toDouble();
    x = ui->ym->text();
    u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->ym->clear();
        return;
    }
    double ym = u[0].toDouble();

    x = ui->kx->text();
    u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->kx->clear();
        return;
    }
    double kx = u[0].toDouble();

    x = ui->ky->text();
    u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->ky->clear();
        return;
    }
    double ky = u[0].toDouble();

    for (size_t i = 0; i < points.size(); i++)
    {
        mastab(points[i], xm, ym, kx, ky);
    }
    for (size_t i = 0; i < okr.size(); i++)
    {
        mastab(okr[i], xm, ym, kx, ky);
    }
    update();
}

void MainWindow::on_povorot_button_clicked()
{
    points_prev = points;
    okr_prev = okr;
    //void povorot(p &a, double xc, double yc, double alpha)
    QString x = ui->xc->text();
    QStringList u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->xc->clear();
        return;
    }
    double xc = u[0].toDouble();
    x = ui->yc->text();
    u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->yc->clear();
        return;
    }
    double yc = u[0].toDouble();

    x = ui->alpha->text();
    u = x.split(" ", QString::SkipEmptyParts);
    if (u.count() != 1)
    {
        ui->alpha->clear();
        return;
    }
    double alpha = u[0].toDouble();

    for (size_t i = 0; i < points.size(); i++)
    {
        povorot(points[i], xc, yc, alpha);
    }
    for (size_t i = 0; i < okr.size(); i++)
    {
        povorot(okr[i], xc, yc, alpha);
    }
    update();
}

void MainWindow::on_return_one_button_clicked()
{
    points = points_prev;
    okr = okr_prev;
    update();
}

void MainWindow::on_pushButton_clicked()
{
    points.clear();
    okr.clear();
    init();
    update();
}
