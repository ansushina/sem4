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
#include "controller.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     std::cout << "konstructor"<<std::endl;
    ui->setupUi(this);
    scene.scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene.scene);
    fig.mas = NULL;
    fig.matrix = NULL;
    fig.n = 0;
}

MainWindow::~MainWindow()
{
    delete [] fig.mas;
    free_matrix(fig.matrix, fig.n);
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
    QString text = ui->filename->text();

    //char filen[50];
    std::string str = text.toStdString();
    dataaction.filename = str.c_str();
    //do_process(DOWNLOAD, dataaction, fig,scene);
    controller(scene,DOWNLOAD, dataaction);
    controller(scene, DRAW_NUMBER, dataaction);
}

void MainWindow::on_filename_editingFinished(){}

void MainWindow::on_pushButton_3_clicked()
{
    double km = ui->doubleSpinBox_6->value();
    dataaction.mast.k = km;
   // do_process(MASTAB_NUMBER,dataaction,fig,scene);
    controller(scene, MASTAB_NUMBER, dataaction);
    controller(scene, DRAW_NUMBER, dataaction);
}

void MainWindow::on_pushButton_2_clicked()
{
    double dx = ui->doubleSpinBox_2->value();
    double dy = ui->doubleSpinBox_5->value();
    double dz = ui->doubleSpinBox_7->value();
    dataaction.per.dx = dx;
    dataaction.per.dy = dy;
    dataaction.per.dz = dz;
    //do_process(PERENOS_NUMBER,dataaction,fig,scene);
    controller(scene, PERENOS_NUMBER, dataaction);
    controller(scene, DRAW_NUMBER, dataaction);
}

void MainWindow::on_pushButton_clicked()
{
    double ax = ui->doubleSpinBox->value();
    double ay = ui->doubleSpinBox_3->value();
    double az = ui->doubleSpinBox_4->value();
    dataaction.pov.ax = ax;
    dataaction.pov.ay = ay;
    dataaction.pov.az = az;
    //controller(myscene_t scene, int act_number, action_t act
    controller(scene, POVOROT_NUMBER, dataaction);
    controller(scene, DRAW_NUMBER, dataaction);
}

void MainWindow::on_pushButton_4_clicked()
{
    controller(scene, DELETE_NUMBER, dataaction);
    controller(scene, DRAW_NUMBER, dataaction);
}

