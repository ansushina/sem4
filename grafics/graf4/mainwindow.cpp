#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <math.h>
void MainWindow::traditional_okr(QPen pen)
{

    int x = 0;
    int y = r;
    int di = (x+1)*(x+1) + (y-1)*(y-1)-r*r;
    while (x < xc+r)
    {

        scene->addEllipse(x+xc,y+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
        if (di < 0)
        {
            //vnutri
            //диагональный или горизонтальный
            int d1 = abs((x+1)*(x+1) + y*y + r*r)-abs((x+1)*(x+1) + (y-1)*(y-1)-r*r);
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
            int d2 = abs((x+1)*(x+1) + (y-1)*(y-1)-r*r)-abs(x*x + (y-1)*(y-1) - r*r);
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

void MainWindow::method()
{
    if (ui->radioButton->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             //cda(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             //cda(QPen(Qt::white,1,Qt::SolidLine));
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
             //br_1(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            //br_1(QPen(Qt::white,1,Qt::SolidLine));

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
            //br_2(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             //br_2(QPen(Qt::white,1,Qt::SolidLine));
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
            //br_3(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
             //br_3(QPen(Qt::white,1,Qt::SolidLine));
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
           // scene->addLine(x1, y1, x2, y2, QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
           // scene->addLine(x1, y1, x2, y2, QPen(Qt::white,1,Qt::SolidLine));
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
       // method();
        QPen pen = QPen(Qt::black);
        traditional_okr(QPen(Qt::black,1,Qt::SolidLine));

    }
    else if (ui->radioButton_9->isChecked())
    {
        //ellipse
    }
    else
    {
        //error
    }
}
