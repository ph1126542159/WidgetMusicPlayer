#ifndef DATAITEMDEF_H
#define DATAITEMDEF_H
#include <QSharedPointer>
#include <QString>
#include <QList>
struct LyricLine {
    qint64 time;
    QString text;
    bool highlight=false;
};
struct SoundBaseInfo
{
    QString url;
    QString imgUrl;
    QString   name;
    QString  author=QStringLiteral("未知");
    QString timesetr="00:00.00";
    int totalNum=0;
    QList<QSharedPointer<LyricLine>>    geCi;
};
Q_DECLARE_METATYPE(LyricLine)
Q_DECLARE_METATYPE(QSharedPointer<LyricLine>)
Q_DECLARE_METATYPE(SoundBaseInfo)
Q_DECLARE_METATYPE(QSharedPointer<SoundBaseInfo>)
#endif // DATAITEMDEF_H
