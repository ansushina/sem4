#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <math.h>
#include <iostream>
#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // scene = new QGraphicsScene(this);
    //ui->graphicsView->setScene(scene);
    ui->draw_label->setStyleSheet("QLabel { background-color : white; }");


    scene = new QPixmap(851, 691);
    scene->fill(QColor("transparent"));
    painter = new QPainter(scene);
   // painter->drawLine(100,100,500,500);
    //update();
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    ui->frame->setAutoFillBackground(true);
    ui->frame->setPalette(Pal);
    QPalette Pal2(palette());
    Pal2.setColor(QPalette::Background, Qt::white);
    ui->frame_3->setAutoFillBackground(true);
    ui->frame_3->setPalette(Pal2);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete painter;
    delete scene;
}

#include <math.h>

void MainWindow::traditional_okr(QPen pen)
{

    //double dx = r;
   // double dy = r;
  //  double l = r;
   //
   // double sx = dx/l;
   // double sy = dy/l;
    painter->setPen(pen);
    double x = 0;
    double y = r;

    while (x <= r)
    {

        y = sqrt(r*r-x*x);
        //scene->addEllipse(round(x)+xc,round(y)+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
        painter->drawPoint(int(round(x)+xc), int(round(y)+yc));
        painter->drawPoint(int(-round(x)+xc), int(round(y)+yc));
        painter->drawPoint(int(round(x)+xc), int(-round(y)+yc));
        painter->drawPoint(int(-round(x)+xc), int(-round(y)+yc));
        x++;

    }
    y=r;
    while (y >= 0)
    {
        y--;
        x = sqrt(r*r-y*y);
        //scene->addEllipse(round(x)+xc,round(y)+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
        painter->drawPoint(int(round(x)+xc), int(round(y)+yc));
        painter->drawPoint(int(-round(x)+xc), int(round(y)+yc));
        painter->drawPoint(int(round(x)+xc), int(-round(y)+yc));
        painter->drawPoint(int(-round(x)+xc), int(-round(y)+yc));

    }
}

void MainWindow::parametr_okr(QPen pen)
{
    // x = r*cos(t);
    // y = r*sin(t);
    painter->setPen(pen);

    double x = 0;
    double y = r;
    int i = 0;
    for (double t = 0; t <= 3.1415926535/2; t += 1/r)
    {
        i++;
        std::cout<<i<<" "<< t <<" "<< x << " " << y <<std::endl;
        //scene->addEllipse(round(x)+xc,round(y)+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
        painter->drawPoint(int(round(x)+xc), int(round(y)+yc));
        painter->drawPoint(int(-round(x)+xc), int(round(y)+yc));
        painter->drawPoint(int(round(x)+xc), int(-round(y)+yc));
        painter->drawPoint(int(-round(x)+xc), int(-round(y)+yc));
        x = r*cos(t);
        y = r*sin(t);
    }
}

void MainWindow::brezenhem_okr(QPen pen)
{

    painter->setPen(pen);
    int x = 0;
    int y =int(r);
    int di = int(2*(1-r));

    while (x <= r && y >= 0)
    {

        //scene->addEllipse(x+xc,y+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
        painter->drawPoint(x+xc, y+yc);
        painter->drawPoint(-x+xc, y+yc);
        painter->drawPoint(x+xc, -y+yc);
        painter->drawPoint(-x+xc, -y+yc);
        if (di < 0)
        {
            //vnutri
            //диагональный или горизонтальный
            int d1 = 2*di + 2*y -1;
            if (d1 < 0)
            {
                // горизонт
                x++;
                di = di+2*x +1;
            }
            else
            {
                //диагональ
                x++;
                y--;
                di += 2*(x-y+1);
            }
        }
        else if (di == 0)
        {
            //na
            //выбираем диагональный
            x++;
            y--;
            di += 2*(x-y+1);
        }
        else
        {
            //snaruzi
            //диагональный или вертикальный
            int d2 = 2*di-2*x-1;
            if (d2 < 0)
            {
                // диагональный
                x++;
                y--;
                di += 2*(x-y+1);

            }
            else
            {
                // вертикальный
                y--;
                di = di - 2*y+1;
            }
        }
    }
}

void MainWindow::traditional_el(QPen pen)
{

    painter->setPen(pen);
    double x = 0;
    double y = 0;

    while (x <=a)
    {

        y = round(b*sqrt(1-x*x/a/a));
        //scene->addEllipse(round(x)+xc,round(y)+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
        painter->drawPoint(int(round(x)+xc), int(round(y)+yc));
        painter->drawPoint(int(-round(x)+xc), int(round(y)+yc));
        painter->drawPoint(int(round(x)+xc), int(-round(y)+yc));
        painter->drawPoint(int(-round(x)+xc), int(-round(y)+yc));
        x++;

    }
    y=0;
    while (y <= b)
    {

        x = round(a*sqrt(-y*y/b/b));
        //scene->addEllipse(round(x)+xc,round(y)+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
        painter->drawPoint(int(round(x)+xc), int(round(y)+yc));
        painter->drawPoint(int(-round(x)+xc), int(round(y)+yc));
        painter->drawPoint(int(round(x)+xc), int(-round(y)+yc));
        painter->drawPoint(int(-round(x)+xc), int(-round(y)+yc));
        y++;

    }
}

void MainWindow::parametr_el(QPen pen)
{
    painter->setPen(pen);

    double x = 0;
    double y = b;
    int i = 0;
    double max = a>b? a:b;
    for (double t = 0; t <= 3.1415926535/2; t += 1/max)
    {
        i++;
        std::cout<<i<<" "<< t <<" "<< x << " " << y <<std::endl;
        //scene->addEllipse(round(x)+xc,round(y)+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
        /*painter->drawPoint(int(round(x)+xc), int(round(y)+yc));
        painter->drawPoint(int(-round(x)+xc), int(round(y)+yc));
        painter->drawPoint(int(round(x)+xc), int(-round(y)+yc));
        painter->drawPoint(int(-round(x)+xc), int(-round(y)+yc));*/

        painter->drawPoint(x+xc, y+yc);
        painter->drawPoint(-x+xc, y+yc);
        painter->drawPoint(x+xc, -y+yc);
        painter->drawPoint(-x+xc, -y+yc);
        x = round(a*cos(t));
        y = round(b*sin(t));
    }
}

void MainWindow::brezenhem_el(QPen pen)
{

    painter->setPen(pen);
    int x = 0;
    int y =int(b);
    int end_y = 0;
    int a2 = a*a;
    int b2 = b*b;
    int di = int(a2 + b2 - 2 * a2 * y);

    while (y >= end_y)
    {

        //scene->addEllipse(x+xc,y+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
        painter->drawPoint(x+xc, y+yc);
        painter->drawPoint(-x+xc, y+yc);
        painter->drawPoint(x+xc, -y+yc);
        painter->drawPoint(-x+xc, -y+yc);
        if (di < 0)
        {
            //vnutri
            //диагональный или горизонтальный
            int d1 = 2 * di + 2 * a2 * y - 1;
            if (d1 < 0)
            {
                // горизонт
                x++;
                di = di + 2 * b2 * x + b2;
            }
            else
            {
                //диагональ
                x++;
                y--;
                di +=  2 * b2 * x + b2 + a2 - 2 * a2 * y;
            }
        }
        else if (di == 0)
        {
            //na
            //выбираем диагональный
            x++;
            y--;
            di +=  2 * b2 * x + b2 + a2 - 2 * a2 * y;
        }
        else
        {
            //snaruzi
            //диагональный или вертикальный
            int d2 = 2*di-2*x-1;
            if (d2 < 0)
            {
                // диагональный
                x++;
                y--;
                di +=  2 * b2 * x + b2 + a2 - 2 * a2 * y;

            }
            else
            {
                // вертикальный
                y--;
                di = di - 2 * a2 * y + a2;
            }
        }
    }
}

void MainWindow::standart_okr(QPen pen)
{
     painter->setPen(pen);
     painter->drawEllipse(xc-r,yc-r,2*r,2*r);
}

void MainWindow::standart_el(QPen pen)
{
     painter->setPen(pen);
     painter->drawEllipse(xc-a,yc-b,2*a,2*b);
}

void MainWindow::sr_point_okr(QPen pen)
{
    painter->setPen(pen);
    int r2 = r*r;
    int x = 0;
    int y = r;
    int rd2 = round(r/sqrt(2));

    int f = (r2-r2*y + 0.25*r2 + 0.5);
    int df = 0;
    int delta = -2*r2 * y;

    while(x <= rd2)
    {
        painter->drawPoint(x+xc, y+yc);
        painter->drawPoint(-x+xc, y+yc);
        painter->drawPoint(x+xc, -y+yc);
        painter->drawPoint(-x+xc, -y+yc);

        x++;
        if (f >= 0)
        {
            y--;
            delta += 2*r2;
            f += delta;
        }
        df +=2*r2;
        f += df +r2;
    }
    delta = 2*r2*x;
    f+= -r2 *(x+y);
    df = -2*r2*y;
    while(y>= 0)
    {
        painter->drawPoint(x+xc, y+yc);
        painter->drawPoint(-x+xc, y+yc);
        painter->drawPoint(x+xc, -y+yc);
        painter->drawPoint(-x+xc, -y+yc);
        y--;
        if (f < 0)
        {
            x++;
            delta += 2*r2;
            f += delta;
        }
        df += 2*r2;
        f += df +r2;
    }
}

void MainWindow::sr_point_el(QPen pen)
{
    painter->setPen(pen);
    int a2 = a*a;
    int b2 = b*b;
    int x = 0;
    int y = b;
    int rd2 = a2/sqrt(a2+b2);

    int f = (b2 - a2 * y + 0.25 * a2 + 0.5);
    int df = 0;
    int delta = -2*a2 * y;

    while(x <= rd2)
    {
        painter->drawPoint(x+xc, y+yc);
        painter->drawPoint(-x+xc, y+yc);
        painter->drawPoint(x+xc, -y+yc);
        painter->drawPoint(-x+xc, -y+yc);

        x++;
        if (f >= 0)
        {
            y--;
            delta += 2*a2;
            f += delta;
        }
        df +=2*b2;
        f += df +b2;
    }
    delta = 2*b2*x;
    f+= -b2 * (x + 0.75) - a2 * (y - 0.75);
    df = -2*a2*y;

    while(y>= 0)
    {
        painter->drawPoint(x+xc, y+yc);
        painter->drawPoint(-x+xc, y+yc);
        painter->drawPoint(x+xc, -y+yc);
        painter->drawPoint(-x+xc, -y+yc);
        y--;
        if (f < 0)
        {
            x++;
            delta += 2*b2;
            f += delta;
        }
        df += 2*a2;
        f += df +a2;
    }
}

void MainWindow::method()
{
    if (!ui->radioButton_norm->isChecked() && !ui->radioButton_fon->isChecked())
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Choose color");
        mBox.exec();
    }
    if (ui->radioButton->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             traditional_okr(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             traditional_okr(QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_3->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             brezenhem_okr(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            brezenhem_okr(QPen(Qt::white,1,Qt::SolidLine));

        }
    }
    else if (ui->radioButton_2->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             parametr_okr(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             parametr_okr(QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_4->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
            sr_point_okr(QPen(color,1,Qt::SolidLine));
            //br_3(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            sr_point_okr(QPen(Qt::white,1,Qt::SolidLine));
             //br_3(QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_5->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
            standart_okr(QPen(color,1,Qt::SolidLine));
           // scene->addLine(x1, y1, x2, y2, QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            standart_okr(QPen(Qt::white,1,Qt::SolidLine));
           // scene->addLine(x1, y1, x2, y2, QPen(Qt::white,1,Qt::SolidLine));
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

void MainWindow::method_el()
{
    if (ui->radioButton->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             traditional_el(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             traditional_el(QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_3->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             brezenhem_el(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            brezenhem_el(QPen(Qt::white,1,Qt::SolidLine));

        }
    }
    else if (ui->radioButton_2->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             parametr_el(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             parametr_el(QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_4->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
            sr_point_okr(QPen(color,1,Qt::SolidLine));
            //br_3(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            sr_point_okr(QPen(Qt::white,1,Qt::SolidLine));
             //br_3(QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_5->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
            standart_el(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            standart_el(QPen(Qt::white,1,Qt::SolidLine));
           // scene->addLine(x1, y1, x2, y2, QPen(Qt::white,1,Qt::SolidLine));
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

void MainWindow::on_main_button_clicked()
{
    //окружность или ээлипс
    //метод
    // считать данные


    if (ui->radioButton_8->isChecked())
    {
        //okr
        QString l_x = ui->x_okr->text();
        QString l_y = ui->y_okr->text();
        QString l_r = ui->r_okr->text();
        QStringList u_x = l_x.split(" ", QString::SkipEmptyParts);
        QStringList u_y = l_y.split(" ", QString::SkipEmptyParts);
        QStringList u_r = l_r.split(" ", QString::SkipEmptyParts);


        if (u_x.count() != 1)
        {
            ui->x_okr->clear();
            return;
        }
        if (u_r.count() != 1)
        {
            ui->r_okr->clear();
            return;
        }
        if (u_y.count() != 1)
        {
            ui->y_okr->clear();
            return;
        }

        xc = u_x[0].toDouble();
        yc = u_y[0].toDouble();
        r = u_r[0].toDouble();

        num = 1;
        method();
        QPen pen = QPen(Qt::black);
        //traditional_okr(QPen(Qt::black,1,Qt::SolidLine));
        ui->draw_label->setPixmap(*scene);

    }
    else if (ui->radioButton_9->isChecked())
    {
        //ellipse
        QString l_x = ui->x_el->text();
        QString l_y = ui->y_el->text();
        QString l_a = ui->a_el->text();
        QString l_b = ui->b_el->text();
        QStringList u_x = l_x.split(" ", QString::SkipEmptyParts);
        QStringList u_y = l_y.split(" ", QString::SkipEmptyParts);
        QStringList u_a = l_a.split(" ", QString::SkipEmptyParts);
        QStringList u_b = l_b.split(" ", QString::SkipEmptyParts);


        if (u_x.count() != 1)
        {
            ui->x_el->clear();
            return;
        }
        if (u_a.count() != 1)
        {
            ui->a_el->clear();
            return;
        }
        if (u_b.count() != 1)
        {
            ui->a_el->clear();
            return;
        }
        if (u_y.count() != 1)
        {
            ui->y_el->clear();
            return;
        }

        xc = u_x[0].toDouble();
        yc = u_y[0].toDouble();
        a = u_a[0].toDouble();
        b = u_b[0].toDouble();

        num = 1;
        method_el();
        QPen pen = QPen(Qt::black);
        //traditional_okr(QPen(Qt::black,1,Qt::SolidLine));
        ui->draw_label->setPixmap(*scene);

    }
    else
    {
        //error
    }
}

void MainWindow::on_color_button_clicked()
{
    color = QColorDialog::getColor();
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color);
    ui->frame->setAutoFillBackground(true);
    ui->frame->setPalette(Pal);
    ui->frame->show();
}
