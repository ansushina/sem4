#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QColorDialog>
#include <QMessageBox>
#include <QPixmapCache>
#include <iostream>
//#include <windows.h>
#include <stack>
#include <vector>
#include <math.h>
#include <QColor>
#include <QPainter>
#include "alg.h"




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

    void on_pushButton_3_clicked();

private:
    //void find_next(std::stack<point_t> &stack, int &x_left, int &x_right, const int &y);
    void draw_line(double x1, double y1, double x2, double y2);
    void draw_rect(int x1, int y1, int x2, int y2);
    void del_polygon();

    Ui::MainWindow *ui;
    QPainter *painter;
    QPixmap *scene;
    QColor color_otr;
    QColor color_line;
    QColor color_ots;
    QPoint position;

    int x_prev = -1;
    int y_prev = -1;

    int x_up,y_up,x_down,y_down;
    bool is_start_ots = true;


    int x0, y0;
    bool is_first = true;
    //bool is_ready = false;
    bool line_flag = false;
    bool rect_flag = false;
    std::vector<line_t> lines;
    std::vector<line_t> egles;
    QImage img;
};

#endif // MAINWINDOW_H
