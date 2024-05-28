#include "geciWnd.h"
#include "ui_geciWnd.h"
#include <QStyledItemDelegate>
#include <QPainter>
#include <QDebug>

LyricsModel::LyricsModel(QObject *parent)
    : QAbstractListModel(parent), m_currentIndex(-1) {}

void LyricsModel::setLyrics(const QList<QSharedPointer<LyricLine>> &lyrics) {
    beginResetModel();
    m_lyrics = lyrics;
    endResetModel();
}

int LyricsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_lyrics.size();
}

QVariant LyricsModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid() || index.row() >= m_lyrics.size())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::UserRole)
        return QVariant::fromValue(m_lyrics.at(index.row()));

    return QVariant();
}

void LyricsModel::setCurrentIndex(int idx) {
    if (m_currentIndex != idx) {
        m_currentIndex = idx;
        emit dataChanged(index(idx), index(idx));
    }
}

QSharedPointer<LyricLine> LyricsModel::getData(int idx)
{
    if(m_lyrics.count()<idx+1) return {};

    return m_lyrics[idx];
}

void LyricsModel::clear()
{
    m_lyrics.clear();
}

class LyricsDelegate : public QStyledItemDelegate
{
public:
    explicit LyricsDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        Q_UNUSED(index)
        QSize size = QStyledItemDelegate::sizeHint(option, index);
        size.setHeight(size.height() + 20); // 增加 10 像素的高度作为间距
        return size;
    }
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        if (!index.isValid())
            return;

        QSharedPointer<LyricLine> lyrcData = index.data(Qt::DisplayRole).value<QSharedPointer<LyricLine>>();
        if(lyrcData->highlight)
            painter->setPen(Qt::red);
        else
            painter->setPen(Qt::black);

        QFont font = painter->font();
        font.setPointSize(12); // 设置字体大小为 16 像素
        font.setFamily(QStringLiteral("微软雅黑")); // 设置字体为微软雅黑
        painter->setFont(font);

        painter->save();
        painter->drawText(option.rect, Qt::AlignCenter, lyrcData->text);
        painter->restore();
    }

};

geciWnd::geciWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::geciWnd)
{
    ui->setupUi(this);

    ui->listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    _lyricsModel=new LyricsModel(this);
    _lyricsDelegate=new LyricsDelegate(this);
    ui->listView->setModel(_lyricsModel);
    ui->listView->setItemDelegate(_lyricsDelegate);
}

geciWnd::~geciWnd()
{
    delete ui;
}

void geciWnd::positionChanged(int pos)
{
    int index=-1;
    for (int i = 0; i < _lyricsModel->rowCount(); ++i) {
        auto item=_lyricsModel->getData(i);
        if (pos >= item->time) {
            if (i > 0) {
                _lyricsModel->getData(i-1)->highlight=false;
            }
            item->highlight=true;
            index=i;
        }
    }
    if(-1!=index){
        _lyricsModel->setCurrentIndex(index);
        index+=5;
        if(index<=_lyricsModel->rowCount()-1)
            ui->listView->scrollTo(_lyricsModel->index(index));
        else{
            ui->listView->scrollTo(_lyricsModel->index(_lyricsModel->rowCount()-1));
        }
        ui->listView->viewport()->update();
    }

}

void geciWnd::updateGeciModel(const QList<QSharedPointer<LyricLine> > &lyrics)
{
    _lyricsModel->clear();
    _lyricsModel->setLyrics(lyrics);
    ui->listView->scrollTo(_lyricsModel->index(0));
}
