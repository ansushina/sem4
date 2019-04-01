#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::traditional_okr(QPen pen)
{

}

void MainWindow::method()
{
    if (ui->radioButton_1->isChecked())
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
        method();

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
