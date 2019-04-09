#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#define PI 3.14159265

//#include <Qpainter>

class Point
{
public:
    Point(){}
    Point(int x, int y): x_(x),y_(y) {}
protected:
    QRectF boundingRect() const
    {
        return QRectF(QPoint(x_,y_), QPoint(x_, y_));
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        painter->drawPoint(x_, y_);
        Q_UNUSED(option);
        Q_UNUSED(widget);
    }
private:
    int x_;
    int y_;
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
    QVector<Point*> point;
    void cda(QPen pen);
    void br_1(QPen pen);
    void br_2(QPen pen);
    void br_3(QPen pen);
    void method();
};

#endif // MAINWINDOW_H
