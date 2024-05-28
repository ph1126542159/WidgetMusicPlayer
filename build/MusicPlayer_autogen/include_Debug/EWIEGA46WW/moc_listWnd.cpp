/****************************************************************************
** Meta object code from reading C++ file 'listWnd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../listWnd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listWnd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_listWnd_t {
    QByteArrayData data[12];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_listWnd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_listWnd_t qt_meta_stringdata_listWnd = {
    {
QT_MOC_LITERAL(0, 0, 7), // "listWnd"
QT_MOC_LITERAL(1, 8, 9), // "playSound"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 30), // "QSharedPointer<SoundBaseInfo>&"
QT_MOC_LITERAL(4, 50, 3), // "ptr"
QT_MOC_LITERAL(5, 54, 17), // "soundValueChanged"
QT_MOC_LITERAL(6, 72, 19), // "autoPlayTypeChanged"
QT_MOC_LITERAL(7, 92, 8), // "playLast"
QT_MOC_LITERAL(8, 101, 8), // "playNext"
QT_MOC_LITERAL(9, 110, 9), // "playRande"
QT_MOC_LITERAL(10, 120, 9), // "appendNew"
QT_MOC_LITERAL(11, 130, 29) // "QSharedPointer<SoundBaseInfo>"

    },
    "listWnd\0playSound\0\0QSharedPointer<SoundBaseInfo>&\0"
    "ptr\0soundValueChanged\0autoPlayTypeChanged\0"
    "playLast\0playNext\0playRande\0appendNew\0"
    "QSharedPointer<SoundBaseInfo>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_listWnd[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   58,    2, 0x0a /* Public */,
       8,    0,   59,    2, 0x0a /* Public */,
       9,    0,   60,    2, 0x0a /* Public */,
      10,    1,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    4,

       0        // eod
};

void listWnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<listWnd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playSound((*reinterpret_cast< QSharedPointer<SoundBaseInfo>(*)>(_a[1]))); break;
        case 1: _t->soundValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->autoPlayTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->playLast(); break;
        case 4: _t->playNext(); break;
        case 5: _t->playRande(); break;
        case 6: _t->appendNew((*reinterpret_cast< QSharedPointer<SoundBaseInfo>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSharedPointer<SoundBaseInfo> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (listWnd::*)(QSharedPointer<SoundBaseInfo> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&listWnd::playSound)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (listWnd::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&listWnd::soundValueChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (listWnd::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&listWnd::autoPlayTypeChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject listWnd::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_listWnd.data,
    qt_meta_data_listWnd,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *listWnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *listWnd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_listWnd.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int listWnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void listWnd::playSound(QSharedPointer<SoundBaseInfo> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void listWnd::soundValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void listWnd::autoPlayTypeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
