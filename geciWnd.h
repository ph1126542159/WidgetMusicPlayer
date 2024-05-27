#ifndef GECIWND_H
#define GECIWND_H

#include <QWidget>
#include <QAbstractListModel>
#include "DataItemDef.h"

namespace Ui {
class geciWnd;
}
class LyricsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit LyricsModel(QObject *parent = nullptr);

    void setLyrics(const QList<QSharedPointer<LyricLine>> &lyrics);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setCurrentIndex(int idx);

    QSharedPointer<LyricLine> getData(int idx);

    void clear();
private:
    QList<QSharedPointer<LyricLine>> m_lyrics;
    int m_currentIndex;
};
class LyricsDelegate;
class geciWnd : public QWidget
{
    Q_OBJECT

public:
    explicit geciWnd(QWidget *parent = nullptr);
    ~geciWnd();
public Q_SLOTS:
    void positionChanged(int pos);
    void updateGeciModel(const QList<QSharedPointer<LyricLine>> &lyrics);
private:
    Ui::geciWnd *ui;
    LyricsModel* _lyricsModel;
    LyricsDelegate* _lyricsDelegate;
};

#endif // GECIWND_H
