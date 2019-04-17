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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFrame *frame_border;
    QFrame *frame_background;
    QFrame *frame_shading;
    QPushButton *pushButton;
    QPushButton *shading_button;
    QPushButton *background_button;
    QRadioButton *mouse_input;
    QRadioButton *button_input;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *x_lineedit;
    QLineEdit *y_lineedit;
    QPushButton *new_point_button;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *main_button;
    QPushButton *clear_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 800);
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
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(800, 10, 351, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_border = new QFrame(gridLayoutWidget);
        frame_border->setObjectName(QStringLiteral("frame_border"));
        frame_border->setMinimumSize(QSize(20, 20));
        frame_border->setMaximumSize(QSize(20, 20));
        frame_border->setFrameShape(QFrame::StyledPanel);
        frame_border->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_border, 0, 0, 1, 1);

        frame_background = new QFrame(gridLayoutWidget);
        frame_background->setObjectName(QStringLiteral("frame_background"));
        frame_background->setMinimumSize(QSize(20, 20));
        frame_background->setMaximumSize(QSize(20, 20));
        frame_background->setFrameShape(QFrame::StyledPanel);
        frame_background->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_background, 2, 0, 1, 1);

        frame_shading = new QFrame(gridLayoutWidget);
        frame_shading->setObjectName(QStringLiteral("frame_shading"));
        frame_shading->setMinimumSize(QSize(20, 20));
        frame_shading->setMaximumSize(QSize(20, 20));
        frame_shading->setFrameShape(QFrame::StyledPanel);
        frame_shading->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_shading, 1, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        shading_button = new QPushButton(gridLayoutWidget);
        shading_button->setObjectName(QStringLiteral("shading_button"));

        gridLayout->addWidget(shading_button, 1, 1, 1, 1);

        background_button = new QPushButton(gridLayoutWidget);
        background_button->setObjectName(QStringLiteral("background_button"));

        gridLayout->addWidget(background_button, 2, 1, 1, 1);

        mouse_input = new QRadioButton(centralWidget);
        mouse_input->setObjectName(QStringLiteral("mouse_input"));
        mouse_input->setGeometry(QRect(900, 160, 251, 23));
        button_input = new QRadioButton(centralWidget);
        button_input->setObjectName(QStringLiteral("button_input"));
        button_input->setGeometry(QRect(900, 200, 301, 23));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(830, 250, 311, 151));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(70, 30, 160, 80));
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
        new_point_button->setGeometry(QRect(70, 110, 161, 25));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(860, 430, 261, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_2);

        main_button = new QPushButton(verticalLayoutWidget);
        main_button->setObjectName(QStringLiteral("main_button"));
        sizePolicy.setHeightForWidth(main_button->sizePolicy().hasHeightForWidth());
        main_button->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(main_button);

        clear_button = new QPushButton(verticalLayoutWidget);
        clear_button->setObjectName(QStringLiteral("clear_button"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(clear_button->sizePolicy().hasHeightForWidth());
        clear_button->setSizePolicy(sizePolicy1);

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        draw_label->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202  \320\263\321\200\320\260\320\275\320\270\321\206\321\213", Q_NULLPTR));
        shading_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \320\267\320\260\320\272\321\200\320\260\321\201\320\272\320\270", Q_NULLPTR));
        background_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", Q_NULLPTR));
        mouse_input->setText(QApplication::translate("MainWindow", "\320\234\321\213\321\210\320\270\320\275\321\213\320\271 \320\262\320\262\320\276\320\264", Q_NULLPTR));
        button_input->setText(QApplication::translate("MainWindow", "\320\232\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\320\275\321\213\320\271 \320\262\320\262\320\276\320\264", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\271 \321\202\320\276\321\207\320\272\320\270", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "x: ", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "y:", Q_NULLPTR));
        new_point_button->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\272\320\275\321\203\321\202\321\214", Q_NULLPTR));
        main_button->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\320\260\321\201\320\270\321\202\321\214", Q_NULLPTR));
        clear_button->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
