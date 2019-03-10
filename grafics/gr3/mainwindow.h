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

private:
    void cda(QPainter &paint);
    void br_1(QPainter &paint);
    Ui::MainWindow *ui;
    double x1,y1,x2,y2;
    int i;
};

#endif // MAINWINDOW_H
