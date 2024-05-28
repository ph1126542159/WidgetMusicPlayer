/********************************************************************************
** Form generated from reading UI file 'btnWnd.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTNWND_H
#define UI_BTNWND_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_btnWnd
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *btnLast;
    QPushButton *btnPlay;
    QPushButton *btnNext;
    QSlider *horizontalSlider;
    QLabel *label;

    void setupUi(QWidget *btnWnd)
    {
        if (btnWnd->objectName().isEmpty())
            btnWnd->setObjectName("btnWnd");
        btnWnd->resize(1235, 68);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnWnd->sizePolicy().hasHeightForWidth());
        btnWnd->setSizePolicy(sizePolicy);
        btnWnd->setMinimumSize(QSize(0, 50));
        btnWnd->setMaximumSize(QSize(16777215, 68));
        btnWnd->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(btnWnd);
        horizontalLayout->setSpacing(9);
        horizontalLayout->setObjectName("horizontalLayout");
        btnLast = new QPushButton(btnWnd);
        btnLast->setObjectName("btnLast");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnLast->sizePolicy().hasHeightForWidth());
        btnLast->setSizePolicy(sizePolicy1);
        btnLast->setMinimumSize(QSize(30, 30));
        btnLast->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/last.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnLast->setIcon(icon);
        btnLast->setIconSize(QSize(30, 30));
        btnLast->setFlat(true);

        horizontalLayout->addWidget(btnLast);

        btnPlay = new QPushButton(btnWnd);
        btnPlay->setObjectName("btnPlay");
        sizePolicy1.setHeightForWidth(btnPlay->sizePolicy().hasHeightForWidth());
        btnPlay->setSizePolicy(sizePolicy1);
        btnPlay->setMinimumSize(QSize(30, 30));
        btnPlay->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/play.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlay->setIcon(icon1);
        btnPlay->setIconSize(QSize(30, 30));
        btnPlay->setFlat(true);

        horizontalLayout->addWidget(btnPlay);

        btnNext = new QPushButton(btnWnd);
        btnNext->setObjectName("btnNext");
        sizePolicy1.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy1);
        btnNext->setMinimumSize(QSize(30, 30));
        btnNext->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/next.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon2);
        btnNext->setIconSize(QSize(30, 30));
        btnNext->setFlat(true);

        horizontalLayout->addWidget(btnNext);

        horizontalSlider = new QSlider(btnWnd);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        label = new QLabel(btnWnd);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);


        retranslateUi(btnWnd);

        QMetaObject::connectSlotsByName(btnWnd);
    } // setupUi

    void retranslateUi(QWidget *btnWnd)
    {
        btnWnd->setWindowTitle(QCoreApplication::translate("btnWnd", "Form", nullptr));
        btnLast->setText(QString());
        btnPlay->setText(QString());
        btnNext->setText(QString());
        label->setText(QCoreApplication::translate("btnWnd", "00\357\274\23200.00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class btnWnd: public Ui_btnWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTNWND_H
