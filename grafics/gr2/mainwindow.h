#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <vector>
//#define A 300.
//#define B 300.
//#define R 100.
//y = c - (x-d)(x-d)
//#define C 20.
//#define D 100.#include <QPaintEvent>

// (x-a)(x-a) + (y-b)(y-b) = r*r

typedef struct point p;

struct point
{
    double x;
    double y;

    point() : x(0), y(0){}
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init();

    void draw_circle(QPainter &paint);
    void draw_grafic(QPainter &paint);

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_perenos_button_clicked();

    void on_mastab_buttob_clicked();

    void on_povorot_button_clicked();

    void on_return_one_button_clicked();

    void on_pushButton_clicked();

private:
    double f(double x);
    double a,b,r,c,d;
    Ui::MainWindow *ui;

    std::vector<p> points;
    std::vector<p> okr;
    std::vector<p> strih_1;
    std::vector<p> strih_2;

    std::vector<p> points_prev;
    std::vector<p> okr_prev;
    std::vector<p> strih_1_prev;
    std::vector<p> strih_2_prev;
};

#endif // MAINWINDOW_H
