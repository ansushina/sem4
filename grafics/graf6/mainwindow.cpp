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
    ui->fast_button->setChecked(true);
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
    QImage image = scene->toImage();

    painter->drawLine(x_prev,y_prev, x - OFFSET_X, y - OFFSET_Y);

    x_prev = x - OFFSET_X;
    y_prev = y - OFFSET_Y;

    ui->draw_label->setPixmap(*scene);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (ui->mouse_random_input->isChecked())
    {
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

        painter->drawLine(x_prev,y_prev, x - OFFSET_X, y - OFFSET_Y);

        x_prev = x - OFFSET_X;
        y_prev = y - OFFSET_Y;

        ui->draw_label->setPixmap(*scene);
    }
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
    /*scene->fill(QColor(color_background));
    painter->setPen(color_border);
    for (size_t i = 0; i < line.size(); i++)
    {
        painter->drawLine(line[i].x1, line[i].y1, line[i].x2, line[i].y2);
    }
    ui->draw_label->setPixmap(*scene);*/
}

void MainWindow::on_clear_button_clicked()
{
    delete painter;
    delete scene;
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
    painter->drawLine(x_prev, y_prev, x0, y0);
    x_prev = -1;
    y_prev = -1;
    is_first = true;

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

    painter->drawLine(x_prev, y_prev, x, y);
    ui->draw_label->setPixmap(*scene);

    x_prev = x;
    y_prev = y;
}

void MainWindow::on_main_button_clicked()
{
    if (!is_first)
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Фигура не замкнута. Пожалуйста, замкните фигуру.");
        mBox.exec();

        return;
    }

    /*if (line.size() <= 2)
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Недостаточно ребер.");
        mBox.exec();
        return;
    }*/

/*    int x_max = line[0].x1;

    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i].x1 > x_max)
            x_max = line[i].x1;
    }

    for (size_t i = 0; i < line.size(); i++)
    {
        QImage image = scene->toImage();

        int x1 = line[i].x1;
        int x2 = line[i].x2;
        int y1 = line[i].y1;
        int y2 = line[i].y2;

        if (y1 > y2)
        {
            int tmp = y2;
            y2 = y1;
            y1 = tmp;
            tmp = x2;
            x2 = x1;
            x1 = tmp;
        }
        else if (y1 == y2)
            continue;

        double dx = (x2 - x1)/(double)(y2-y1);
        double xstart = x1;
        for (int y = y1; y < y2; y++)
        {
            for (int x = round(xstart); x <= x_max; x++)
            {

                QColor color = image.pixelColor(x,y);
                if (color == color_background)
                {
                    painter->setPen(color_shading);
                }
                else if (color == color_shading)
                {
                    painter->setPen(color_background);
                }
                else
                {
                    painter->setPen(color_border);
                }
                painter->drawPoint(x,y);
            }
            xstart += dx;

            if (ui->slow_Button->isChecked())
                repaint();

            ui->draw_label->setPixmap(*scene);
        }
    }*/
}
