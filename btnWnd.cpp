#include "btnWnd.h"
#include "ui_btnWnd.h"
#include <QUrl>



btnWnd::btnWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::btnWnd)
{
    ui->setupUi(this);
    _player=new QMediaPlayer(this);
    _player->setVolume(50);

    QObject::connect(_player,&QMediaPlayer::positionChanged,[=](qint64 position){
        ui->horizontalSlider->setValue(position);
        if(_cuurPtrData.isNull()) return;
        qint64 dura=_player->duration();
        if(0==dura){
            dura=_cuurPtrData->totalNum;
        }
        QString strLabel= millisecondsToString(dura-position);
        ui->label->setText(strLabel);
    });

    QObject::connect(_player,&QMediaPlayer::mediaStatusChanged,[=](QMediaPlayer::MediaStatus status){
        if(_cuurPtrData.isNull()) return;
        qDebug()<<status;
        if(status==QMediaPlayer::BufferedMedia){
            qint64 dura=_player->duration();
            if(0==dura){
                dura=_cuurPtrData->totalNum;
            }
            ui->horizontalSlider->setRange(0,dura);
        }else if(status==QMediaPlayer::EndOfMedia){
            if(0==_autoPlayType){
                _player->play();
            }else if(1==_autoPlayType){
                Q_EMIT  playRande();
            }else if(2==_autoPlayType){
                Q_EMIT playNext();
            }
        }
    });
    QObject::connect(_player,&QMediaPlayer::stateChanged,[=](QMediaPlayer::State newState){
        if(newState==QMediaPlayer::PlayingState) Q_EMIT playingChanged(true);
        else Q_EMIT playingChanged(false);
    });

    QObject::connect(ui->horizontalSlider, &QSlider::valueChanged, _player, &QMediaPlayer::setPosition);

    QObject::connect(ui->btnLast,&QPushButton::released,this,&btnWnd::playLast);
    QObject::connect(ui->btnPlay,&QPushButton::released,[=](){
        if(_player->state()==QMediaPlayer::PlayingState) {
            _player->pause();
            ui->btnPlay->setIcon(QIcon(":/images/pause.svg"));
        }
        else {
            _player->play();
            ui->btnPlay->setIcon(QIcon(":/images/play.svg"));
        }
    });
    QObject::connect(ui->btnNext,&QPushButton::released,this,&btnWnd::playNext);
}

btnWnd::~btnWnd()
{
    delete ui;
}

void btnWnd::playSound(QSharedPointer<SoundBaseInfo> &ptr)
{
    _cuurPtrData=ptr;
    _player->setMedia(QUrl(ptr->url));
    _player->play();
    Q_EMIT updateImage(ptr->imgUrl);
}

void btnWnd::soundValueChanged(int valuse)
{
    _player->setVolume(valuse);
}

void btnWnd::autoPlayTypeChanged(int type)
{
    _autoPlayType=type;
}
QString btnWnd::millisecondsToString(qint64 milliseconds) {
    qint64 totalSeconds = milliseconds / 1000;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    int millisecondsPart = (milliseconds % 1000) / 10;

    return QString("%1:%2.%3")
            .arg(minutes, 2, 10, QLatin1Char('0'))
            .arg(seconds, 2, 10, QLatin1Char('0'))
            .arg(millisecondsPart, 2, 10, QLatin1Char('0'));
}
