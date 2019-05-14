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

#define OFFSET_X 10
#define OFFSET_Y 20

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
    Pal.setColor(QPalette::Background, Qt::black);

    ui->frame_otr->setAutoFillBackground(true);
    ui->frame_otr->setPalette(Pal);

    Pal.setColor(QPalette::Background, Qt::red);
    ui->frame_ots->setAutoFillBackground(true);
    ui->frame_ots->setPalette(Pal);
    color_ots = QColor(Qt::red);

    color_line = QColor(Qt::blue);
    color_otr = QColor(Qt::black);

    Pal.setColor(QPalette::Background, Qt::blue);
    ui->frame_line->setAutoFillBackground(true);
    ui->frame_line->setPalette(Pal);

    ui->input_otsek->setChecked(true);
    //ui->fast_button->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete painter;
    delete scene;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if (x < 10 || y < 20 || x > 700 || y > 700)
        return;
    if (ui->input_line->isChecked())
    {
        painter->setPen(color_otr);
        if (event->modifiers() == Qt::ShiftModifier)
        {
            if (fabs(x - OFFSET_X - x0) < fabs(y - OFFSET_Y- y0))
            {
                x = x0 + OFFSET_X;
            }
            else
            {
                y = y0 + OFFSET_Y;
            }

        }
        if (is_first)
        {
            x0 = x - OFFSET_X;
            y0 = y - OFFSET_Y;
            is_first = false;
            painter->drawEllipse(x0,y0, 1,1);
            ui->draw_label->setPixmap(*scene);
            return;
        }
        else
        {
            is_first = true;
            draw_line(x0,y0,x - OFFSET_X,y - OFFSET_Y);
            line_t line(x0,x - OFFSET_X,y0,y - OFFSET_Y);
            lines.push_back(line);
            return;
        }

    }
    if (!ui->input_otsek->isChecked())
    {
        return;
    }

    painter->setPen(color_ots);

    if (is_start_ots)
    {
        on_pushButton_2_clicked();
        x0 = x - OFFSET_X;
        y0 = y - OFFSET_Y;
        x_prev = x - OFFSET_X;
        y_prev = y - OFFSET_Y;
       // is_first = false;
        is_start_ots = false;
        painter->drawEllipse(x-OFFSET_X,y-OFFSET_Y,1,1);
        ui->draw_label->setPixmap(*scene);
        return;
    }

    if (event->modifiers() == Qt::ShiftModifier)
    {
        if (fabs(x - OFFSET_X - x_prev) < fabs(y - OFFSET_Y- y_prev))
        {
            x = x_prev + OFFSET_X;
        }
        else
        {
            y = y_prev + OFFSET_Y;
        }

    }

    line_t l;
    l.x1 = x_prev;
    l.y1 = y_prev;
    l.x2 = x - OFFSET_X;
    l.y2 = y - OFFSET_Y;

    egles.push_back(l);

    painter->drawLine(l.x1, l.y1, l.x2, l.y2);
    x_prev = x - OFFSET_X;
    y_prev = y - OFFSET_Y;

    ui->draw_label->setPixmap(*scene);

   /* x_prev = x - OFFSET_X;
    y_prev = y - OFFSET_Y;

    ui->draw_label->setPixmap(*scene);

    painter->setPen(color_ots);
    if (is_start_ots)
    {
        on_pushButton_2_clicked();
        x_up = x - OFFSET_X;
        y_up = y - OFFSET_Y;
        is_start_ots = false;

        painter->drawEllipse(x - OFFSET_X,y - OFFSET_Y,1,1);
        ui->draw_label->setPixmap(*scene);
        return;
    }

    painter->setPen(color_ots);

    x_down = x - OFFSET_X;
    y_down = y - OFFSET_Y;
    is_start_ots = true;
    draw_rect(x_up,y_up, x_down, y_down);
    return;*/
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
}

void MainWindow::on_pushButton_clicked()
{
    color_otr = QColorDialog::getColor(Qt::black, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_otr);
    ui->frame_otr->setAutoFillBackground(true);
    ui->frame_otr->setPalette(Pal);
    ui->frame_otr->show();
}

void MainWindow::on_shading_button_clicked()
{
    color_ots = QColorDialog::getColor(Qt::red, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_ots);
    ui->frame_ots->setAutoFillBackground(true);
    ui->frame_ots->setPalette(Pal);
    ui->frame_ots->show();
}

void MainWindow::on_background_button_clicked()
{
    color_line = QColorDialog::getColor(Qt::white, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_line);
    ui->frame_line->setAutoFillBackground(true);
    ui->frame_line->setPalette(Pal);
    ui->frame_line->show();
}

void MainWindow::on_clear_button_clicked()
{
    lines.clear();
    egles.clear();
    delete painter;
    delete scene;
    ui->draw_label->clear();
    scene = new QPixmap(851, 701);
    scene->fill(QColor(Qt::white));
    painter = new QPainter(scene);
    ui->draw_label->setPixmap(*scene);
    is_first = true;
    line_flag = false;
    rect_flag = false;
    is_start_ots = true;

}

void MainWindow::on_pushButton_2_clicked()
{

    if (1)
    {
        rect_flag = false;
        delete painter;
        delete scene;
        egles.clear();
        ui->draw_label->clear();
        scene = new QPixmap(851, 701);
        scene->fill(QColor(Qt::white));
        painter = new QPainter(scene);
        ui->draw_label->setPixmap(*scene);
        for (size_t i = 0; i < lines.size(); i++)
        {
            draw_line(lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2);
        }
        is_start_ots = true;

    }
    ui->draw_label->setPixmap(*scene);
}

void MainWindow::draw_line(double x1, double y1, double x2, double y2)
{
    painter->drawLine(x1,y1,x2,y2);
    line_flag = true;
    ui->draw_label->setPixmap(*scene);
}

void MainWindow::draw_rect(int x1, int y1, int x2, int y2)
{
    int xmax = x1>x2?x1:x2;
    int xmin = x1>x2?x2:x1;
    int ymax = y1>y2?y1:y2;
    int ymin = y1>y2?y2:y1;
    rect_flag = true;
    painter->drawRect(xmin,ymin,xmax-xmin, ymax-ymin);
    ui->draw_label->setPixmap(*scene);
}

void MainWindow::on_new_point_button_clicked()
{
    QString l_x = ui->x_lineedit->text();
    QString l_y = ui->y_lineedit->text();
    bool ok1 = true, ok2 = true;
    int x = l_x.toDouble(&ok1);
    int y = l_y.toDouble(&ok2);
    if (!ok1 || !ok2)
    {
        ui->x_lineedit->clear();
        ui->y_lineedit->clear();
        return;
    }
    if (x < 0 || y < 0 || x > 700 || y > 700)
        return;
    painter->setPen(color_otr);
    if (ui->input_line->isChecked())
    {
        painter->setPen(color_otr);
        if (is_first)
        {
            x0 = x;
            y0 = y;
            is_first = false;
            painter->drawEllipse(x,y, 1,1);
            ui->draw_label->setPixmap(*scene);
            return;
        }
        else
        {
            is_first = true;
            draw_line(x0,y0,x,y);
            line_t line(x0,x,y0,y);
            lines.push_back(line);
            return;
        }

    }
    if (!ui->input_otsek->isChecked())
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
       // mBox.setInformativeText("Выберите кнопку 'Клавиатурный ввод' чтобы иметь возмжность вводить точки.");
        mBox.exec();
    }


    painter->setPen(color_ots);

    if (is_start_ots)
    {
        on_pushButton_2_clicked();
        x0 = x;
        y0 = y;
        x_prev = x;
        y_prev = y;

        is_start_ots = false;
        painter->drawEllipse(x,y,1,1);
        ui->draw_label->setPixmap(*scene);
        return;
    }

    line_t l;
    l.x1 = x_prev;
    l.y1 = y_prev;
    l.x2 = x;
    l.y2 = y;

    egles.push_back(l);

    painter->drawLine(l.x1, l.y1, l.x2, l.y2);
    x_prev = x;
    y_prev = y;

    ui->draw_label->setPixmap(*scene);
}


void set_bits(int xmax, int xmin, int ymax, int ymin, int x, int y, int *arr)
{
    arr[3] = x < xmin ? 1:0;
    arr[2] = x > xmax ? 1:0;
    arr[1] = y < ymin ? 1:0;
    arr[0] = y > ymax ? 1:0;
}

int get_sum(int *arr, int n)
{
    int sum = 0;
    for(int i = 0;i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int get_p(int *arr1, int *arr2, int n)
{
    int sum = 0;
    for(int i = 0;i < n; i++)
    {
        sum += arr1[i]*arr2[i];
    }
    return sum;
}
void MainWindow::on_main_button_clicked()
{

    if (!is_first)
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Отрезок не дорисован.");
        mBox.exec();
        return;
    }
    if (!line_flag || !rect_flag)
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Недостаточно данных. Введите отрезок и отсекатель");
        mBox.exec();
        return;
    }

    painter->setPen(QPen(color_line,2));

    int obhod;
    if(!is_convex(egles, obhod))
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Невыпуклый многоугольник.");
        mBox.exec();
        return;
    }
    for (int i = 0 ; i < lines.size(); i++)
    {
        point p1(lines[i].x1,lines[i].y1);
        point p2(lines[i].x2,lines[i].y2);
        alg(p2,p1,obhod,egles,*painter);
        ui->draw_label->setPixmap(*scene);
    }

    painter->setPen(QPen(color_line,1));

}

void MainWindow::on_pushButton_3_clicked()
{
    if (is_start_ots)
        return;
    if (egles.size() < 2)
        return;
    if (egles.back().x1 == x0 && egles.back().y1 == y0)
        return;
    line_t l;
    l.x1 = x_prev;
    l.y1 = y_prev;
    l.x2 = x0;
    l.y2 = y0;

    egles.push_back(l);

    x_prev = -1;
    y_prev = -1;
    //is_first = true;
    is_start_ots = true;
    rect_flag = true;

    painter->drawLine(l.x1, l.y1, l.x2, l.y2);
    ui->draw_label->setPixmap(*scene);

}
