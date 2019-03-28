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
        double alphax;
        double alphay;
        double alphaz;
    };
    struct mast
    {
        double k;
    };
    struct per
    {
        double dx;
        double dy;
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

    void on_filename_editingFinished();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    struct figure fig;
    void draw_figure();
    union data dataaction;
};

#endif // MAINWINDOW_H
