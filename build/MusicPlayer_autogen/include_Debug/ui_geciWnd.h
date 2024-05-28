/********************************************************************************
** Form generated from reading UI file 'geciWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GECIWND_H
#define UI_GECIWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_geciWnd
{
public:
    QVBoxLayout *verticalLayout;
    QListView *listView;

    void setupUi(QWidget *geciWnd)
    {
        if (geciWnd->objectName().isEmpty())
            geciWnd->setObjectName(QString::fromUtf8("geciWnd"));
        geciWnd->resize(643, 626);
        geciWnd->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(geciWnd);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 100, 0, 100);
        listView = new QListView(geciWnd);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));

        verticalLayout->addWidget(listView);


        retranslateUi(geciWnd);

        QMetaObject::connectSlotsByName(geciWnd);
    } // setupUi

    void retranslateUi(QWidget *geciWnd)
    {
        geciWnd->setWindowTitle(QCoreApplication::translate("geciWnd", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class geciWnd: public Ui_geciWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GECIWND_H
