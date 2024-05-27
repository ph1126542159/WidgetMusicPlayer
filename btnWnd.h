#ifndef BTNWND_H
#define BTNWND_H
#include <QMediaPlayer>
#include <QWidget>
#include "DataItemDef.h"
#include <QSharedPointer>

namespace Ui {
class btnWnd;
}

class btnWnd : public QWidget
{
    Q_OBJECT

public:
    explicit btnWnd(QWidget *parent = nullptr);
    ~btnWnd();
    static QString millisecondsToString(qint64 milliseconds);
Q_SIGNALS:
    void playLast();
    void playNext();
    void playRande();
    void playingChanged(bool isPlaying);
    void updateImage(const QString&);
    void positionChanged(int pos);
    void updateGeciModel(const QList<QSharedPointer<LyricLine>> &lyrics);
public Q_SLOTS:
    void playSound(QSharedPointer<SoundBaseInfo>& ptr);
    void soundValueChanged(int);
    void autoPlayTypeChanged(int);
private:
    Ui::btnWnd *ui;
    QMediaPlayer* _player;
    QSharedPointer<SoundBaseInfo> _cuurPtrData;
    int _autoPlayType=2;
};

#endif // BTNWND_H
