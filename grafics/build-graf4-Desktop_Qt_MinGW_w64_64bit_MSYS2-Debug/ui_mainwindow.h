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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *x_okr;
    QLabel *label_2;
    QLineEdit *y_okr;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *r_okr;
    QPushButton *main_button;
    QLabel *label_5;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLineEdit *x_el;
    QLabel *label_9;
    QLineEdit *y_el;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLineEdit *a_el;
    QLabel *label_11;
    QLineEdit *b_el;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_9;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_12;
    QLineEdit *lineEdit_3;
    QLabel *label_13;
    QLineEdit *lineEdit_4;
    QLabel *label_14;
    QLineEdit *lineEdit_5;
    QLabel *label_15;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_16;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLabel *label_17;
    QRadioButton *radioButton_norm;
    QRadioButton *radioButton_fon;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *color_button;
    QLabel *label_18;
    QFrame *frame;
    QLabel *label_19;
    QFrame *frame_3;
    QPushButton *color_fon_button_2;
    QLabel *draw_label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_3;
    QButtonGroup *buttonGroup_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1250, 850);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(730, 40, 251, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        x_okr = new QLineEdit(verticalLayoutWidget);
        x_okr->setObjectName(QStringLiteral("x_okr"));

        horizontalLayout->addWidget(x_okr);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        y_okr = new QLineEdit(verticalLayoutWidget);
        y_okr->setObjectName(QStringLiteral("y_okr"));

        horizontalLayout->addWidget(y_okr);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        r_okr = new QLineEdit(verticalLayoutWidget);
        r_okr->setObjectName(QStringLiteral("r_okr"));

        horizontalLayout_2->addWidget(r_okr);


        verticalLayout->addLayout(horizontalLayout_2);

        main_button = new QPushButton(centralWidget);
        main_button->setObjectName(QStringLiteral("main_button"));
        main_button->setGeometry(QRect(880, 350, 231, 41));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(860, 130, 264, 19));
        radioButton_5 = new QRadioButton(centralWidget);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(radioButton_5);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(860, 271, 264, 23));
        radioButton_3 = new QRadioButton(centralWidget);
        buttonGroup_2->addButton(radioButton_3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(860, 213, 264, 23));
        radioButton_4 = new QRadioButton(centralWidget);
        buttonGroup_2->addButton(radioButton_4);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(860, 242, 264, 23));
        radioButton = new QRadioButton(centralWidget);
        buttonGroup_2->addButton(radioButton);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(860, 155, 264, 23));
        radioButton_2 = new QRadioButton(centralWidget);
        buttonGroup_2->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(860, 184, 264, 23));
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(990, 40, 251, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        x_el = new QLineEdit(verticalLayoutWidget_2);
        x_el->setObjectName(QStringLiteral("x_el"));

        horizontalLayout_3->addWidget(x_el);

        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        y_el = new QLineEdit(verticalLayoutWidget_2);
        y_el->setObjectName(QStringLiteral("y_el"));

        horizontalLayout_3->addWidget(y_el);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        a_el = new QLineEdit(verticalLayoutWidget_2);
        a_el->setObjectName(QStringLiteral("a_el"));

        horizontalLayout_4->addWidget(a_el);

        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_4->addWidget(label_11);

        b_el = new QLineEdit(verticalLayoutWidget_2);
        b_el->setObjectName(QStringLiteral("b_el"));

        horizontalLayout_4->addWidget(b_el);


        verticalLayout_2->addLayout(horizontalLayout_4);

        radioButton_8 = new QRadioButton(centralWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_8);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        radioButton_8->setGeometry(QRect(770, 10, 112, 23));
        radioButton_9 = new QRadioButton(centralWidget);
        buttonGroup->addButton(radioButton_9);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));
        radioButton_9->setGeometry(QRect(1070, 10, 112, 23));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(720, 520, 261, 231));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 200, 75, 23));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 20, 211, 181));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_12);

        lineEdit_3 = new QLineEdit(formLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_13);

        lineEdit_4 = new QLineEdit(formLayoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        label_14 = new QLabel(formLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_14);

        lineEdit_5 = new QLineEdit(formLayoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_5);

        label_15 = new QLabel(formLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_15);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(980, 520, 261, 231));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 200, 75, 23));
        formLayoutWidget_2 = new QWidget(groupBox_2);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(20, 20, 211, 181));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(formLayoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_16);

        lineEdit_6 = new QLineEdit(formLayoutWidget_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_6);

        lineEdit_7 = new QLineEdit(formLayoutWidget_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_7);

        label_17 = new QLabel(formLayoutWidget_2);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_17);

        radioButton_norm = new QRadioButton(centralWidget);
        buttonGroup_3 = new QButtonGroup(MainWindow);
        buttonGroup_3->setObjectName(QStringLiteral("buttonGroup_3"));
        buttonGroup_3->addButton(radioButton_norm);
        radioButton_norm->setObjectName(QStringLiteral("radioButton_norm"));
        radioButton_norm->setGeometry(QRect(890, 320, 112, 23));
        radioButton_fon = new QRadioButton(centralWidget);
        buttonGroup_3->addButton(radioButton_fon);
        radioButton_fon->setObjectName(QStringLiteral("radioButton_fon"));
        radioButton_fon->setGeometry(QRect(1000, 320, 112, 23));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(880, 410, 231, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        color_button = new QPushButton(gridLayoutWidget);
        color_button->setObjectName(QStringLiteral("color_button"));

        gridLayout->addWidget(color_button, 0, 2, 1, 1);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout->addWidget(label_18, 0, 0, 1, 1);

        frame = new QFrame(gridLayoutWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 0, 1, 1, 1);

        label_19 = new QLabel(gridLayoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout->addWidget(label_19, 1, 0, 1, 1);

        frame_3 = new QFrame(gridLayoutWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_3, 1, 1, 1, 1);

        color_fon_button_2 = new QPushButton(gridLayoutWidget);
        color_fon_button_2->setObjectName(QStringLiteral("color_fon_button_2"));

        gridLayout->addWidget(color_fon_button_2, 1, 2, 1, 1);

        draw_label = new QLabel(centralWidget);
        draw_label->setObjectName(QStringLiteral("draw_label"));
        draw_label->setGeometry(QRect(10, 10, 700, 700));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1250, 17));
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
        label->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\320\270 ", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Xc: ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Yc: ", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "R: ", nullptr));
        main_button->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 ", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        radioButton_5->setText(QApplication::translate("MainWindow", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\321\207\320\275\320\260\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 ", nullptr));
        radioButton_3->setText(QApplication::translate("MainWindow", "\320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260", nullptr));
        radioButton_4->setText(QApplication::translate("MainWindow", "\320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \321\201\321\200\320\265\320\264\320\275\320\265\320\271 \321\202\320\276\321\207\320\272\320\270", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "\320\272\320\260\320\275\320\276\320\275\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\215\320\273\320\273\320\270\320\277\321\201\320\260", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Xc: ", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Yc: ", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "a: ", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "b:", nullptr));
        radioButton_8->setText(QApplication::translate("MainWindow", "\320\236\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        radioButton_9->setText(QApplication::translate("MainWindow", "\320\255\320\273\320\273\320\270\320\277\321\201", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\206\320\265\320\275\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Xc", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Yc", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "R\320\275\320\260\321\207", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "deltaR", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "N", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\206\320\265\320\275\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \321\215\320\273\320\273\320\270\320\277\321\201\321\213", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Yc", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "Xc", nullptr));
        radioButton_norm->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\271 \321\206\320\262\320\265\321\202", nullptr));
        radioButton_fon->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        color_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\271 \321\206\320\262\320\265\321\202", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        color_fon_button_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        draw_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
