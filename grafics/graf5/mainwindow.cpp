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

    ui->mouse_input->setChecked(true);
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
        x0 = x - OFFSET_X;
        y0 = y - OFFSET_Y;
        x_prev = x - OFFSET_X;
        y_prev = y - OFFSET_Y;
        is_first = false;
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

    line.push_back(l);

    QImage image = scene->toImage();

    //if (image.pixelColor(QPoint(l1.x, l1.y)) != color_border)

    painter->drawEllipse(l.x2,l.y2,1,1);
    painter->drawLine(l.x1, l.y1, l.x2, l.y2);

    x_prev = x - OFFSET_X;
    y_prev = y - OFFSET_Y;

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
    scene->fill(QColor(color_background));
    ui->draw_label->setPixmap(*scene);
}

void MainWindow::on_clear_button_clicked()
{
    delete painter;
    delete scene;
    line.clear();
    ui->draw_label->clear();
    scene = new QPixmap(851, 691);
    scene->fill(QColor(color_background));
    painter = new QPainter(scene);
    ui->draw_label->setPixmap(*scene);
    x_prev = -1;
    y_prev = -1;
    is_first = true;
}

void MainWindow::on_pushButton_2_clicked()
{
    if (is_first)
        return;
    line_t l;
    l.x1 = x_prev;
    l.y1 = y_prev;
    l.x2 = x0;
    l.y2 = y0;

    line.push_back(l);

    x_prev = -1;
    y_prev = -1;
    is_first = true;

    painter->drawLine(l.x1, l.y1, l.x2, l.y2);
    ui->draw_label->setPixmap(*scene);
}

void MainWindow::on_new_point_button_clicked()
{
    if (!ui->button_input->isChecked())
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Выберите кнопку 'Клавиатурный ввод' чтобы иметь возмжность вводить точки.");
        mBox.exec();
    }
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

    painter->setPen(color_border);

    if (is_first)
    {
        x0 = x;
        y0 = y;
        x_prev = x;
        y_prev = y;
        is_first = false;
        painter->drawEllipse(x,y,1,1);
        ui->draw_label->setPixmap(*scene);
        return;
    }

    line_t l;
    l.x1 = x_prev;
    l.y1 = y_prev;
    l.x2 = x;
    l.y2 = y;

    line.push_back(l);

    painter->drawEllipse(l.x2,l.y2,1,1);
    painter->drawLine(l.x1, l.y1, l.x2, l.y2);
    ui->draw_label->setPixmap(*scene);

    x_prev = x;
    y_prev = y;
}

void MainWindow::on_main_button_clicked()
{
    if (!is_first)
        return;

    if (line.size() <= 2)
        return;

    QImage image = scene->toImage();

    int x_max;
    int x_min;
    int y_max;
    int y_min;

    for (int i = 0; i < line.size; i++)
    {
        if (line[i].x1 < x_min)
            x_min = line[i].x1;
        if (line[i].x1 > x_max)
            x_max = line[i].x1;
        if (line[i].y1 < y_min)
            y_min = line[i].y1;
        if (line[i].y1 < y_max)
            y_max = line[i].y1
    }
}
