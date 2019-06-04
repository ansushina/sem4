#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QColorDialog>
#include <QMessageBox>
#include <QPixmapCache>
#include <iostream>
#include <QDebug>
//#include <windows.h>
#include <math.h>
#include <stack>
#include <stdlib.h>

#define OFFSET_X 10
#define OFFSET_Y 15

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->draw_label->setPalette(Qt::white);
    ui->draw_label->setMouseTracking(true);
    this->setMouseTracking(true);

    scene = new QPixmap(851, 701);
    scene->fill(QColor("transparent"));
    scene->fill(QColor(Qt::white));

    painter = new QPainter(scene);
    painter->setPen(QPen(Qt::black));

    ui->draw_label->setPixmap(*scene);

    QPalette Pal(palette());
    color_line = QColor(Qt::blue);


    Pal.setColor(QPalette::Background, Qt::blue);
    ui->frame_otr->setAutoFillBackground(true);
    ui->frame_otr->setPalette(Pal);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete painter;
    delete scene;
}

void MainWindow::on_pushButton_clicked()
{
    color_line = QColorDialog::getColor(Qt::blue, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_line);
    ui->frame_otr->setAutoFillBackground(true);
    ui->frame_otr->setPalette(Pal);
    ui->frame_otr->show();
}



void MainWindow::on_clear_button_clicked()
{

    delete painter;
    delete scene;
    ui->draw_label->clear();
    scene = new QPixmap(851, 701);
    scene->fill(QColor(Qt::white));
    painter = new QPainter(scene);
    ui->draw_label->setPixmap(*scene);
    fig_flag = false;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if (!fig_flag)
        return;

    if (event->key() == Qt::Key_S)
    {
        alphax -= 5;
    }
    else if (event->key() == Qt::Key_D)
    {
        alphay -= 5;
    }
    else if (event->key() == Qt::Key_A)
    {
        alphay += 5;
    }
    else if (event->key() == Qt::Key_W)
    {
        alphax += 5;
    }
    else if (event->key() == Qt::Key_E)
    {
        alphaz += 5;
    }
    else if (event->key() == Qt::Key_Z)
    {
        alphaz -= 5;
    }
    on_clear_button_clicked();
    params p(xbegin,xend,xdelta,ybegin,yend,ydelta);
    p.alphax =alphax;
    p.alphay = alphay;
    p.alphaz = alphaz;
    int i = ui->comboBox->currentIndex();
    p.func = Func.get_f(i);
    painter->setPen(color_line);
    horizon_alg(p,*painter);
    ui->draw_label->setPixmap(*scene);
    fig_flag = true;

}

void MainWindow::on_pushButton_3_clicked()
{
    painter->setPen(color_line);
    QString l_x = ui->xbegin->text();
    QString l_x1 = ui->xend->text();
    QString l_x2 = ui->dx->text();
     bool ok1 = true, ok2 = true, ok3 = true;
    int x = l_x.toDouble(&ok1);
    int x1 = l_x1.toDouble(&ok2);
    int x2 = l_x2.toDouble(&ok3);
    if (!ok1 || !ok2 || !ok3)
    {
        ui->xbegin->clear();
        ui->xend->clear();
        ui->dx->clear();
        return;
    }
    QString l_y = ui->ybegin->text();
    QString l_y1 = ui->yend->text();
    QString l_y2 = ui->dy->text();
    int y = l_y.toDouble(&ok1);
    int y1 = l_y1.toDouble(&ok2);
    int y2 = l_y2.toDouble(&ok3);
    if (!ok1 || !ok2 || !ok3)
    {
        ui->ybegin->clear();
        ui->yend->clear();
        ui->dy->clear();
        return;
    }

    xbegin = x;
    xend = x1;
    xdelta = x2;
    ybegin = y;
    yend = y1;
    ydelta = y2;

    on_clear_button_clicked();

    alphax = 0;
    alphay = 0;
    alphaz = 0;

    params p(xbegin,xend,xdelta,ybegin,yend,ydelta);
    p.alphax =alphax;
    p.alphay = alphay;
    p.alphaz = alphaz;
    int i = ui->comboBox->currentIndex();
    p.func = Func.get_f(i);
    painter->setPen(color_line);
    horizon_alg(p,*painter);
    ui->draw_label->setPixmap(*scene);
    fig_flag = true;

}


void MainWindow::on_pushButton_2_clicked()
{
    if (!fig_flag)
        return;
    int ax = ui->alphax->value();
    int ay = ui->alphay->value();
    int az = ui->alphay_2->value();

    on_clear_button_clicked();
    alphax += ax;
    alphay += ay;
    alphaz += az;
    params p(xbegin,xend,xdelta,ybegin,yend,ydelta);
    p.alphax =alphax;
    p.alphay = alphay;
    p.alphaz = alphaz;
    int i = ui->comboBox->currentIndex();
    p.func = Func.get_f(i);
    painter->setPen(color_line);
    horizon_alg(p,*painter);
    ui->draw_label->setPixmap(*scene);
    fig_flag = true;
}