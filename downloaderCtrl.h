#ifndef DOWNLOADERCTRL_H
#define DOWNLOADERCTRL_H
#include <QObject>
#include <QThread>
#include <QVariant>
#include "DataItemDef.h"
class DownLoaderHttpThread: public QThread{
    Q_OBJECT
public:
    DownLoaderHttpThread(QObject* parent=nullptr);
    void append(const QStringList& header);

Q_SIGNALS:
    void dlowndNewMusic(QSharedPointer<SoundBaseInfo>);
protected:
    void run();
private:
    struct DownLoaderHttpThreadPrivate;
    DownLoaderHttpThreadPrivate * _ptrivate;
};

class DownLoaderCtrl : public QObject{
    Q_OBJECT
public:
    DownLoaderCtrl(QObject* parent=nullptr);
    Q_INVOKABLE void addpendNew(const QString& header1,const QString& header2);
Q_SIGNALS:
    void dlowndNewMusic(QSharedPointer<SoundBaseInfo>);
private:
    struct DownLoaderCtrlPrivate;
    DownLoaderCtrlPrivate* _ptrPrivate;
};

#endif // DOWNLOADERCTRL_H
