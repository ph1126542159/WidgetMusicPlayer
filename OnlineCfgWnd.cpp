#include "OnlineCfgWnd.h"
#include "ui_OnlineCfgWnd.h"

OnlineCfgWnd::OnlineCfgWnd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OnlineCfgWnd)
{
    ui->setupUi(this);
}

OnlineCfgWnd::~OnlineCfgWnd()
{
    delete ui;
}

QString OnlineCfgWnd::getHttpHeader()
{
return ui->plainTextEditHeader->toPlainText();
}

QString OnlineCfgWnd::getGroup()
{
    return ui->plainTextEditGroup->placeholderText();
}
