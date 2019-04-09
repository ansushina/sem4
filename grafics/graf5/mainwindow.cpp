#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QColorDialog>
#include <QMessageBox>
#include <QPixmapCache>
#include <iostream>
//#include <windows.h>
#include <math.h>

#define OFFSET_X 10
#define OFFSET_Y 20

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->draw_label->setPalette(color_background);
    ui->draw_label->setMouseTracking(true);
    this->setMouseTracking(true);

    scene = new QPixmap(851, 691);
    scene->fill(QColor("transparent"));
    scene->fill(QColor(Qt::white));

    painter = new QPainter(scene);
    painter->setPen(QPen(Qt::black));

    ui->draw_label->setPixmap(*scene);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);

    ui->frame_border->setAutoFillBackground(true);
    ui->frame_border->setPalette(Pal);

    Pal.setColor(QPalette::Background, Qt::red);
    ui->frame_shading->setAutoFillBackground(true);
    ui->frame_shading->setPalette(Pal);
    color_shading = QColor(Qt::red);

    color_background = QColor(Qt::white);
    color_border = QColor(Qt::black);

    Pal.setColor(QPalette::Background, Qt::white);
    ui->frame_background->setAutoFillBackground(true);
    ui->frame_background->setPalette(Pal);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete painter;
    delete scene;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (!ui->mouse_input->isChecked())
    {
        return;
    }

    int x = event->x();
    int y = event->y();

    if (x < 10 || y < 20 || x > 700 || y > 700)
        return;

    painter->setPen(color_border);

    if (is_first)
    {
        x0 = x;
        y0 = y;
        x_prev = x;
        y_prev = y;
        is_first = false;
        //painter->drawPoint(x,y);
        //
        //return;
    }

    line_t l;
    l.x1 = x_prev;
    l.y1 = y_prev;
    l.x2 = x;
    l.y2 = y;

    line.push_back(l);

    x_prev = x;
    y_prev = y;

    ui->draw_label->setPixmap(*scene);
}

void MainWindow::on_pushButton_clicked()
{
    color_border = QColorDialog::getColor(Qt::black, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_border);
    ui->frame_border->setAutoFillBackground(true);
    ui->frame_border->setPalette(Pal);
    ui->frame_border->show();
}

void MainWindow::on_shading_button_clicked()
{
    color_shading = QColorDialog::getColor(Qt::red, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_shading);
    ui->frame_shading->setAutoFillBackground(true);
    ui->frame_shading->setPalette(Pal);
    ui->frame_shading->show();
}

void MainWindow::on_background_button_clicked()
{
    color_background = QColorDialog::getColor(Qt::white, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_background);
    ui->frame_background->setAutoFillBackground(true);
    ui->frame_background->setPalette(Pal);
    ui->frame_background->show();
}

void MainWindow::on_clear_button_clicked()
{
    delete painter;
    delete scene;
    edges.clear();
    ui->draw_label->clear();
    scene = new QPixmap(851, 691);
    scene->fill(QColor(color_background));
    painter = new QPainter(scene);
    ui->draw_label->setPixmap(*scene);
    prev_x = -1;
    prev_y = -1;
}
