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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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
    QLabel *draw_label;
    QFrame *line;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QFrame *frame_otr;
    QFrame *frame_line;
    QFrame *frame_ots;
    QPushButton *pushButton;
    QPushButton *shading_button;
    QPushButton *background_button;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *input_line;
    QRadioButton *input_otsek;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *x_lineedit;
    QLineEdit *y_lineedit;
    QPushButton *new_point_button;
    QSpacerItem *verticalSpacer_3;
    QPushButton *main_button;
    QPushButton *clear_button;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1300, 770);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        draw_label = new QLabel(centralWidget);
        draw_label->setObjectName(QStringLiteral("draw_label"));
        draw_label->setGeometry(QRect(10, 10, 700, 700));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(720, 0, 16, 861));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(790, 10, 361, 691));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_otr = new QFrame(verticalLayoutWidget);
        frame_otr->setObjectName(QStringLiteral("frame_otr"));
        frame_otr->setMinimumSize(QSize(20, 20));
        frame_otr->setMaximumSize(QSize(20, 20));
        frame_otr->setFrameShape(QFrame::StyledPanel);
        frame_otr->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_otr, 0, 0, 1, 1);

        frame_line = new QFrame(verticalLayoutWidget);
        frame_line->setObjectName(QStringLiteral("frame_line"));
        frame_line->setMinimumSize(QSize(20, 20));
        frame_line->setMaximumSize(QSize(20, 20));
        frame_line->setFrameShape(QFrame::StyledPanel);
        frame_line->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_line, 2, 0, 1, 1);

        frame_ots = new QFrame(verticalLayoutWidget);
        frame_ots->setObjectName(QStringLiteral("frame_ots"));
        frame_ots->setMinimumSize(QSize(20, 20));
        frame_ots->setMaximumSize(QSize(20, 20));
        frame_ots->setFrameShape(QFrame::StyledPanel);
        frame_ots->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_ots, 1, 0, 1, 1);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        shading_button = new QPushButton(verticalLayoutWidget);
        shading_button->setObjectName(QStringLiteral("shading_button"));

        gridLayout->addWidget(shading_button, 1, 1, 1, 1);

        background_button = new QPushButton(verticalLayoutWidget);
        background_button->setObjectName(QStringLiteral("background_button"));

        gridLayout->addWidget(background_button, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_2);

        input_line = new QRadioButton(verticalLayoutWidget);
        input_line->setObjectName(QStringLiteral("input_line"));

        verticalLayout_2->addWidget(input_line);

        input_otsek = new QRadioButton(verticalLayoutWidget);
        input_otsek->setObjectName(QStringLiteral("input_otsek"));

        verticalLayout_2->addWidget(input_otsek);


        verticalLayout->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 150));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(70, 30, 191, 80));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        x_lineedit = new QLineEdit(formLayoutWidget);
        x_lineedit->setObjectName(QStringLiteral("x_lineedit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, x_lineedit);

        y_lineedit = new QLineEdit(formLayoutWidget);
        y_lineedit->setObjectName(QStringLiteral("y_lineedit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, y_lineedit);

        new_point_button = new QPushButton(groupBox);
        new_point_button->setObjectName(QStringLiteral("new_point_button"));
        new_point_button->setGeometry(QRect(90, 110, 171, 25));

        verticalLayout->addWidget(groupBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_3);

        main_button = new QPushButton(verticalLayoutWidget);
        main_button->setObjectName(QStringLiteral("main_button"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(main_button->sizePolicy().hasHeightForWidth());
        main_button->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(main_button);

        clear_button = new QPushButton(verticalLayoutWidget);
        clear_button->setObjectName(QStringLiteral("clear_button"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(clear_button->sizePolicy().hasHeightForWidth());
        clear_button->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(clear_button);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1300, 21));
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
        draw_label->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \320\276\321\202\321\200\320\265\320\267\320\272\320\260 ", Q_NULLPTR));
        shading_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \320\276\321\202\321\201\320\265\320\272\320\260\321\202\320\265\320\273\321\217", Q_NULLPTR));
        background_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \320\276\321\202\321\201\320\265\321\207\320\265\320\275\320\270\321\217", Q_NULLPTR));
        input_line->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", Q_NULLPTR));
        input_otsek->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \320\276\321\202\321\201\320\265\320\272\320\260\321\202\320\265\320\273\321\217", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\271 \321\202\320\276\321\207\320\272\320\270", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "x: ", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "y:", Q_NULLPTR));
        new_point_button->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", Q_NULLPTR));
        main_button->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\201\320\265\321\207\321\214", Q_NULLPTR));
        clear_button->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\276\321\202\321\201\320\265\320\272\320\260\321\202\320\265\320\273\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
