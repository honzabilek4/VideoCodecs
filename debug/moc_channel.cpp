/****************************************************************************
** Meta object code from reading C++ file 'channel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../channel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'channel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Channel_t {
    QByteArrayData data[12];
    char stringdata[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Channel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Channel_t qt_meta_stringdata_Channel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Channel"
QT_MOC_LITERAL(1, 8, 16), // "updateTextOutput"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "text"
QT_MOC_LITERAL(4, 31, 23), // "on_browseButton_clicked"
QT_MOC_LITERAL(5, 55, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(6, 77, 20), // "on_runButton_clicked"
QT_MOC_LITERAL(7, 98, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(8, 122, 14), // "processStarted"
QT_MOC_LITERAL(9, 137, 22), // "readyReadStandardError"
QT_MOC_LITERAL(10, 160, 23), // "readyReadStandardOutput"
QT_MOC_LITERAL(11, 184, 15) // "processFinished"

    },
    "Channel\0updateTextOutput\0\0text\0"
    "on_browseButton_clicked\0on_saveButton_clicked\0"
    "on_runButton_clicked\0on_cancelButton_clicked\0"
    "processStarted\0readyReadStandardError\0"
    "readyReadStandardOutput\0processFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Channel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Channel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Channel *_t = static_cast<Channel *>(_o);
        switch (_id) {
        case 0: _t->updateTextOutput((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_browseButton_clicked(); break;
        case 2: _t->on_saveButton_clicked(); break;
        case 3: _t->on_runButton_clicked(); break;
        case 4: _t->on_cancelButton_clicked(); break;
        case 5: _t->processStarted(); break;
        case 6: _t->readyReadStandardError(); break;
        case 7: _t->readyReadStandardOutput(); break;
        case 8: _t->processFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Channel::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Channel::updateTextOutput)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Channel::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Channel.data,
      qt_meta_data_Channel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Channel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Channel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Channel.stringdata))
        return static_cast<void*>(const_cast< Channel*>(this));
    return QDialog::qt_metacast(_clname);
}

int Channel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Channel::updateTextOutput(const QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
