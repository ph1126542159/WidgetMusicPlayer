#ifndef IMGWND_H
#define IMGWND_H

#include <QWidget>
#include <QPixmap>
namespace Ui {
class imgWnd;
}

class imgWnd : public QWidget
{
    Q_OBJECT

public:
    explicit imgWnd(QWidget *parent = nullptr);
    ~imgWnd();
protected:
    void paintEvent(QPaintEvent *event) override;
public slots:
    void updateAngle();
    void playingChanged(bool isPlaying);
    void reLoadPixmap(const QString& path);
private:
    void scaleAndRotateImage();
    void drawArc(int penWidth,int nSize,const QColor& clr,QPainter* painter);
    Ui::imgWnd *ui;
    QPixmap _bkImg;
    QTimer *_timer;
    qreal _angle=0;
};

#endif // IMGWND_H
