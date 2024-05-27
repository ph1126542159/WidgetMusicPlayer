#ifndef ONLINECFGWND_H
#define ONLINECFGWND_H

#include <QDialog>

namespace Ui {
class OnlineCfgWnd;
}

class OnlineCfgWnd : public QDialog
{
    Q_OBJECT

public:
    explicit OnlineCfgWnd(QWidget *parent = nullptr);
    ~OnlineCfgWnd();
    QString getHttpHeader();
    QString getGroup();
private:
    Ui::OnlineCfgWnd *ui;
};

#endif // ONLINECFGWND_H
