
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
//#include <qpainter.h>
//#include <QPainter>
#include <QMessageBox>
#include <iostream>
#include <QColor>
#include <QColorDialog>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    color(Qt::black),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QRegExp check ("[-+]?(\\d+(\\.\\d*)?|\\.\\d+)$");
    QRegExpValidator *my_double_validator = new QRegExpValidator(check, this);
    ui->x1->setValidator(my_double_validator);
    ui->x2->setValidator(my_double_validator);
    ui->y1->setValidator(my_double_validator);
    ui->y2->setValidator(my_double_validator);
    //ui->but_exec->setEnabled(false);


    connect(ui->x1, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->x2, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->y1, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->y2, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    ui->frame->setAutoFillBackground(true);
    ui->frame->setPalette(Pal);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cda(QPen pen)
{
    scene->addEllipse(x1, y1, 0.1, 0.1, pen, QBrush(Qt::SolidPattern));
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
        scene->addEllipse(round(x), round(y), 0.1, 0.1, pen, QBrush(Qt::SolidPattern));
        x += sx;
        y += sy;
    }
}

#define EPS 0.00000001
int s(int x)
{
    if (x > 0)
        return 1;
    if (x == 0)
        return 0;
    return -1;
}

void MainWindow::br_1(QPen pen)
{
    int x = x1;
    int y = y1;
    int dx = x2-x1;
    int dy = y2-y1;
    int sx = s(dx);
    int sy = s(dy);
    dx = fabs(dx);
    dy = fabs(dy);
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
    double m = ((double)dy)/dx;
    double l = m - 0.5;
    for (int i = 0; i <= dx; i++)
    {
        scene->addEllipse(x, y, 0.1, 0.1, pen, QBrush(Qt::SolidPattern));
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

void MainWindow::br_2(QPen pen)
{
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
        scene->addEllipse(x, y, 0.1, 0.1, pen, QBrush(Qt::SolidPattern));
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

void MainWindow::br_3(QPen pen)
{
    int I = 255;
    int x = x1;
    int y = y1;
    int dx = x2-x1;
    int dy = y2-y1;
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
    double m = ((double)dy)/dx;
    m = m * I;
    double l = I*0.5;
    double W = I - m;
    QColor col = pen.color();
   // col.setAlphaF(l);
    scene->addEllipse(x, y, 0.1, 0.1, pen, QBrush(Qt::SolidPattern));

    for (int i = 0; i < dx; i++)
    {
        //paint.d
        if (l <= W)
        {
            if (obmen == 0)
                x += sx;
            else
                y += sy;
            l += m;
        }
        else if (l > W)
        {
            x += sx;
            y += sy;
            l -= W;
        }
        col.setAlphaF(1 - (l / I));
        scene->addEllipse(x, y, 0.1, 0.1, QPen(col,1,Qt::SolidLine), QBrush(Qt::SolidPattern));
    }
}

void MainWindow::method()
{
    if (ui->radioButton_1->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             cda(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             cda(QPen(Qt::white,1,Qt::SolidLine));
        }
        else
        {
            QMessageBox mBox;
            mBox.setIcon(QMessageBox::Information);
            mBox.setInformativeText("Choose color");
            mBox.exec();

        }
    }
    else if (ui->radioButton_2->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             br_1(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            br_1(QPen(Qt::white,1,Qt::SolidLine));

        }
        else
        {
            QMessageBox mBox;
            mBox.setIcon(QMessageBox::Information);
            mBox.setInformativeText("Choose color");
            mBox.exec();

        }
    }
    else if (ui->radioButton_3->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
            br_2(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             br_2(QPen(Qt::white,1,Qt::SolidLine));
        }
        else
        {
            QMessageBox mBox;
            mBox.setIcon(QMessageBox::Information);
            mBox.setInformativeText("Choose color");
            mBox.exec();

        }
    }
    else if (ui->radioButton_4->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
            br_3(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             br_3(QPen(Qt::white,1,Qt::SolidLine));
        }
        else
        {
            QMessageBox mBox;
            mBox.setIcon(QMessageBox::Information);
            mBox.setInformativeText("Choose color");
            mBox.exec();

        }
    }
    else if (ui->radioButton_5->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
            scene->addLine(x1, y1, x2, y2, QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            scene->addLine(x1, y1, x2, y2, QPen(Qt::white,1,Qt::SolidLine));
        }
        else
        {
            QMessageBox mBox;
            mBox.setIcon(QMessageBox::Information);
            mBox.setInformativeText("Choose color");
            mBox.exec();

        }
    }
    else
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Choose method");
        mBox.exec();
    }
}

void MainWindow::on_draw_clicked()
{
    QString l_x1 = ui->x1->text();
    QString l_x2 = ui->x2->text();
    QString l_y1 = ui->y1->text();
    QString l_y2 = ui->y2->text();
    QStringList u_x1 = l_x1.split(" ", QString::SkipEmptyParts);
    QStringList u_x2 = l_x2.split(" ", QString::SkipEmptyParts);
    QStringList u_y1 = l_y1.split(" ", QString::SkipEmptyParts);
    QStringList u_y2 = l_y2.split(" ", QString::SkipEmptyParts);

    if (u_x1.count() != 1)
    {
        ui->x1->clear();
        return;
    }
    if (u_x2.count() != 1)
    {
        ui->x2->clear();
        return;
    }
    if (u_y1.count() != 1)
    {
        ui->y2->clear();
        return;
    }
    if (u_y2.count() != 1)
    {
        ui->y2->clear();
        return;
    }

    x1 = u_x1[0].toDouble();
    y1 = u_y1[0].toDouble();
    x2 = u_x2[0].toDouble();
    y2 = u_y2[0].toDouble();

    if (x1 == x2 && y1 == y2)
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Вырожденный отрезок!");
        mBox.exec();
        return;
    }


    method();

    update();
}

void MainWindow::on_choose_color_clicked()
{
    color = QColorDialog::getColor();
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color);
    ui->frame->setAutoFillBackground(true);
    ui->frame->setPalette(Pal);
    ui->frame->show();
}

void MainWindow::on_clean_but_clicked()
{
    scene->clear();
}

void MainWindow::on_wiz_button_clicked()
{

   // on_clean_but_clicked();

    QString l_x1 = ui->x1->text();
    QString l_x2 = ui->x2->text();
    QString l_y1 = ui->y1->text();
    QString l_y2 = ui->y2->text();
    QStringList u_x1 = l_x1.split(" ", QString::SkipEmptyParts);
    QStringList u_x2 = l_x2.split(" ", QString::SkipEmptyParts);
    QStringList u_y1 = l_y1.split(" ", QString::SkipEmptyParts);
    QStringList u_y2 = l_y2.split(" ", QString::SkipEmptyParts);

    if (u_x1.count() != 1)
    {
        ui->x1->clear();
        return;
    }
    if (u_x2.count() != 1)
    {
        ui->x2->clear();
        return;
    }
    if (u_y1.count() != 1)
    {
        ui->y2->clear();
        return;
    }
    if (u_y2.count() != 1)
    {
        ui->y2->clear();
        return;
    }

    x1 = u_x1[0].toDouble();
    y1 = u_y1[0].toDouble();
    x2 = u_x2[0].toDouble();
    y2 = u_y2[0].toDouble();

    if (x1 == x2 && y1 == y2)
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Вырожденный отрезок!");
        mBox.exec();
        return;
    }

    int mx1 = x1;
    int mx2 = x2;
    int my1 = y1;
    int my2 = y2;
    double xc = ((double)(x2+x1))/2;
    double yc = ((double)(y2+y1))/2;


    for (int alpha = 0; alpha < 180; alpha +=10)
    {
        double distance1 = sqrt(pow(fabs(x1 - x2), 2) + pow(fabs(y1 - y2),2));
        cout << distance1 << endl;
        cout << x2<<" "<<y2<<endl;
        x1 = xc + (mx1 - xc) * cos(alpha * PI / 180) + (my1 - yc) * sin(alpha * PI / 180);
        y1 = yc - (mx1 - xc) * sin(alpha * PI / 180) + (my1 - yc) * cos(alpha * PI / 180);
        x2 = xc + (mx2 - xc) * cos(alpha * PI / 180) + (my2 - yc) * sin(alpha * PI / 180);
        y2 = yc - (mx2 - xc) * sin(alpha * PI / 180) + (my2 - yc) * cos(alpha * PI / 180);

        method();
    }

}
