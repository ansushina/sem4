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

    void method();
    void method_el();




private slots:
    void on_main_button_clicked();

    void on_color_button_clicked();

    void on_color_fon_button_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    //QGraphicsScene *scene;
    QPixmap *scene;
    QPainter *painter;
    QColor color = Qt::black;
    QColor bg_color = Qt::white;


    double xc, yc;
    double r;
    double a;
    double b;
    int num;
};

#endif // MAINWINDOW_H
