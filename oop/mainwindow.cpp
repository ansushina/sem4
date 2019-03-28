#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <qpainter.h>
#include <QPainter>
#include <QMessageBox>
#include <iostream>
#include <QColor>
#include <QColorDialog>
#include "io.h"
#include "process.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     std::cout << "konstructor"<<std::endl;
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw_figure()
{
    QPen pen = QPen(Qt::black);
     std::cout << "in draw"<<std::endl;
    for (size_t i = 0; i < fig.n; i++)
    {
        for (size_t j = 0; j < fig.n; j++)
        {

            std::cout <<i <<j <<std::endl;
            if (fig.matrix[i][j] != 0)
            {
                std::cout <<i <<std::endl;
                std::cout <<fig.mas[j].x<<" "<<fig.mas[j].y <<std::endl;
                scene->addLine(fig.mas[i].x,fig.mas[i].y, fig.mas[j].x, fig.mas[j].y);
            }
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
  /*  QString text = ui->filename->text();

    char *filen = text.toStdString();
    dataaction.filename = filen;
    do_process(DOWNLOAD, dataaction, fig);*/
}

void MainWindow::on_filename_editingFinished()
{

}
