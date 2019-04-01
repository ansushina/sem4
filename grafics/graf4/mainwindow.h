#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

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
    void on_main_button_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    double xc, yc;
    double r;
    double a;
    double b;
    int num;
};

#endif // MAINWINDOW_H
