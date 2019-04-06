#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QColor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void traditional_okr(QPen pen);
    void parametr_okr(QPen pen);
    void brezenhem_okr(QPen pen);
    void sr_point_okr(QPen pen);
    void standart_okr(QPen pen);

    void traditional_el(QPen pen);
    void parametr_el(QPen pen);
    void brezenhem_el(QPen pen);
    void sr_point_el(QPen pen);
    void standart_el(QPen pen);
    void method();
    void method_el();



private slots:
    void on_main_button_clicked();

    void on_color_button_clicked();

private:
    Ui::MainWindow *ui;
    //QGraphicsScene *scene;
    QPixmap *scene;
    QPainter *painter;
    QColor color = Qt::black;


    double xc, yc;
    double r;
    double a;
    double b;
    int num;
};

#endif // MAINWINDOW_H
