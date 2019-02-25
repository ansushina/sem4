#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void init(MainWindow *w);
private slots:

    void on_buttonBox_accepted();

private:
    MainWindow *main;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
