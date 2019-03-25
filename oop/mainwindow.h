#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include "io.h"
#include "process.h"

union data
{
    char *filename;
    struct pov
    {
        char* alphax;
        char* alphay;
        char* alphaz;
    };
    struct mast
    {
        char* k;
    };
    struct per
    {
        char *dx;
        char *dy;
    };
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    struct figure fig;
    void draw_figure();
};

#endif // MAINWINDOW_H
