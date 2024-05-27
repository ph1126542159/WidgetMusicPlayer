#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->listWndObj,&listWnd::soundValueChanged,ui->btnWndObj,&btnWnd::soundValueChanged);
    QObject::connect(ui->listWndObj,&listWnd::playSound,ui->btnWndObj,&btnWnd::playSound);
    QObject::connect(ui->listWndObj,&listWnd::autoPlayTypeChanged,ui->btnWndObj,&btnWnd::autoPlayTypeChanged);
    QObject::connect(ui->btnWndObj,&btnWnd::playLast,ui->listWndObj,&listWnd::playLast);
    QObject::connect(ui->btnWndObj,&btnWnd::playNext,ui->listWndObj,&listWnd::playNext);
    QObject::connect(ui->btnWndObj,&btnWnd::playingChanged,ui->imageWnd,&imgWnd::playingChanged);
    QObject::connect(ui->btnWndObj,&btnWnd::updateImage,ui->imageWnd,&imgWnd::reLoadPixmap);
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

