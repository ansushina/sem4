#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <vector>
#include "alg.h"
#include <QListWidgetItem>




namespace Ui {
class MainWindow;
}

struct okr
{
    cent p1;
    cent p2;
    cent p3;
    unsigned int n1;
    unsigned int n2;
    unsigned int n3;
};

struct answer
{
   struct okr o1;
   struct okr o2;

   cent c1;
   cent c2;
   double r1;
   double r2;

   double s;

   cent p1;
   cent p2;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void draw_circle(QPainter &paint, cent c, double r);
    void draw_o(QPainter &paint, struct okr o, int i);
    void init();
    void find_second(cent c, double r, struct okr o1);
    void do_something(cent c1, double r1, cent c2, double r2, struct okr o1, struct okr o2);
    void draw_all(QPainter &paint);
    void mashtab();
    void change(QString s, cent a, int i);

protected :
   void paintEvent(QPaintEvent *event);

private slots:
   void on_pushButton_clicked();

   void on_pushButton_4_clicked();

   void on_pushButton_2_clicked();

   void on_pushButton_5_clicked();

   void on_pushButton_3_clicked();

   void on_lineEdit_returnPressed();

   void on_lineEdit_2_returnPressed();

   void on_pushButton_6_clicked();

   void on_pushButton_7_clicked();

   void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

   void on_listWidget_2_doubleClicked(const QModelIndex &index);

private:
   std::vector<cent> points;
   std::vector<cent> points2;
   struct answer answ;
   struct answer answ1;
   cent zero;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
