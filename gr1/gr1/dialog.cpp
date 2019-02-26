#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init(MainWindow *w, int u)
{
    main = w;

    i = u;
}

void Dialog::on_buttonBox_accepted()
{
    QString x = "";
    x = ui->lineEdit->text();
    QStringList u = x.split(" ", QString::SkipEmptyParts);
    int count = u.count();
    if (count == 2)
    {
        cent a;
        a.x = u[0].toDouble();
        a.y = u[1].toDouble();
        main->change(x, a, i);
        this->close();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Невозможно изменить точку! Введено неправильное новое значение.");
        msgBox.exec();
    }
}
