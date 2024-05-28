/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "btnWnd.h"
#include "geciWnd.h"
#include "imgWnd.h"
#include "listWnd.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    imgWnd *imageWnd;
    QFrame *line;
    geciWnd *geciWndObj;
    QFrame *line_2;
    listWnd *listWndObj;
    QFrame *line_3;
    btnWnd *btnWndObj;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1125, 658);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        imageWnd = new imgWnd(centralwidget);
        imageWnd->setObjectName("imageWnd");

        horizontalLayout->addWidget(imageWnd);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout->addWidget(line);

        geciWndObj = new geciWnd(centralwidget);
        geciWndObj->setObjectName("geciWndObj");
        geciWndObj->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(geciWndObj);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout->addWidget(line_2);

        listWndObj = new listWnd(centralwidget);
        listWndObj->setObjectName("listWndObj");
        listWndObj->setMinimumSize(QSize(280, 0));

        horizontalLayout->addWidget(listWndObj);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(2, 4);
        horizontalLayout->setStretch(4, 1);

        verticalLayout->addLayout(horizontalLayout);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_3);

        btnWndObj = new btnWnd(centralwidget);
        btnWndObj->setObjectName("btnWndObj");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnWndObj->sizePolicy().hasHeightForWidth());
        btnWndObj->setSizePolicy(sizePolicy);
        btnWndObj->setMinimumSize(QSize(0, 50));
        btnWndObj->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(btnWndObj);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
