#ifndef LISTWND_H
#define LISTWND_H

#include <QWidget>
#include "DataItemDef.h"
#include <QSharedPointer>
#include <QStandardItemModel>
#include "downloaderCtrl.h"
namespace Ui {
class listWnd;
}

class listWnd : public QWidget
{
    Q_OBJECT

public:
    explicit listWnd(QWidget *parent = nullptr);
    ~listWnd();
Q_SIGNALS:
    void playSound(QSharedPointer<SoundBaseInfo>& ptr);
    void soundValueChanged(int);
    void autoPlayTypeChanged(int);
public Q_SLOTS:
    void playLast();
    void playNext();
    void playRande();
    void appendNew(QSharedPointer<SoundBaseInfo> ptr);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::listWnd *ui;
    QStandardItemModel* _ptrModel;
    int _currRow=0;
    bool _isNoSound=false;
    DownLoaderCtrl _downCtrl;
};

#endif // LISTWND_H
