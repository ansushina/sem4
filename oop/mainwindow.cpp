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
    fig.arr = NULL;
    fig.matrix = NULL;
    fig.n = 0;
}

MainWindow::~MainWindow()
{
    delete [] fig.arr;
    free_matrix(fig.matrix, fig.n);
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
    QString text = ui->filename->text();

    std::string str = text.toStdString();
    dataaction.filename = str.c_str();
    controller(scene,DOWNLOAD, dataaction);
    controller(scene, DRAW_NUMBER, dataaction);
}

void MainWindow::on_filename_editingFinished(){}

void MainWindow::on_pushButton_3_clicked()
{
    double km = ui->doubleSpinBox_6->value();
    dataaction.scale.k = km;
    controller(scene, SCALE_NUMBER, dataaction);
    controller(scene, DRAW_NUMBER, dataaction);
}

void MainWindow::on_pushButton_2_clicked()
{
    double dx = ui->doubleSpinBox_2->value();
    double dy = ui->doubleSpinBox_5->value();
    double dz = ui->doubleSpinBox_7->value();
    dataaction.move.dx = dx;
    dataaction.move.dy = dy;
    dataaction.move.dz = dz;

    controller(scene, MOVE_NUMBER, dataaction);
    controller(scene, DRAW_NUMBER, dataaction);
}

void MainWindow::on_pushButton_clicked()
{
    double ax = ui->doubleSpinBox->value();
    double ay = ui->doubleSpinBox_3->value();
    double az = ui->doubleSpinBox_4->value();
    dataaction.rotation.ax = ax;
    dataaction.rotation.ay = ay;
    dataaction.rotation.az = az;

    controller(scene, ROTATION_NUMBER, dataaction);
    controller(scene, DRAW_NUMBER, dataaction);
}

void MainWindow::on_pushButton_4_clicked()
{
    controller(scene, DELETE_NUMBER, dataaction);
    controller(scene, DRAW_NUMBER, dataaction);
}

