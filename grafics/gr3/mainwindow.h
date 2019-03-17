#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    void cda(QPainter &paint, double x1, double y1, double x2, double y2, QColor color);
    void br_1(QPainter &paint, double x1, double y1, double x2, double y2, QColor color);
    void br_2(QPainter &paint, double x1, double y1, double x2, double y2, QColor color);
    void br_3(QPainter &paint, double x1, double y1, double x2, double y2, QColor color);
    Ui::MainWindow *ui;
    double x1,y1,x2,y2;
    int i;
    double bg_x1, bg_y1, bg_x2, bg_y2;
    int bg_i;
    QColor color;
    QColor bg_color;
    bool flag;
    bool f;
};

#endif // MAINWINDOW_H
