#ifndef CHANGEWINDOW_H
#define CHANGEWINDOW_H

#include <QMainWindow>

namespace Ui {
class changewindow;
}

class changewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit changewindow(QWidget *parent = nullptr);
    ~changewindow();

private:
    Ui::changewindow *ui;
};

#endif // CHANGEWINDOW_H
