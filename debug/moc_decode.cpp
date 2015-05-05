/****************************************************************************
** Meta object code from reading C++ file 'decode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../decode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'decode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Decode_t {
    QByteArrayData data[15];
    char stringdata[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Decode_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Decode_t qt_meta_stringdata_Decode = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Decode"
QT_MOC_LITERAL(1, 7, 16), // "updateTextOutput"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "text"
QT_MOC_LITERAL(4, 30, 8), // "toggleUi"
QT_MOC_LITERAL(5, 39, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(6, 63, 20), // "on_runButton_clicked"
QT_MOC_LITERAL(7, 84, 14), // "processStarted"
QT_MOC_LITERAL(8, 99, 23), // "readyReadStandardOutput"
QT_MOC_LITERAL(9, 123, 22), // "readyReadStandardError"
QT_MOC_LITERAL(10, 146, 16), // "decodingFinished"
QT_MOC_LITERAL(11, 163, 23), // "on_browseButton_clicked"
QT_MOC_LITERAL(12, 187, 12), // "getArguments"
QT_MOC_LITERAL(13, 200, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(14, 222, 12) // "loadSettings"

    },
    "Decode\0updateTextOutput\0\0text\0toggleUi\0"
    "on_cancelButton_clicked\0on_runButton_clicked\0"
    "processStarted\0readyReadStandardOutput\0"
    "readyReadStandardError\0decodingFinished\0"
    "on_browseButton_clicked\0getArguments\0"
    "on_saveButton_clicked\0loadSettings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Decode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   78,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QStringList,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Decode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Decode *_t = static_cast<Decode *>(_o);
        switch (_id) {
        case 0: _t->updateTextOutput((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->toggleUi(); break;
        case 2: _t->on_cancelButton_clicked(); break;
        case 3: _t->on_runButton_clicked(); break;
        case 4: _t->processStarted(); break;
        case 5: _t->readyReadStandardOutput(); break;
        case 6: _t->readyReadStandardError(); break;
        case 7: _t->decodingFinished(); break;
        case 8: _t->on_browseButton_clicked(); break;
        case 9: { QStringList _r = _t->getArguments();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 10: _t->on_saveButton_clicked(); break;
        case 11: _t->loadSettings(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Decode::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Decode::updateTextOutput)) {
                *result = 0;
            }
        }
        {
            typedef void (Decode::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Decode::toggleUi)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Decode::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Decode.data,
      qt_meta_data_Decode,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Decode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Decode::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Decode.stringdata))
        return static_cast<void*>(const_cast< Decode*>(this));
    return QDialog::qt_metacast(_clname);
}

int Decode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Decode::updateTextOutput(const QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Decode::toggleUi()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
