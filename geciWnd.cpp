#include "geciWnd.h"
#include "ui_geciWnd.h"

geciWnd::geciWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::geciWnd)
{
    ui->setupUi(this);
}

geciWnd::~geciWnd()
{
    delete ui;
}
