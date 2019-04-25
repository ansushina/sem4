#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QColorDialog>
#include <QMessageBox>
#include <QPixmapCache>
#include <iostream>
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
    ui->draw_label->setPalette(color_background);
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
    if (ui->input_zatravka->isChecked())
    {
        int x = event->x();
        int y = event->y();

        if (x < 10 || y < 20 || x > 700 || y > 700)
            return;
        xz = x - OFFSET_X;
        yz = y - OFFSET_Y;
        zatravka_flag = true;
        painter->setPen(color_shading);
        painter->drawPoint(xz,yz);
        ui->draw_label->setPixmap(*scene);
        return;

    }
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
    scene = new QPixmap(851, 701);
    scene->fill(QColor(color_background));
    painter = new QPainter(scene);
    ui->draw_label->setPixmap(*scene);
    x_prev = -1;
    y_prev = -1;
    zatravka_flag = false;
    is_first = true;
}

void MainWindow::on_pushButton_2_clicked()
{
    if (is_first)
        return;
    painter->setPen(color_border);
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


void MainWindow::find_next(std::stack<point_t> &stack, int &x_left, int &x_right, const int &y)
{
    bool f = false;
    int x = x_left;
    int xn;
    while (x <= x_right)
    {
        f = false;
        QColor color = img.pixelColor(x,y);
        while (color != color_border && color != color_shading && x <= x_right)
        {
            f = true;
            x++;
            color = img.pixelColor(x,y);
        }
        if (f == true)
        {
            point_t p;
            p.x = x;
            p.y = y;
            if (x == x_right && img.pixelColor(x,y) != color_border && img.pixelColor(x,y) != color_shading)
            {
                stack.push(p);
            }
            else
            {
                p.x--;
                stack.push(p);
            }
        }

        xn = x;
        color = img.pixelColor(x,y);
        while ((color == color_border || color == color_shading) && x < x_right)
        {
            x++;
            color = img.pixelColor(x,y);
        }
        if (x == xn)
            x++;

    }

}

void MainWindow::on_main_button_clicked()
{
    if (!zatravka_flag)
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Не введен начальный пиксель. Введите начальный пиксель, чтобы продолжить.");
        mBox.exec();
        return;

    }
    if (!is_first)
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Фигура не замкнута. Пожалуйста, замкните фигуру.");
        mBox.exec();
        return;
    }

    img = scene->toImage();
    painter->setPen(color_shading);

    int x_left, x_right;

    std::stack<point_t> mystack;
    point_t z;
    z.x = xz;
    z.y = yz;
    mystack.push(z);

    while (!mystack.empty())
    {
        point_t p = mystack.top();
        mystack.pop();
        painter->drawPoint(p.x,p.y);
        //ui->draw_label->setPixmap(*scene);
        img = scene->toImage();
        int x = p.x + 1;
        int y = p.y;
        while(img.pixelColor(x,y) != color_border && x < 700)
        {
            painter->drawPoint(x,y);
            x++;
        }
        x_right = x-1;
        x = p.x-1;
        while(img.pixelColor(x,y) != color_border && x > 0)
        {
            painter->drawPoint(x,y);
            x--;
        }
        x_left = x+1;
        x = p.x;

        if (p.y < 700)
        {
            y = p.y+1;
            find_next(mystack, x_left, x_right, y);
        }
        if (p.y > 0)
        {
            y = p.y - 1;
            find_next(mystack, x_left, x_right, y);
        }

        if (ui->slow_Button->isChecked())
        {
            //Sleep(20);
            repaint();

        }
        ui->draw_label->setPixmap(*scene);
    }
}
