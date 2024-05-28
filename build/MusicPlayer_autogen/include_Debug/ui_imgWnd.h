/********************************************************************************
** Form generated from reading UI file 'imgWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGWND_H
#define UI_IMGWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imgWnd
{
public:

    void setupUi(QWidget *imgWnd)
    {
        if (imgWnd->objectName().isEmpty())
            imgWnd->setObjectName(QString::fromUtf8("imgWnd"));
        imgWnd->resize(400, 300);

        retranslateUi(imgWnd);

        QMetaObject::connectSlotsByName(imgWnd);
    } // setupUi

    void retranslateUi(QWidget *imgWnd)
    {
        imgWnd->setWindowTitle(QCoreApplication::translate("imgWnd", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class imgWnd: public Ui_imgWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGWND_H
