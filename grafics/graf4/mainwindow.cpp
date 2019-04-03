#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "math.h"
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
/*
 * MainWindow::traditional_okr(QPen pen)
  «(»
  {
>     //x=0;
>     //y=r;
>     //x=r
>     //y=0
>     //y=sqrt(r*r-x*x)
  «r*r-x*x»
      //lg=abs((xi+1)^2 + yi^2 - r*r)
  «(»
      //ld = (xi+1)+(yi-1)-r
  «(»
      //lb = xi*xi + (yi-1) -r
  «(»
      //пять вариантов
      //пять: Нет такого файла или каталога
      // d - разность квадратов расстояний от центра окружности

      //до диагонального пиксела и до идеальной окружности
      //до: Нет такого файла или каталога
      // di = (xi+1)^2 + (yi-1)^2 -r*r
  «(»
      // di < 0 -> внутри, выбираем горизонтальный или диагональный
      0: Нет такого файла или каталога
      // вычислим Лг и Лд - Д1 = Лг-Лд
    //Д1 мельше 0 - диагональный
    // иначе горизонтальный
    // ди Ю 0 - снаружи
   // посчитаем Д2 = ЛД-ЛВ
   //если меньше нуля - диагональный
   //иначе -вертикальный
    // ди = 0 - лежит на окружности д1 и д2
4$     int x = 0;
 int y = r;

   int d = 2*(1-r);
     int d1, d2;

    while (x < r)
>     {
>         //d = (x+1)*(x+1) + (y-1)*(y-1) - r*r;
       if (d < 0)
>         {
>             //1 или 2 случай
>             d1 = abs((x+1)*(x+1) + y*y - r*r) - abs((x+1)*(x+1) + (y-1)*(y-1)-r*r);
          if (d1 <= 0)
>             {
>                 //горизонтальный
>                 x++;
>                 d = d+2*x +1;
>             }
>             else
            {
>                 //диагональный
>                 x++;
>                 y--;
>                 d=d +2*x -2*y+2;
>             }


Try: sudo apt install <deb name>

y--:

          }
  «}»
          else (d > 0)
  «else»
          {
>             d2 = 2 * (d-x) - 1;
  «(»
              if (d2 <= 0)
>             {
>                 //диагональный
>                 x++;
>                 y--;
>                 d=d +2*x -2*y+2;
>             }
>             else
  «else»
              {
>                 // вертикальный
>                 y--;
>                 d = 2*y+1
>             }

y--:
d:

          }
  «}»
          else
  «else»
          {
>             // диагольный?
>         }


      }
  «}»

*/
void MainWindow::traditional_okr(QPen pen)
{

    //double dx = r;
  / // double dy = r;
  //  double l = r;
   //
   // double sx = dx/l;
   // double sy = dy/l;
    double x = 0;
    double y = r;

    while (x < r && y > 0)
    {
        scene->addEllipse(round(x)+xc,round(y)+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
        x++;
        y = sqrt(r*r-x*x);
    }
    while (y > 0)
    {
        scene->addEllipse(round(x)+xc,round(y)+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
        y--;
        x = sqrt(r*r-y*y);
    }
}

void MainWindow::parametr_okr(QPen pen)
{
    // x = r*cos(t);
    // y = r*sin(t);
    double x = 0;
    double y = r;
    for (int t = 0; t < 3.14/2; t += 1/r)
    {
        scene->addEllipse(round(x)+xc,round(y)+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
        x = r*cos(t);
        y = r*sin(t);
    }
}


void MainWindow::brezenhem(QPen pen)
{

    int x = 0;
    int y = r;
    int di = 2*(1-r);

    while (x < r && y > 0)
    {

        scene->addEllipse(x+xc,y+yc,0.1,0.1,pen,QBrush(Qt::SolidPattern));
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
    else if (ui->radioButton_3->isChecked())
    {
        if (ui->radioButton_norm->isChecked())
        {
             brezenhem(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_fon->isChecked())
        {
            brezenhem(QPen(Qt::white,1,Qt::SolidLine));

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
