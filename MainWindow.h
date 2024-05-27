#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DataItemDef.h"
#include <QSharedPointer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private Q_SLOTS:

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
