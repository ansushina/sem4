/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *k;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *dx;
    QLabel *label_5;
    QLineEdit *dy;
    QLabel *label_6;
    QLineEdit *dz;
    QPushButton *pushButton;
    QLabel *label_7;
    QFormLayout *formLayout_2;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *alphaxy;
    QLineEdit *alphaxz;
    QLineEdit *alphayz;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1050, 730);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 700, 700));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        graphicsView->setFont(font);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(719, 10, 321, 671));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        k = new QLineEdit(verticalLayoutWidget);
        k->setObjectName(QStringLiteral("k"));

        horizontalLayout->addWidget(k);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setVerticalSpacing(6);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        dx = new QLineEdit(verticalLayoutWidget);
        dx->setObjectName(QStringLiteral("dx"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dx);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        dy = new QLineEdit(verticalLayoutWidget);
        dy->setObjectName(QStringLiteral("dy"));

        formLayout->setWidget(1, QFormLayout::FieldRole, dy);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        dz = new QLineEdit(verticalLayoutWidget);
        dz->setObjectName(QStringLiteral("dz"));

        formLayout->setWidget(2, QFormLayout::FieldRole, dz);


        verticalLayout->addLayout(formLayout);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_10);

        alphaxy = new QLineEdit(verticalLayoutWidget);
        alphaxy->setObjectName(QStringLiteral("alphaxy"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, alphaxy);

        alphaxz = new QLineEdit(verticalLayoutWidget);
        alphaxz->setObjectName(QStringLiteral("alphaxz"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, alphaxz);

        alphayz = new QLineEdit(verticalLayoutWidget);
        alphayz->setObjectName(QStringLiteral("alphayz"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, alphayz);


        verticalLayout->addLayout(formLayout_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1050, 18));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265.\n"
"\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\321\215\321\204\320\270\321\206\320\265\320\275\321\202 \320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217:", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "k: ", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201\n"
"\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\321\215\321\204\320\270\321\206\320\265\320\275\321\202\321\213 \320\277\320\265\321\200\320\265\320\275\320\276\321\201\320\260:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "dX:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "dY:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "dZ:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202:\n"
"\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\203\320\263\320\273\321\213 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "AlphaXY", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "AlphaXZ", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "AlphaYZ", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
