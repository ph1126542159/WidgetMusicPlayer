/********************************************************************************
** Form generated from reading UI file 'listWnd.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWND_H
#define UI_LISTWND_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listWnd
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOnlie;
    QPushButton *selectLoaclFile;
    QTableView *tableView;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnDanqu;
    QPushButton *btnXunhuan;
    QPushButton *btnRande;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *vloumeBtn;
    QSlider *horizontalSlider;

    void setupUi(QWidget *listWnd)
    {
        if (listWnd->objectName().isEmpty())
            listWnd->setObjectName("listWnd");
        listWnd->resize(304, 811);
        listWnd->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(listWnd);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOnlie = new QPushButton(listWnd);
        btnOnlie->setObjectName("btnOnlie");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnOnlie->sizePolicy().hasHeightForWidth());
        btnOnlie->setSizePolicy(sizePolicy);
        btnOnlie->setMinimumSize(QSize(32, 32));
        btnOnlie->setMaximumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/24gf-folderShare.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnOnlie->setIcon(icon);
        btnOnlie->setIconSize(QSize(32, 32));
        btnOnlie->setFlat(true);

        horizontalLayout->addWidget(btnOnlie);

        selectLoaclFile = new QPushButton(listWnd);
        selectLoaclFile->setObjectName("selectLoaclFile");
        sizePolicy.setHeightForWidth(selectLoaclFile->sizePolicy().hasHeightForWidth());
        selectLoaclFile->setSizePolicy(sizePolicy);
        selectLoaclFile->setMinimumSize(QSize(32, 32));
        selectLoaclFile->setMaximumSize(QSize(32, 32));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/24gf-folderPlus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        selectLoaclFile->setIcon(icon1);
        selectLoaclFile->setIconSize(QSize(32, 32));
        selectLoaclFile->setFlat(true);

        horizontalLayout->addWidget(selectLoaclFile);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(listWnd);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8("QTableView{\n"
"	background-color: transparent;\n"
"	border:none;\n"
"}"));

        verticalLayout->addWidget(tableView);

        line = new QFrame(listWnd);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnDanqu = new QPushButton(listWnd);
        btnDanqu->setObjectName("btnDanqu");
        sizePolicy.setHeightForWidth(btnDanqu->sizePolicy().hasHeightForWidth());
        btnDanqu->setSizePolicy(sizePolicy);
        btnDanqu->setMinimumSize(QSize(32, 32));
        btnDanqu->setMaximumSize(QSize(32, 32));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/one.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnDanqu->setIcon(icon2);
        btnDanqu->setIconSize(QSize(32, 32));
        btnDanqu->setCheckable(true);
        btnDanqu->setFlat(true);

        horizontalLayout_2->addWidget(btnDanqu);

        btnXunhuan = new QPushButton(listWnd);
        btnXunhuan->setObjectName("btnXunhuan");
        sizePolicy.setHeightForWidth(btnXunhuan->sizePolicy().hasHeightForWidth());
        btnXunhuan->setSizePolicy(sizePolicy);
        btnXunhuan->setMinimumSize(QSize(32, 32));
        btnXunhuan->setMaximumSize(QSize(32, 32));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/loop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnXunhuan->setIcon(icon3);
        btnXunhuan->setIconSize(QSize(32, 32));
        btnXunhuan->setCheckable(true);
        btnXunhuan->setChecked(true);
        btnXunhuan->setFlat(true);

        horizontalLayout_2->addWidget(btnXunhuan);

        btnRande = new QPushButton(listWnd);
        btnRande->setObjectName("btnRande");
        sizePolicy.setHeightForWidth(btnRande->sizePolicy().hasHeightForWidth());
        btnRande->setSizePolicy(sizePolicy);
        btnRande->setMinimumSize(QSize(32, 32));
        btnRande->setMaximumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/rand.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnRande->setIcon(icon4);
        btnRande->setIconSize(QSize(32, 32));
        btnRande->setCheckable(true);
        btnRande->setFlat(true);

        horizontalLayout_2->addWidget(btnRande);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(6, -1, 6, -1);
        vloumeBtn = new QPushButton(listWnd);
        vloumeBtn->setObjectName("vloumeBtn");
        sizePolicy.setHeightForWidth(vloumeBtn->sizePolicy().hasHeightForWidth());
        vloumeBtn->setSizePolicy(sizePolicy);
        vloumeBtn->setMinimumSize(QSize(32, 32));
        vloumeBtn->setMaximumSize(QSize(32, 32));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/sound.svg"), QSize(), QIcon::Normal, QIcon::Off);
        vloumeBtn->setIcon(icon5);
        vloumeBtn->setIconSize(QSize(32, 32));
        vloumeBtn->setFlat(true);

        horizontalLayout_3->addWidget(vloumeBtn);

        horizontalSlider = new QSlider(listWnd);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(listWnd);

        QMetaObject::connectSlotsByName(listWnd);
    } // setupUi

    void retranslateUi(QWidget *listWnd)
    {
        listWnd->setWindowTitle(QCoreApplication::translate("listWnd", "Form", nullptr));
        btnOnlie->setText(QString());
        selectLoaclFile->setText(QString());
        btnDanqu->setText(QString());
        btnXunhuan->setText(QString());
        btnRande->setText(QString());
        vloumeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class listWnd: public Ui_listWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWND_H
