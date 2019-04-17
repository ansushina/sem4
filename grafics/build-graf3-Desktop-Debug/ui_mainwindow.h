/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QGraphicsView *graphicsView;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *x1;
    QLabel *l1;
    QLineEdit *y1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *x2;
    QLabel *label_5;
    QLineEdit *y2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_norm;
    QRadioButton *radioButton_fon;
    QPushButton *draw;
    QPushButton *choose_color;
    QPushButton *wiz_button;
    QPushButton *clean_but;
    QFrame *frame;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1050, 770);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 700, 700));
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(770, 20, 251, 421));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        x1 = new QLineEdit(verticalLayoutWidget_2);
        x1->setObjectName(QStringLiteral("x1"));

        horizontalLayout->addWidget(x1);

        l1 = new QLabel(verticalLayoutWidget_2);
        l1->setObjectName(QStringLiteral("l1"));

        horizontalLayout->addWidget(l1);

        y1 = new QLineEdit(verticalLayoutWidget_2);
        y1->setObjectName(QStringLiteral("y1"));

        horizontalLayout->addWidget(y1);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        x2 = new QLineEdit(verticalLayoutWidget_2);
        x2->setObjectName(QStringLiteral("x2"));

        horizontalLayout_3->addWidget(x2);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        y2 = new QLineEdit(verticalLayoutWidget_2);
        y2->setObjectName(QStringLiteral("y2"));

        horizontalLayout_3->addWidget(y2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label);

        radioButton_1 = new QRadioButton(verticalLayoutWidget_2);
        radioButton_1->setObjectName(QStringLiteral("radioButton_1"));

        verticalLayout_2->addWidget(radioButton_1);

        radioButton_2 = new QRadioButton(verticalLayoutWidget_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_2->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(verticalLayoutWidget_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(verticalLayoutWidget_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_2->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(verticalLayoutWidget_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        verticalLayout_2->addWidget(radioButton_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2->setContentsMargins(-1, 6, -1, -1);
        radioButton_norm = new QRadioButton(verticalLayoutWidget_2);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_norm);
        radioButton_norm->setObjectName(QStringLiteral("radioButton_norm"));
        radioButton_norm->setAutoRepeat(false);
        radioButton_norm->setAutoExclusive(true);

        horizontalLayout_2->addWidget(radioButton_norm);

        radioButton_fon = new QRadioButton(verticalLayoutWidget_2);
        buttonGroup->addButton(radioButton_fon);
        radioButton_fon->setObjectName(QStringLiteral("radioButton_fon"));
        radioButton_fon->setFocusPolicy(Qt::StrongFocus);
        radioButton_fon->setAutoRepeat(false);
        radioButton_fon->setAutoExclusive(true);

        horizontalLayout_2->addWidget(radioButton_fon);


        verticalLayout_2->addLayout(horizontalLayout_2);

        draw = new QPushButton(verticalLayoutWidget_2);
        draw->setObjectName(QStringLiteral("draw"));
        draw->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(draw->sizePolicy().hasHeightForWidth());
        draw->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(draw);

        choose_color = new QPushButton(centralWidget);
        choose_color->setObjectName(QStringLiteral("choose_color"));
        choose_color->setGeometry(QRect(840, 450, 121, 41));
        wiz_button = new QPushButton(centralWidget);
        wiz_button->setObjectName(QStringLiteral("wiz_button"));
        wiz_button->setGeometry(QRect(790, 660, 221, 41));
        clean_but = new QPushButton(centralWidget);
        clean_but->setObjectName(QStringLiteral("clean_but"));
        clean_but->setGeometry(QRect(790, 600, 221, 41));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(880, 500, 41, 41));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1050, 17));
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
        label_7->setText(QApplication::translate("MainWindow", "\320\222\320\262\321\203\320\264\320\270\321\202\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\202\320\276\321\207\320\265\320\272:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "X: ", Q_NULLPTR));
        l1->setText(QApplication::translate("MainWindow", "Y: ", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "X: ", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Y: ", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260:", Q_NULLPTR));
        radioButton_1->setText(QApplication::translate("MainWindow", "\320\246\320\224\320\220", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "\320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274 \321\201 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\274\320\270 \321\207\320\270\321\201\320\273\320\260\320\274\320\270", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "\320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274 \321\201 \321\206\320\265\320\273\321\213\320\274\320\270 \321\207\320\270\321\201\320\273\320\260\320\274\320\270", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("MainWindow", "\320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274 \321\201 \321\203\321\201\321\202\321\200\320\260\320\275\320\265\320\275\320\270\320\265\320\274 \321\201\321\202\321\203\320\277\320\265\320\275\321\207\320\260\321\202\320\276\321\201\321\202\320\270", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("MainWindow", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\321\207\320\275\321\213\320\271 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274", Q_NULLPTR));
        radioButton_norm->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\271 \321\206\320\262\320\265\321\202", Q_NULLPTR));
        radioButton_fon->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", Q_NULLPTR));
        draw->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        choose_color->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", Q_NULLPTR));
        wiz_button->setText(QApplication::translate("MainWindow", "\320\222\320\270\320\267\321\203\320\260\320\273\321\214\320\275\321\213\320\265 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272\320\270", Q_NULLPTR));
        clean_but->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
