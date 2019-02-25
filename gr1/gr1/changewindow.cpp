#include "changewindow.h"
#include "ui_changewindow.h"

changewindow::changewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::changewindow)
{
    ui->setupUi(this);
}

changewindow::~changewindow()
{
    delete ui;
}
