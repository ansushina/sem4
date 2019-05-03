/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_13;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *dx;
    QLabel *label_7;
    QLineEdit *dy;
    QPushButton *perenos_button;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *xm;
    QLabel *label_10;
    QLineEdit *ym;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *kx;
    QLabel *label_2;
    QLineEdit *ky;
    QPushButton *mastab_buttob;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QLineEdit *xc;
    QLabel *label_12;
    QLineEdit *yc;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *alpha;
    QPushButton *povorot_button;
    QSpacerItem *verticalSpacer_4;
    QPushButton *return_one_button;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 750);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 0, 770, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 700, 770, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 0, 6, 700));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(770, 0, 3, 700));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(790, 30, 210, 641));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout->addWidget(label_13);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout->addWidget(label_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        dx = new QLineEdit(verticalLayoutWidget);
        dx->setObjectName(QStringLiteral("dx"));

        horizontalLayout_3->addWidget(dx);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        dy = new QLineEdit(verticalLayoutWidget);
        dy->setObjectName(QStringLiteral("dy"));

        horizontalLayout_3->addWidget(dy);


        verticalLayout->addLayout(horizontalLayout_3);

        perenos_button = new QPushButton(verticalLayoutWidget);
        perenos_button->setObjectName(QStringLiteral("perenos_button"));

        verticalLayout->addWidget(perenos_button);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        xm = new QLineEdit(verticalLayoutWidget);
        xm->setObjectName(QStringLiteral("xm"));

        horizontalLayout_4->addWidget(xm);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        ym = new QLineEdit(verticalLayoutWidget);
        ym->setObjectName(QStringLiteral("ym"));

        horizontalLayout_4->addWidget(ym);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        kx = new QLineEdit(verticalLayoutWidget);
        kx->setObjectName(QStringLiteral("kx"));

        horizontalLayout->addWidget(kx);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        ky = new QLineEdit(verticalLayoutWidget);
        ky->setObjectName(QStringLiteral("ky"));

        horizontalLayout->addWidget(ky);


        verticalLayout->addLayout(horizontalLayout);

        mastab_buttob = new QPushButton(verticalLayoutWidget);
        mastab_buttob->setObjectName(QStringLiteral("mastab_buttob"));

        verticalLayout->addWidget(mastab_buttob);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_5->addWidget(label_11);

        xc = new QLineEdit(verticalLayoutWidget);
        xc->setObjectName(QStringLiteral("xc"));

        horizontalLayout_5->addWidget(xc);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_5->addWidget(label_12);

        yc = new QLineEdit(verticalLayoutWidget);
        yc->setObjectName(QStringLiteral("yc"));

        horizontalLayout_5->addWidget(yc);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        alpha = new QLineEdit(verticalLayoutWidget);
        alpha->setObjectName(QStringLiteral("alpha"));

        horizontalLayout_2->addWidget(alpha);


        verticalLayout->addLayout(horizontalLayout_2);

        povorot_button = new QPushButton(verticalLayoutWidget);
        povorot_button->setObjectName(QStringLiteral("povorot_button"));

        verticalLayout->addWidget(povorot_button);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        return_one_button = new QPushButton(verticalLayoutWidget);
        return_one_button->setObjectName(QStringLiteral("return_one_button"));

        verticalLayout->addWidget(return_one_button);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217 \320\275\320\260 \320\277\320\273\320\276\321\201\320\272\320\276\321\201\321\202\320\270.\n"
" \320\230\321\201\321\205\320\276\320\264\320\275\320\276\320\265 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265:\n"
" (x-a)*(x-a)+(y-b)*(y-b) = r*r\n"
" y = c - (x-d)*(x-d) \n"
" a = 350  b = 350 r = 150\n"
" c= 350 d = 350", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201: \n"
" \320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\321\215\321\204\320\270\321\206\320\265\320\275\321\202\321\213 \320\277\320\265\321\200\320\265\320\275\320\276\321\201\320\260: ", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "dx:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "dy:", nullptr));
        perenos_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\277\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265:\n"
" \320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\321\215\321\204\320\270\321\206\320\265\320\275\321\202\321\213 \320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217\n"
" \320\270 \321\202\320\276\321\207\320\272\321\203 \320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217\n"
"", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "xm:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "ym:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", " kx: ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "ky: ", nullptr));
        mastab_buttob->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202: \n"
" \320\222\320\262\320\276\320\264\320\270\321\202\320\265 \321\206\320\275\321\202\321\200 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260 \320\270 \321\203\320\263\320\276\320\273: ", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "xc:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "yc:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273:", nullptr));
        povorot_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\277\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        return_one_button->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\275\320\260 \320\276\320\264\320\270\320\275 \321\210\320\260\320\263 ", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\272 \320\270\321\201\321\205\320\276\320\264\320\275\320\276\320\274\321\203 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
