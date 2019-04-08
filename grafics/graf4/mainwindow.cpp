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
    ui->draw_label->setStyleSheet("QLabel { background-color : white; }");


    scene = new QPixmap(851, 691);
    scene->fill(QColor("transparent"));
    painter = new QPainter(scene);
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

void traditional_okr(double xc, double yc, double r,QPainter &painter,QPen pen)
{
    std::cout<<"ptraditional"<<xc<<yc<<r<< std::endl;
    painter.setPen(pen);
    double x = 0;
    double y = r;

    while (x <= r)
    {
        y = sqrt(r*r-x*x);
        painter.drawPoint(int(round(x)+xc), int(round(y)+yc));
        painter.drawPoint(int(-round(x)+xc), int(round(y)+yc));
        painter.drawPoint(int(round(x)+xc), int(-round(y)+yc));
        painter.drawPoint(int(-round(x)+xc), int(-round(y)+yc));
        x++;

    }
    y = r;
    while (y >= 0)
    {
        y--;
        x = sqrt(r*r-y*y);
        painter.drawPoint(int(round(x)+xc), int(round(y)+yc));
        painter.drawPoint(int(-round(x)+xc), int(round(y)+yc));
        painter.drawPoint(int(round(x)+xc), int(-round(y)+yc));
        painter.drawPoint(int(-round(x)+xc), int(-round(y)+yc));

    }
}

void parametr_okr(double xc, double yc, double r,QPainter &painter,QPen pen)
{
    painter.setPen(pen);

    double x = 0;
    double y = r;
    int i = 0;
    for (double t = 0; t <= 3.1415926535/2; t += 1/r)
    {
        i++;
        std::cout<<i<<" "<< t <<" "<< x << " " << y <<std::endl;
        painter.drawPoint(int(round(x)+xc), int(round(y)+yc));
        painter.drawPoint(int(-round(x)+xc), int(round(y)+yc));
        painter.drawPoint(int(round(x)+xc), int(-round(y)+yc));
        painter.drawPoint(int(-round(x)+xc), int(-round(y)+yc));
        x = r*cos(t);
        y = r*sin(t);
    }
}

void brezenhem_okr(double xc, double yc, double r,QPainter &painter,QPen pen)
{

    painter.setPen(pen);
    int x = 0;
    int y =int(r);
    int di = int(2*(1-r));

    while (x <= r && y >= 0)
    {
        painter.drawPoint(x+xc, y+yc);
        painter.drawPoint(-x+xc, y+yc);
        painter.drawPoint(x+xc, -y+yc);
        painter.drawPoint(-x+xc, -y+yc);
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

void traditional_el(double xc, double yc, double a, double b,QPainter &painter,QPen pen)
{

    painter.setPen(pen);
    double x = 0;
    double y = 0;

    while (x <=a)
    {
        y = round(b*sqrt(1-x*x/a/a));
        painter.drawPoint(int(round(x)+xc), int(round(y)+yc));
        painter.drawPoint(int(-round(x)+xc), int(round(y)+yc));
        painter.drawPoint(int(round(x)+xc), int(-round(y)+yc));
        painter.drawPoint(int(-round(x)+xc), int(-round(y)+yc));
        x++;

    }
    y=0;
    while (y <= b)
    {
        x = round(a*sqrt(1-y*y/b/b));
        painter.drawPoint(int(round(x)+xc), int(round(y)+yc));
        painter.drawPoint(int(-round(x)+xc), int(round(y)+yc));
        painter.drawPoint(int(round(x)+xc), int(-round(y)+yc));
        painter.drawPoint(int(-round(x)+xc), int(-round(y)+yc));
        y++;

    }
}

void parametr_el(double xc, double yc, double a, double b,QPainter &painter,QPen pen)
{
    painter.setPen(pen);

    double x = 0;
    double y = b;
    int i = 0;
    double max = a>b? a:b;
    for (double t = 0; t <= 3.1415926535/2; t += 1/max)
    {
        i++;
        painter.drawPoint(x+xc, y+yc);
        painter.drawPoint(-x+xc, y+yc);
        painter.drawPoint(x+xc, -y+yc);
        painter.drawPoint(-x+xc, -y+yc);
        x = round(a*cos(t));
        y = round(b*sin(t));
    }
}

void brezenhem_el(double xc, double yc, double a, double b,QPainter &painter,QPen pen)
{
    painter.setPen(pen);
    int x = 0;
    int y = int(b);
    int end_y = 0;
    int a2 = a*a;
    int b2 = b*b;
    int di = a2 + b2 - 2 * a2 * y;

    while (y >= end_y)
    {
        painter.drawPoint(x+xc, y+yc);
        painter.drawPoint(-x+xc, y+yc);
        painter.drawPoint(x+xc, -y+yc);
        painter.drawPoint(-x+xc, -y+yc);
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

void standart_okr(double xc, double yc, double r,QPainter &painter,QPen pen)
{
     painter.setPen(pen);
     painter.drawEllipse(xc-r,yc-r,2*r,2*r);
}

void standart_el(double xc, double yc, double a, double b,QPainter &painter,QPen pen)
{
     painter.setPen(pen);
     painter.drawEllipse(xc-a,yc-b,2*a,2*b);
}

void sr_point_okr(double xc, double yc, double r,QPainter &painter,QPen pen)
{
    painter.setPen(pen);
    int r2 = r*r;
    int x = 0;
    int y = r;
    int rd2 = round(r/sqrt(2));

    int f = (r2-r2*y + 0.25*r2 + 0.5);
    int df = 0;
    int delta = -2*r2 * y;

    // идем по окружности до центра чатверти
    while(x <= rd2)
    {
        painter.drawPoint(x+xc, y+yc);
        painter.drawPoint(-x+xc, y+yc);
        painter.drawPoint(x+xc, -y+yc);
        painter.drawPoint(-x+xc, -y+yc);
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
        painter.drawPoint(x+xc, y+yc);
        painter.drawPoint(-x+xc, y+yc);
        painter.drawPoint(x+xc, -y+yc);
        painter.drawPoint(-x+xc, -y+yc);
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

/*void MainWindow::sr_point_el(QPen pen)
{
    painter.setPen(pen);
    int a2 = a*a;
    int b2 = b*b;
    int x = 0;
    int y = b;
    int rd2 = a2/sqrt(a2+b2);
    //fpr = b*b(x+1)^2 + a*a(y*y -0.5) - a*a*b*b

    int f = (b2 - a2 * y + 0.25 * a2 + 0.5);
    int df = 0;
    int delta = -2*a2 * y;

    while(x <= rd2)
    {
        painter.drawPoint(x+xc, y+yc);
        painter.drawPoint(-x+xc, y+yc);
        painter.drawPoint(x+xc, -y+yc);
        painter.drawPoint(-x+xc, -y+yc);

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
        painter.drawPoint(x+xc, y+yc);
        painter.drawPoint(-x+xc, y+yc);
        painter.drawPoint(x+xc, -y+yc);
        painter.drawPoint(-x+xc, -y+yc);
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
}*/
void sr_point_el(double xc, double yc, double a, double b,QPainter &painter,QPen pen)
{
    painter.setPen(pen);
    int a2 = a*a;
    int b2 = b*b;
    int x = 0;
    int y = b;
    int rd2 = a2/sqrt(a2+b2);
    //fpr = b*b(x+1)^2 + a*a(y*y -0.5) - a*a*b*b

    int f = (b2 - a2 * y + 0.25 * a2 + 0.5);
    int df = 0;
    int delta = -2*a2 * y;

    while(x <= rd2)
    {
        painter.drawPoint(x+xc, y+yc);
        painter.drawPoint(-x+xc, y+yc);
        painter.drawPoint(x+xc, -y+yc);
        painter.drawPoint(-x+xc, -y+yc);

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

    while(y >= 0)
    {
        painter.drawPoint(x+xc, y+yc);
        painter.drawPoint(-x+xc, y+yc);
        painter.drawPoint(x+xc, -y+yc);
        painter.drawPoint(-x+xc, -y+yc);
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
             traditional_okr(xc,yc,r,*painter,QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             traditional_okr(xc,yc,r,*painter,QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_3->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             brezenhem_okr(xc,yc,r,*painter,QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            brezenhem_okr(xc,yc,r,*painter,QPen(Qt::white,1,Qt::SolidLine));

        }
    }
    else if (ui->radioButton_2->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             parametr_okr(xc,yc,r,*painter,QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             parametr_okr(xc,yc,r,*painter,QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_4->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
            sr_point_okr(xc,yc,r,*painter,QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            sr_point_okr(xc,yc,r,*painter,QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_5->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
            standart_okr(xc,yc,r,*painter,QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            standart_okr(xc,yc,r,*painter,QPen(Qt::white,1,Qt::SolidLine));
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
             traditional_el(xc,yc,a,b,*painter,QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             traditional_el(xc,yc,a,b,*painter,QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_3->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             brezenhem_el(xc,yc,a,b,*painter,QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            brezenhem_el(xc,yc,a,b,*painter,QPen(Qt::white,1,Qt::SolidLine));

        }
    }
    else if (ui->radioButton_2->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             parametr_el(xc,yc,a,b,*painter,QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             parametr_el(xc,yc,a,b,*painter,QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_4->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
            sr_point_el(xc,yc,a,b,*painter,QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            sr_point_el(xc,yc,a,b,*painter,QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_5->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
            standart_el(xc,yc,a,b,*painter,QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            standart_el(xc,yc,a,b,*painter,QPen(Qt::white,1,Qt::SolidLine));
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

void MainWindow::on_color_fon_button_2_clicked()
{
    bg_color = QColorDialog::getColor();

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, bg_color);
    ui->frame_3->setAutoFillBackground(true);
    ui->frame_3->setPalette(Pal);
    ui->frame_3->show();
    ui->draw_label->setAutoFillBackground(true);
    ui->draw_label->setPalette(Pal);
    ui->draw_label->show();
}

void draw_okr_spectr(double xc, double yc, double r, double dr, int n, QPainter &painter,
                     QPen pen, void (*func)(double, double, double, QPainter &, QPen))
{
    double delta = 0;
    for (int i = 0; i < n; i++)
    {
            func(xc, yc, r + delta , painter, pen);
            delta += dr;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString l_x = ui->xc_s->text();
    QString l_y = ui->yc_s->text();
    QString l_r = ui->rn_s->text();
    QString l_n = ui->n_s->text();
    QString l_dr = ui->dr_s->text();
    bool ok1 = true, ok2 = true, ok3 = true, ok4 = true, ok5 = true;

    xc = l_x.toDouble(&ok1);
    yc = l_y.toDouble(&ok2);
    r = l_r.toDouble(&ok3);
    double dr = l_dr.toDouble(&ok4);
    int n = l_n.toInt(&ok5);
    if (!ok1 || !ok2 || !ok3 || !ok4 || !ok5)
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Input error!");
        mBox.exec();
        ui->xc_s->clear();
        ui->yc_s->clear();
        ui->rn_s->clear();
        ui->n_s->clear();
        ui->dr_s->clear();
        return;
    }
    QColor color1 = color;
    if (ui->radioButton_fon->isChecked())
         color1 = Qt::white;
    if (ui->radioButton->isChecked())
    {
        draw_okr_spectr(xc, yc, r, dr, n, *painter, QPen(color1,1,Qt::SolidLine), traditional_okr);
    }
    else if (ui->radioButton_3->isChecked())
    {
        draw_okr_spectr(xc, yc, r, dr, n, *painter, QPen(color1,1,Qt::SolidLine), brezenhem_okr);
    }
    else if (ui->radioButton_2->isChecked())
    {

             //parametr_el(QPen(color,1,Qt::SolidLine));
        draw_okr_spectr(xc, yc, r, dr, n, *painter, QPen(color1,1,Qt::SolidLine), parametr_okr);
    }
    else if (ui->radioButton_4->isChecked())
    {

            //sr_point_el(QPen(color,1,Qt::SolidLine));
        draw_okr_spectr(xc, yc, r, dr, n, *painter, QPen(color1,1,Qt::SolidLine), sr_point_okr);

    }
    else if (ui->radioButton_5->isChecked())
    {
            //standart_el(QPen(color,1,Qt::SolidLine));
        draw_okr_spectr(xc, yc, r, dr, n, *painter, QPen(color1,1,Qt::SolidLine), standart_okr);
    }
    else
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Choose method");
        mBox.exec();
    }
    ui->draw_label->setPixmap(*scene);
}


void draw_el_spectr(double xc, double yc, double a, double b, double dr, int n, QPainter &painter,
                     QPen pen, void (*func)(double, double, double,double, QPainter &, QPen))
{
    double delta = 0;
    //qDebug() << N << " is N";
    double koef = b / a;
    for (int i = 0; i < n; i++)
    {

        func(xc, yc, a + delta, b + delta * koef, painter, pen);
        delta += dr;
}

}
void MainWindow::on_pushButton_2_clicked()
{
    QString l_x = ui->xe_s->text();
    QString l_y = ui->ye_s->text();
    QString l_a = ui->a_s->text();
    QString l_b = ui->b_s->text();
    QString l_n = ui->ne_s->text();
    QString l_dr = ui->step_s->text();
    bool ok1 = true, ok2 = true, ok3 = true, ok4 = true, ok5 = true, ok6 = true;

    xc = l_x.toDouble(&ok1);
    yc = l_y.toDouble(&ok2);
    a = l_a.toDouble(&ok3);
    b = l_b.toDouble(&ok6);
    double dr = l_dr.toDouble(&ok4);
    int n = l_n.toInt(&ok5);
    if (!ok1 || !ok2 || !ok3 || !ok4 || !ok5)
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Input error!");
        mBox.exec();
        ui->xe_s->clear();
        ui->ye_s->clear();
        ui->a_s->clear();
        ui->b_s->clear();
        ui->ne_s->clear();
        ui->step_s->clear();
        return;
    }
    QColor color1 = color;
    if (ui->radioButton_fon->isChecked())
         color1 = Qt::white;
    if (ui->radioButton->isChecked())
    {
        draw_el_spectr(xc, yc,  a, b, dr, n, *painter, QPen(color1,1,Qt::SolidLine), traditional_el);
    }
    else if (ui->radioButton_3->isChecked())
    {
        draw_el_spectr(xc, yc,  a, b,dr, n, *painter, QPen(color1,1,Qt::SolidLine), brezenhem_el);
    }
    else if (ui->radioButton_2->isChecked())
    {

             //parametr_el(QPen(color,1,Qt::SolidLine));
        draw_el_spectr(xc, yc, a, b, dr, n, *painter, QPen(color1,1,Qt::SolidLine), parametr_el);
    }
    else if (ui->radioButton_4->isChecked())
    {

            //sr_point_el(QPen(color,1,Qt::SolidLine));
        draw_el_spectr(xc, yc,  a, b, dr, n, *painter, QPen(color1,1,Qt::SolidLine), sr_point_el);

    }
    else if (ui->radioButton_5->isChecked())
    {
            //standart_el(QPen(color,1,Qt::SolidLine));
        draw_el_spectr(xc, yc, a, b, dr, n, *painter, QPen(color1,1,Qt::SolidLine), standart_el);
    }
    else
    {
        QMessageBox mBox;
        mBox.setIcon(QMessageBox::Information);
        mBox.setInformativeText("Choose method");
        mBox.exec();
    }
    ui->draw_label->setPixmap(*scene);
}
