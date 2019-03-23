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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    char filename[] = "1.txt";

    FILE *f = fopen(filename, "r");
    if (!f)
        return;
    int rc = read_from_file(f, fig);
    if (rc)
        return;
    draw_figure();
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw_figure()
{
    QPen pen = QPen(Qt::black);
    for (size_t i = 0; i < fig.n; i++)
    {
        for (size_t j = 0; j < fig.n; j++)
        {
            if (fig.matrix[i][j] != 0)
            {
                scene->addLine(fig.mas[i].x,fig.mas[i].y, fig.mas[j].x, fig.mas[j].y);
            }
        }
    }
}
