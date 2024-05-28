#include "imgWnd.h"
#include "ui_imgWnd.h"
#include <QPainter>
#include <QPainterPath>
#include <QTimer>
imgWnd::imgWnd(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::imgWnd)
{
    ui->setupUi(this);

    reLoadPixmap(":/images/icon.png");

    // 设置定时器，每隔一段时间更新旋转角度
    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, &imgWnd::updateAngle);
}

imgWnd::~imgWnd()
{
    delete ui;
}

void imgWnd::reLoadPixmap(const QString& path)
{
    QString imgPath = path;
    if (imgPath.isEmpty())imgPath = ":/images/icon.png";
    _bkImg = QPixmap(imgPath);
}




void imgWnd::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    // 计算圆形区域的中心点和半径
    QPoint center(width() / 2, height() / 2);
    int radius = qMin(width(), height()) / 4;

    // 保存当前绘图状态
    painter.save();

    QPainterPath clipPath;
    clipPath.addEllipse(center, radius, radius);
    painter.setClipPath(clipPath);

    // 缩放图片并旋转
    QPixmap scaledImage = _bkImg.scaled(2 * radius, 2 * radius, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QTransform transform;
    transform.translate(center.x(), center.y());
    transform.rotate(_angle);
    transform.translate(-center.x(), -center.y());
    painter.setTransform(transform, true);
    // 绘制旋转后的图像
    painter.drawPixmap(center.x() - scaledImage.width() / 2, center.y() - scaledImage.height() / 2, scaledImage);


    // 恢复绘图状态
    painter.restore();

    drawArc(25,radius+10,QColor("gray"),&painter);
    drawArc(10,radius+5,QColor("lightgray"),&painter);
}

void imgWnd::updateAngle()
{
    _angle += 0.4; // 每次旋转增加1度
    if (_angle >= 360) _angle -= 360; // 限制角度在 0 到 360 之间
    update(); // 更新绘图
}

void imgWnd::playingChanged(bool isPlaying)
{
    if(isPlaying)  _timer->start(50);
    else _timer->stop();
}

void imgWnd::drawArc(int penWidth, int nSize,const QColor& clr, QPainter* painter)
{
    // 设置画笔和画刷
    QPen pen(clr, penWidth);
    painter->setPen(pen);

    QPoint center = rect().center();
    QRect rect(center.x()-nSize,center.y()-nSize,nSize*2,nSize*2);

    int startAngle = 0 * 16;   // 30度
    int spanAngle = 360 * 16;   // 120度
    painter->drawArc(rect, startAngle, spanAngle);
}
