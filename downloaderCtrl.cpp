﻿#include "downloaderCtrl.h"
#include <atomic>
#include <QQueue>
#include <mutex>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QFile>
#include <QIODevice>
#include <QDir>
#include <QImage>
#include <QPixmap>
#include "btnWnd.h"
#include <QDebug>

bool downloadFile(const QString &urlStr, QByteArray &bt)
{
    QNetworkAccessManager manager;
    QUrl url(urlStr);
    QUrl encodedUrl = QUrl::fromEncoded(url.toEncoded());
    qDebug() << "Encoded URL:" << encodedUrl;
    QNetworkRequest request(encodedUrl);

    QNetworkReply *reply = manager.get(request);

    // 使用事件循环来阻塞直到下载完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // 检查下载是否成功
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "Error:" << reply->errorString();
        reply->deleteLater();
        return false;
    }

    bt.clear();
    bt = reply->readAll();
    reply->deleteLater();
    return true;
}
QJsonObject byteArrayToJsonObject(const QByteArray &byteArray)
{
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray, &parseError);

    if (parseError.error != QJsonParseError::NoError)
    {
        qWarning() << "Failed to parse JSON:" << parseError.errorString();
        return QJsonObject();
    }

    if (!jsonDoc.isObject())
    {
        qWarning() << "JSON is not an object.";
        return QJsonObject();
    }

    return jsonDoc.object();
}
struct DownLoaderHttpThread::DownLoaderHttpThreadPrivate
{
    std::atomic_bool _stop{false};
    QQueue<QStringList> _listDown;
    std::mutex _mtx;
};
DownLoaderHttpThread::DownLoaderHttpThread(QObject *parent)
{
    _ptrivate = new DownLoaderHttpThreadPrivate();
}

void DownLoaderHttpThread::append(const QStringList &header)
{
    std::unique_lock<std::mutex> lock(_ptrivate->_mtx);
    _ptrivate->_listDown.enqueue(header);
}
int getMilliseconds(const QString &timeString)
{
    QStringList parts = timeString.split(":");
    int minutes = parts[0].toInt();
    int seconds = parts[1].section('.', 0, 0).toInt();
    int milliseconds = parts[1].section('.', 1, 1).toInt();

    // 转换为毫秒
    int totalTime = minutes * 60 * 1000 + seconds * 1000 + milliseconds;
    return totalTime;
}
void parseLyrics(QList<QSharedPointer<LyricLine>> &list, const QString &lyrics)
{
    QStringList lines = lyrics.split("\\r\\n");
    list.clear();
    for (int i = 0; i < lines.size(); i++)
    {
        QString line = lines[i];
        QStringList parts = line.split("]");
        if (parts.length() >= 2)
        {
            QString timeStr = parts.first().mid(1); // 去掉左括号
            QString text = parts.last().trimmed();
            int time = getMilliseconds(timeStr);
            QSharedPointer<LyricLine> lyricLine(new LyricLine());
            lyricLine->time = time;
            lyricLine->text = text;
            list.append(lyricLine);
        }
    }
}
void DownLoaderHttpThread::run()
{
    while (!_ptrivate->_stop)
    {
        QThread::msleep(100);
        QStringList strHeader;
        {
            std::unique_lock<std::mutex> lock(_ptrivate->_mtx);
            if (!_ptrivate->_listDown.isEmpty())
            {
                strHeader = _ptrivate->_listDown.takeFirst();
            }
        }

        if (strHeader.isEmpty())
        {
            QThread::msleep(1000);
            continue;
        }
        QByteArray bt;
        downloadFile(strHeader[0] + "/" + strHeader[1] + "/music.json", bt);

        QJsonObject listObj = byteArrayToJsonObject(bt);
        if (listObj.isEmpty())
            continue;

        QJsonArray arr = listObj["list"].toArray();

        foreach (auto it, arr)
        {
            QJsonObject obj = it.toObject();
            QSharedPointer<SoundBaseInfo> ptrData(new SoundBaseInfo());

            ptrData->name = obj["albumName"].toString();
            ptrData->author = obj["musicName"].toString().remove("-"+ptrData->name);

            ptrData->totalNum = obj["duration"].toInt() * 1000;
            ptrData->timesetr = btnWnd::millisecondsToString(ptrData->totalNum);

            QString dirPath = "./temp" + obj["path"].toString();
            QDir dir;
            dir.mkpath(dirPath);

            QString musicStr = strHeader[0] + obj["path"].toString() + "/" + obj["mp3"].toString();
            if (downloadFile(musicStr, bt))
            {
                QString filePath = dirPath + "/" + obj["mp3"].toString();

                QFile file(filePath);
                file.remove();

                if (file.open(QIODevice::WriteOnly))
                {
                    file.write(bt);
                    file.close();
                    ptrData->url = filePath;
                }
                else
                {
                    qDebug() << file.errorString();
                    continue;
                }
            }
            QString imgStr = strHeader[0] + obj["path"].toString() + "/" + obj["img"].toString();
            if (downloadFile(imgStr, bt))
            {
                QString filePath = dirPath + "/" + obj["img"].toString();

                QFile file(filePath);
                file.remove();

                if (file.open(QIODevice::WriteOnly))
                {
                    file.write(bt);
                    file.close();
                    ptrData->imgUrl = filePath;
                }
                else
                {
                    qDebug() << file.errorString();
                }
            }
            QString geciStr = strHeader[0] + obj["path"].toString() + "/" + obj["lyric"].toString();
            if (downloadFile(geciStr, bt))
            {
                parseLyrics(ptrData->geCi, bt);
            }

            Q_EMIT dlowndNewMusic(ptrData);
        }
    }
}

struct DownLoaderCtrl::DownLoaderCtrlPrivate
{
    DownLoaderHttpThread _thread;
};

DownLoaderCtrl::DownLoaderCtrl(QObject *parent)
{
    _ptrPrivate = new DownLoaderCtrlPrivate();
    QObject::connect(&_ptrPrivate->_thread, &DownLoaderHttpThread::dlowndNewMusic, this, &DownLoaderCtrl::dlowndNewMusic);
    _ptrPrivate->_thread.start();
}

void DownLoaderCtrl::addpendNew(const QString &header1, const QString &header2)
{
    QStringList list;
    list << header1;
    list << header2;
    _ptrPrivate->_thread.append(list);
}
