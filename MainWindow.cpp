#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QPainter>
#include "QtAdvancedStylesheet.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    acss::QtAdvancedStylesheet* AdvancedStyleSheet;
    QString AppDir = qApp->applicationDirPath();
    QString StylesDir = AppDir+"/styles";
    AdvancedStyleSheet = new acss::QtAdvancedStylesheet();
    AdvancedStyleSheet->setStylesDirPath(StylesDir);
    AdvancedStyleSheet->setOutputDirPath(AppDir + "/output");
    AdvancedStyleSheet->setCurrentStyle("qt_material");
    AdvancedStyleSheet->setCurrentTheme("light_lightgreen");
    this->setWindowIcon(AdvancedStyleSheet->styleIcon());
    AdvancedStyleSheet->updateStylesheet();
    qApp->setStyleSheet(AdvancedStyleSheet->styleSheet());

    QObject::connect(ui->listWndObj,&listWnd::soundValueChanged,ui->btnWndObj,&btnWnd::soundValueChanged);
    QObject::connect(ui->listWndObj,&listWnd::playSound,ui->btnWndObj,&btnWnd::playSound);
    QObject::connect(ui->listWndObj,&listWnd::autoPlayTypeChanged,ui->btnWndObj,&btnWnd::autoPlayTypeChanged);
    QObject::connect(ui->btnWndObj,&btnWnd::playLast,ui->listWndObj,&listWnd::playLast);
    QObject::connect(ui->btnWndObj,&btnWnd::playNext,ui->listWndObj,&listWnd::playNext);
    QObject::connect(ui->btnWndObj,&btnWnd::playingChanged,ui->imageWnd,&imgWnd::playingChanged);
    QObject::connect(ui->btnWndObj,&btnWnd::updateImage,ui->imageWnd,&imgWnd::reLoadPixmap);
    QObject::connect(ui->btnWndObj,&btnWnd::positionChanged,ui->geciWndObj,&geciWnd::positionChanged);
    QObject::connect(ui->btnWndObj,&btnWnd::updateGeciModel,ui->geciWndObj,&geciWnd::updateGeciModel);

    for (const auto& Theme : AdvancedStyleSheet->themes())
    {
        qDebug()<<Theme;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);
}

