#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#define PI 3.14159265

//#include <Qpainter>


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



    void on_pushButton_clicked();

    void on_draw_clicked();

    void on_choose_color_clicked();

    void on_clean_but_clicked();

    void on_wiz_button_clicked();

private:
        QColor color;
        double x1,y1,x2,y2;
        int i;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    void cda(QPen pen);
    void br_1(QPen pen);
    void br_2(QPen pen);
    void br_3(QPen pen);
    void method();
};

#endif // MAINWINDOW_H
