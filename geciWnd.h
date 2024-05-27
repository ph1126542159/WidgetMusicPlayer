#ifndef GECIWND_H
#define GECIWND_H

#include <QWidget>

namespace Ui {
class geciWnd;
}

class geciWnd : public QWidget
{
    Q_OBJECT

public:
    explicit geciWnd(QWidget *parent = nullptr);
    ~geciWnd();

private:
    Ui::geciWnd *ui;
};

#endif // GECIWND_H
