/********************************************************************************
** Form generated from reading UI file 'OnlineCfgWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINECFGWND_H
#define UI_ONLINECFGWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OnlineCfgWnd
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEditHeader;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *plainTextEditGroup;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OnlineCfgWnd)
    {
        if (OnlineCfgWnd->objectName().isEmpty())
            OnlineCfgWnd->setObjectName(QString::fromUtf8("OnlineCfgWnd"));
        OnlineCfgWnd->resize(656, 453);
        OnlineCfgWnd->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        verticalLayout = new QVBoxLayout(OnlineCfgWnd);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        groupBox = new QGroupBox(OnlineCfgWnd);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEditHeader = new QPlainTextEdit(groupBox);
        plainTextEditHeader->setObjectName(QString::fromUtf8("plainTextEditHeader"));

        horizontalLayout->addWidget(plainTextEditHeader);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(OnlineCfgWnd);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        plainTextEditGroup = new QPlainTextEdit(groupBox_2);
        plainTextEditGroup->setObjectName(QString::fromUtf8("plainTextEditGroup"));

        verticalLayout_2->addWidget(plainTextEditGroup);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(OnlineCfgWnd);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(OnlineCfgWnd);
        QObject::connect(buttonBox, SIGNAL(accepted()), OnlineCfgWnd, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OnlineCfgWnd, SLOT(reject()));

        QMetaObject::connectSlotsByName(OnlineCfgWnd);
    } // setupUi

    void retranslateUi(QDialog *OnlineCfgWnd)
    {
        OnlineCfgWnd->setWindowTitle(QCoreApplication::translate("OnlineCfgWnd", "\345\234\250\347\272\277\344\270\213\350\275\275", nullptr));
        groupBox->setTitle(QCoreApplication::translate("OnlineCfgWnd", "Http\344\270\213\350\275\275\345\244\264", nullptr));
        plainTextEditHeader->setPlainText(QCoreApplication::translate("OnlineCfgWnd", "https://gitee.com/MarkYangUp/music/raw/master", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("OnlineCfgWnd", "\344\270\213\350\275\275\347\273\204", nullptr));
        plainTextEditGroup->setPlainText(QCoreApplication::translate("OnlineCfgWnd", "\351\243\216\351\233\250\346\227\240\351\230\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OnlineCfgWnd: public Ui_OnlineCfgWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINECFGWND_H
