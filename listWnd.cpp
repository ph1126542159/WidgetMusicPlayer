#include "listWnd.h"
#include "ui_listWnd.h"
#include <QPainter>
#include <QFileDialog>
#include <QFileInfo>
#include <QButtonGroup>
#include <QDebug>
#include "OnlineCfgWnd.h"
listWnd::listWnd(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::listWnd)
{
    ui->setupUi(this);

    ui->btnOnlie->setToolTip(QStringLiteral("在线音乐"));
    ui->btnDanqu->setToolTip(QStringLiteral("顺序播放"));
    ui->btnRande->setToolTip(QStringLiteral("随机播放"));
    ui->btnXunhuan->setToolTip(QStringLiteral("循环播放"));
    ui->vloumeBtn->setToolTip(QStringLiteral("音量"));
    ui->selectLoaclFile->setToolTip(QStringLiteral("选择本地音乐"));

    _isNoSound = false;
    _currRow = 0;

    _ptrModel = new QStandardItemModel(0, 4, this);
    // 设置表头
    _ptrModel->setHeaderData(0, Qt::Horizontal, QStringLiteral("名称"));
    _ptrModel->setHeaderData(1, Qt::Horizontal, QStringLiteral("作者"));
    _ptrModel->setHeaderData(2, Qt::Horizontal, QStringLiteral("时长"));
    _ptrModel->setHeaderData(3, Qt::Horizontal, QStringLiteral("操作"));

    ui->tableView->setModel(_ptrModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setShowGrid(false);
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setFocusPolicy(Qt::NoFocus);



    QObject::connect(_ptrModel, &QStandardItemModel::rowsInserted, [=]() {
        if (_ptrModel->rowCount() == 1) {
            QStandardItem* item = _ptrModel->itemFromIndex(_ptrModel->index(0, 0));
            QSharedPointer<SoundBaseInfo> ptr = item->data().value<QSharedPointer<SoundBaseInfo>>();
            Q_EMIT playSound(ptr);
            _currRow = 0;
            ui->tableView->selectRow(_currRow);
        }
        });
    QObject::connect(ui->selectLoaclFile, &QPushButton::released, [=]() {
        QFileDialog dialog(this);
        dialog.setFileMode(QFileDialog::ExistingFiles);
        dialog.setNameFilter(tr("sound (*.mp3)"));
        dialog.setViewMode(QFileDialog::Detail);
        QStringList fileNames;
        if (dialog.exec()) {
            fileNames = dialog.selectedFiles();
            for (const QString& fileName : fileNames) {
                QFileInfo file(fileName);
                QSharedPointer<SoundBaseInfo> ptrData(new SoundBaseInfo());
                ptrData->name = file.fileName();
                ptrData->url = fileName;
                ptrData->imgUrl = ":/images/icon.png";

                appendNew(ptrData);
            }
        }
        });

    QObject::connect(&_downCtrl, &DownLoaderCtrl::dlowndNewMusic, this, &listWnd::appendNew);


    QButtonGroup* btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->btnDanqu, 0);
    btnGroup->addButton(ui->btnRande, 1);
    btnGroup->addButton(ui->btnXunhuan, 2);
    btnGroup->setExclusive(true);

    QObject::connect(btnGroup, &QButtonGroup::idReleased, this, &listWnd::autoPlayTypeChanged);

    QObject::connect(ui->vloumeBtn, &QPushButton::released, [=]() {
        if (_isNoSound) {
            ui->vloumeBtn->setIcon(QIcon(":/images/nosound.svg"));
            ui->horizontalSlider->setValue(0);
        }
        else {
            ui->horizontalSlider->setValue(50);
            ui->vloumeBtn->setIcon(QIcon(":/images/sound.svg"));
        }
        _isNoSound = !_isNoSound;
        Q_EMIT soundValueChanged(ui->horizontalSlider->value());
        });
    QObject::connect(ui->horizontalSlider, &QSlider::valueChanged, [=](int value) {
        if (0 == value) {
            _isNoSound = true;
            ui->vloumeBtn->setIcon(QIcon(":/images/nosound.svg"));
        }
        else {
            _isNoSound = false;
            ui->vloumeBtn->setIcon(QIcon(":/images/sound.svg"));
        }
        Q_EMIT soundValueChanged(value);
        });

    QObject::connect(ui->btnOnlie, &QPushButton::released, [=]() {
        OnlineCfgWnd cfg;
        int result = cfg.exec();
        if (result == QDialog::Rejected) return;
        qDebug() << cfg.getGroup();
        _downCtrl.addpendNew(cfg.getHttpHeader(), cfg.getGroup());
        });
}
void listWnd::appendNew(QSharedPointer<SoundBaseInfo> ptrData)
{
    QList<QStandardItem*> items;
    QStandardItem* first = new QStandardItem(ptrData->name);
    first->setData(QVariant::fromValue<QSharedPointer<SoundBaseInfo>>(ptrData));
    first->setTextAlignment(Qt::AlignCenter);
    items.append(first);
    auto second = new QStandardItem(ptrData->author);
    second->setTextAlignment(Qt::AlignCenter);
    items.append(second);
    auto third = new QStandardItem(ptrData->timesetr);
    third->setTextAlignment(Qt::AlignCenter);
    items.append(third);

    auto fourth = new QStandardItem();
    fourth->setText(QStringLiteral("  "));
    fourth->setIcon(QIcon(":/images/delete.svg"));
    items.append(fourth);
    _ptrModel->appendRow(items);
}
listWnd::~listWnd()
{
    delete ui;
}

void listWnd::playLast()
{
    _currRow--;
    if (_currRow < 0) {
        _currRow = 0;
        return;
    }
    QStandardItem* item = _ptrModel->itemFromIndex(_ptrModel->index(_currRow, 0));
    QSharedPointer<SoundBaseInfo> ptr = item->data().value<QSharedPointer<SoundBaseInfo>>();
    Q_EMIT playSound(ptr);

    ui->tableView->selectRow(_currRow);
}

void listWnd::playNext()
{
    _currRow++;
    if (_currRow >= _ptrModel->rowCount()) {
        _currRow = _ptrModel->rowCount() - 1;
        return;
    }
    QStandardItem* item = _ptrModel->itemFromIndex(_ptrModel->index(_currRow, 0));
    QSharedPointer<SoundBaseInfo> ptr = item->data().value<QSharedPointer<SoundBaseInfo>>();
    Q_EMIT playSound(ptr);
    ui->tableView->selectRow(_currRow);
}

void listWnd::playRande()
{
    _currRow = qrand() % _ptrModel->rowCount();
    QStandardItem* item = _ptrModel->itemFromIndex(_ptrModel->index(_currRow, 0));
    QSharedPointer<SoundBaseInfo> ptr = item->data().value<QSharedPointer<SoundBaseInfo>>();
    Q_EMIT playSound(ptr);
}



void listWnd::paintEvent(QPaintEvent*)
{
    // QPainter painter(this);
    // painter.fillRect(rect(), QColor("#7fb80e"));
}
