#include "MainWindow.h"
#include <QApplication>
#include <QDebug>
#include <QDir>
#include "DataItemDef.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir::setCurrent(a.applicationDirPath());
    qRegisterMetaType<QSharedPointer<SoundBaseInfo>>();

    MainWindow w;

    w.show();
    return a.exec();
}
