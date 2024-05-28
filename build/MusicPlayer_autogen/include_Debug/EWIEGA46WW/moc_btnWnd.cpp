/****************************************************************************
** Meta object code from reading C++ file 'btnWnd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../btnWnd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'btnWnd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_btnWnd_t {
    QByteArrayData data[18];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_btnWnd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_btnWnd_t qt_meta_stringdata_btnWnd = {
    {
QT_MOC_LITERAL(0, 0, 6), // "btnWnd"
QT_MOC_LITERAL(1, 7, 8), // "playLast"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 8), // "playNext"
QT_MOC_LITERAL(4, 26, 9), // "playRande"
QT_MOC_LITERAL(5, 36, 14), // "playingChanged"
QT_MOC_LITERAL(6, 51, 9), // "isPlaying"
QT_MOC_LITERAL(7, 61, 11), // "updateImage"
QT_MOC_LITERAL(8, 73, 15), // "positionChanged"
QT_MOC_LITERAL(9, 89, 3), // "pos"
QT_MOC_LITERAL(10, 93, 15), // "updateGeciModel"
QT_MOC_LITERAL(11, 109, 33), // "QList<QSharedPointer<LyricLin..."
QT_MOC_LITERAL(12, 143, 6), // "lyrics"
QT_MOC_LITERAL(13, 150, 9), // "playSound"
QT_MOC_LITERAL(14, 160, 30), // "QSharedPointer<SoundBaseInfo>&"
QT_MOC_LITERAL(15, 191, 3), // "ptr"
QT_MOC_LITERAL(16, 195, 17), // "soundValueChanged"
QT_MOC_LITERAL(17, 213, 19) // "autoPlayTypeChanged"

    },
    "btnWnd\0playLast\0\0playNext\0playRande\0"
    "playingChanged\0isPlaying\0updateImage\0"
    "positionChanged\0pos\0updateGeciModel\0"
    "QList<QSharedPointer<LyricLine> >\0"
    "lyrics\0playSound\0QSharedPointer<SoundBaseInfo>&\0"
    "ptr\0soundValueChanged\0autoPlayTypeChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_btnWnd[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,
       8,    1,   73,    2, 0x06 /* Public */,
      10,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   79,    2, 0x0a /* Public */,
      16,    1,   82,    2, 0x0a /* Public */,
      17,    1,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void btnWnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<btnWnd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playLast(); break;
        case 1: _t->playNext(); break;
        case 2: _t->playRande(); break;
        case 3: _t->playingChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->updateImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->positionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateGeciModel((*reinterpret_cast< const QList<QSharedPointer<LyricLine> >(*)>(_a[1]))); break;
        case 7: _t->playSound((*reinterpret_cast< QSharedPointer<SoundBaseInfo>(*)>(_a[1]))); break;
        case 8: _t->soundValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->autoPlayTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSharedPointer<LyricLine> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (btnWnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&btnWnd::playLast)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (btnWnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&btnWnd::playNext)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (btnWnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&btnWnd::playRande)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (btnWnd::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&btnWnd::playingChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (btnWnd::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&btnWnd::updateImage)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (btnWnd::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&btnWnd::positionChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (btnWnd::*)(const QList<QSharedPointer<LyricLine>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&btnWnd::updateGeciModel)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject btnWnd::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_btnWnd.data,
    qt_meta_data_btnWnd,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *btnWnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *btnWnd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_btnWnd.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int btnWnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void btnWnd::playLast()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void btnWnd::playNext()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void btnWnd::playRande()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void btnWnd::playingChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void btnWnd::updateImage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void btnWnd::positionChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void btnWnd::updateGeciModel(const QList<QSharedPointer<LyricLine>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
