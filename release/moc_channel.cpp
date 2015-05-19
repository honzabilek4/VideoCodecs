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
    QByteArrayData data[14];
    char stringdata[223];
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
QT_MOC_LITERAL(4, 31, 10), // "updateText"
QT_MOC_LITERAL(5, 42, 23), // "on_browseButton_clicked"
QT_MOC_LITERAL(6, 66, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(7, 88, 20), // "on_runButton_clicked"
QT_MOC_LITERAL(8, 109, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(9, 133, 14), // "processStarted"
QT_MOC_LITERAL(10, 148, 22), // "readyReadStandardError"
QT_MOC_LITERAL(11, 171, 23), // "readyReadStandardOutput"
QT_MOC_LITERAL(12, 195, 15), // "processFinished"
QT_MOC_LITERAL(13, 211, 11) // "berFinished"

    },
    "Channel\0updateTextOutput\0\0text\0"
    "updateText\0on_browseButton_clicked\0"
    "on_saveButton_clicked\0on_runButton_clicked\0"
    "on_cancelButton_clicked\0processStarted\0"
    "readyReadStandardError\0readyReadStandardOutput\0"
    "processFinished\0berFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Channel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   75,    2, 0x08 /* Private */,
       6,    0,   76,    2, 0x08 /* Private */,
       7,    0,   77,    2, 0x08 /* Private */,
       8,    0,   78,    2, 0x08 /* Private */,
       9,    0,   79,    2, 0x08 /* Private */,
      10,    0,   80,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    0,   82,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
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
    QMetaType::Void,

       0        // eod
};

void Channel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Channel *_t = static_cast<Channel *>(_o);
        switch (_id) {
        case 0: _t->updateTextOutput((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->updateText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_browseButton_clicked(); break;
        case 3: _t->on_saveButton_clicked(); break;
        case 4: _t->on_runButton_clicked(); break;
        case 5: _t->on_cancelButton_clicked(); break;
        case 6: _t->processStarted(); break;
        case 7: _t->readyReadStandardError(); break;
        case 8: _t->readyReadStandardOutput(); break;
        case 9: _t->processFinished(); break;
        case 10: _t->berFinished(); break;
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
        {
            typedef void (Channel::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Channel::updateText)) {
                *result = 1;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Channel::updateTextOutput(const QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Channel::updateText(const QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
