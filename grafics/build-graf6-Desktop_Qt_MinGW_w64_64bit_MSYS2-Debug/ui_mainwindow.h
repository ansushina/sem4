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
    QLabel *draw_label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QFrame *frame_border;
    QFrame *frame_background;
    QFrame *frame_shading;
    QPushButton *pushButton;
    QPushButton *shading_button;
    QPushButton *background_button;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *input_zatravka;
    QRadioButton *mouse_random_input;
    QRadioButton *mouse_input;
    QRadioButton *button_input;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *x_lineedit;
    QLineEdit *y_lineedit;
    QPushButton *new_point_button;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *fast_button;
    QRadioButton *slow_Button;
    QPushButton *main_button;
    QPushButton *clear_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(120);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(720, 0, 16, 861));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        draw_label = new QLabel(centralWidget);
        draw_label->setObjectName(QStringLiteral("draw_label"));
        draw_label->setGeometry(QRect(10, 10, 700, 700));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(790, 10, 361, 701));
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
        frame_border = new QFrame(verticalLayoutWidget);
        frame_border->setObjectName(QStringLiteral("frame_border"));
        frame_border->setMinimumSize(QSize(20, 20));
        frame_border->setMaximumSize(QSize(20, 20));
        frame_border->setFrameShape(QFrame::StyledPanel);
        frame_border->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_border, 0, 0, 1, 1);

        frame_background = new QFrame(verticalLayoutWidget);
        frame_background->setObjectName(QStringLiteral("frame_background"));
        frame_background->setMinimumSize(QSize(20, 20));
        frame_background->setMaximumSize(QSize(20, 20));
        frame_background->setFrameShape(QFrame::StyledPanel);
        frame_background->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_background, 2, 0, 1, 1);

        frame_shading = new QFrame(verticalLayoutWidget);
        frame_shading->setObjectName(QStringLiteral("frame_shading"));
        frame_shading->setMinimumSize(QSize(20, 20));
        frame_shading->setMaximumSize(QSize(20, 20));
        frame_shading->setFrameShape(QFrame::StyledPanel);
        frame_shading->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_shading, 1, 0, 1, 1);

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

        input_zatravka = new QRadioButton(verticalLayoutWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(input_zatravka);
        input_zatravka->setObjectName(QStringLiteral("input_zatravka"));

        verticalLayout_2->addWidget(input_zatravka);

        mouse_random_input = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(mouse_random_input);
        mouse_random_input->setObjectName(QStringLiteral("mouse_random_input"));

        verticalLayout_2->addWidget(mouse_random_input);

        mouse_input = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(mouse_input);
        mouse_input->setObjectName(QStringLiteral("mouse_input"));

        verticalLayout_2->addWidget(mouse_input);

        button_input = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(button_input);
        button_input->setObjectName(QStringLiteral("button_input"));

        verticalLayout_2->addWidget(button_input);


        verticalLayout->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
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

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fast_button = new QRadioButton(verticalLayoutWidget);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(fast_button);
        fast_button->setObjectName(QStringLiteral("fast_button"));

        horizontalLayout->addWidget(fast_button);

        slow_Button = new QRadioButton(verticalLayoutWidget);
        buttonGroup_2->addButton(slow_Button);
        slow_Button->setObjectName(QStringLiteral("slow_Button"));

        horizontalLayout->addWidget(slow_Button);


        verticalLayout->addLayout(horizontalLayout);

        main_button = new QPushButton(verticalLayoutWidget);
        main_button->setObjectName(QStringLiteral("main_button"));
        sizePolicy2.setHeightForWidth(main_button->sizePolicy().hasHeightForWidth());
        main_button->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(main_button);

        clear_button = new QPushButton(verticalLayoutWidget);
        clear_button->setObjectName(QStringLiteral("clear_button"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(clear_button->sizePolicy().hasHeightForWidth());
        clear_button->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(clear_button);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 22));
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
        draw_label->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202  \320\263\321\200\320\260\320\275\320\270\321\206\321\213", nullptr));
        shading_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \320\267\320\260\320\272\321\200\320\260\321\201\320\272\320\270", nullptr));
        background_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        input_zatravka->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \320\267\320\260\321\202\321\200\320\260\320\262\320\272\320\270", nullptr));
        mouse_random_input->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\273\321\214\320\275\320\276\320\271 \321\204\320\270\320\263\321\203\321\200\321\213 \320\274\321\213\321\210\320\272\320\276\320\271", nullptr));
        mouse_input->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \320\274\320\275\320\276\320\263\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\260 \320\274\321\213\321\210\320\272\320\276\320\271", nullptr));
        button_input->setText(QApplication::translate("MainWindow", "\320\232\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\320\275\321\213\320\271 \320\262\320\262\320\276\320\264", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\271 \321\202\320\276\321\207\320\272\320\270", nullptr));
        label->setText(QApplication::translate("MainWindow", "x: ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "y:", nullptr));
        new_point_button->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\272\320\275\321\203\321\202\321\214", nullptr));
        fast_button->setText(QApplication::translate("MainWindow", "\320\261\320\265\320\267 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\270", nullptr));
        slow_Button->setText(QApplication::translate("MainWindow", "\321\201 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\276\320\271", nullptr));
        main_button->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\320\260\321\201\320\270\321\202\321\214", nullptr));
        clear_button->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
