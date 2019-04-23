#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QColorDialog>
#include <QMessageBox>
#include <QPixmapCache>
#include <iostream>
//#include <windows.h>
#include <math.h>
#include <QColor>
#include <QPainter>

typedef struct line line_t;
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
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
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_shading_button_clicked();

    void on_background_button_clicked();

    void on_clear_button_clicked();

    void on_pushButton_2_clicked();

    void on_new_point_button_clicked();

    void on_main_button_clicked();

private:
    Ui::MainWindow *ui;
    QPainter *painter;
    QPixmap *scene;
    QColor color_border;
    QColor color_background;
    QColor color_shading;
    QPoint position;

    int x_prev = -1;
    int y_prev = -1;

    int x0, y0;
    bool is_first = true;
    bool is_ready = false;
    QImage img;
};

#endif // MAINWINDOW_H
