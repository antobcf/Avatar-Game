/****************************************************************************
** Meta object code from reading C++ file 'creaavatar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AvatarGame/creaavatar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'creaavatar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CreaAvatar_t {
    QByteArrayData data[16];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreaAvatar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreaAvatar_t qt_meta_stringdata_CreaAvatar = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CreaAvatar"
QT_MOC_LITERAL(1, 11, 8), // "checkUno"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "checkDue"
QT_MOC_LITERAL(4, 30, 8), // "checkTre"
QT_MOC_LITERAL(5, 39, 12), // "checkQuattro"
QT_MOC_LITERAL(6, 52, 11), // "checkCinque"
QT_MOC_LITERAL(7, 64, 8), // "checkSei"
QT_MOC_LITERAL(8, 73, 10), // "checkSette"
QT_MOC_LITERAL(9, 84, 9), // "checkOtto"
QT_MOC_LITERAL(10, 94, 9), // "groupTipo"
QT_MOC_LITERAL(11, 104, 10), // "resetTutto"
QT_MOC_LITERAL(12, 115, 10), // "resetCheck"
QT_MOC_LITERAL(13, 126, 13), // "calcoloValori"
QT_MOC_LITERAL(14, 140, 17), // "inserisciImmagine"
QT_MOC_LITERAL(15, 158, 11) // "setImmagine"

    },
    "CreaAvatar\0checkUno\0\0checkDue\0checkTre\0"
    "checkQuattro\0checkCinque\0checkSei\0"
    "checkSette\0checkOtto\0groupTipo\0"
    "resetTutto\0resetCheck\0calcoloValori\0"
    "inserisciImmagine\0setImmagine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreaAvatar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreaAvatar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CreaAvatar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkUno(); break;
        case 1: _t->checkDue(); break;
        case 2: _t->checkTre(); break;
        case 3: _t->checkQuattro(); break;
        case 4: _t->checkCinque(); break;
        case 5: _t->checkSei(); break;
        case 6: _t->checkSette(); break;
        case 7: _t->checkOtto(); break;
        case 8: _t->groupTipo(); break;
        case 9: _t->resetTutto(); break;
        case 10: _t->resetCheck(); break;
        case 11: _t->calcoloValori(); break;
        case 12: _t->inserisciImmagine(); break;
        case 13: _t->setImmagine(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CreaAvatar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CreaAvatar.data,
    qt_meta_data_CreaAvatar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CreaAvatar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreaAvatar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CreaAvatar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CreaAvatar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
