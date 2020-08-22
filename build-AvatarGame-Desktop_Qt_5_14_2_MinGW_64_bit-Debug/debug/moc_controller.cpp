/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AvatarGame/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[22];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 10), // "mostraHome"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "mostraCrea"
QT_MOC_LITERAL(4, 34, 11), // "mostraLista"
QT_MOC_LITERAL(5, 46, 13), // "mostraScontro"
QT_MOC_LITERAL(6, 60, 18), // "mostraSviluppatori"
QT_MOC_LITERAL(7, 79, 25), // "mostraInformazioniSistema"
QT_MOC_LITERAL(8, 105, 11), // "infoPopHome"
QT_MOC_LITERAL(9, 117, 12), // "infoPopLista"
QT_MOC_LITERAL(10, 130, 15), // "inserisciAvatar"
QT_MOC_LITERAL(11, 146, 14), // "modificaAvatar"
QT_MOC_LITERAL(12, 161, 16), // "scontroTraAvatar"
QT_MOC_LITERAL(13, 178, 13), // "rimuoviAvatar"
QT_MOC_LITERAL(14, 192, 13), // "ricercaAvatar"
QT_MOC_LITERAL(15, 206, 8), // "caricaDb"
QT_MOC_LITERAL(16, 215, 6), // "carica"
QT_MOC_LITERAL(17, 222, 5), // "salva"
QT_MOC_LITERAL(18, 228, 7), // "scontro"
QT_MOC_LITERAL(19, 236, 12), // "resetRicerca"
QT_MOC_LITERAL(20, 249, 13), // "calcoloValori"
QT_MOC_LITERAL(21, 263, 7) // "Avatar*"

    },
    "Controller\0mostraHome\0\0mostraCrea\0"
    "mostraLista\0mostraScontro\0mostraSviluppatori\0"
    "mostraInformazioniSistema\0infoPopHome\0"
    "infoPopLista\0inserisciAvatar\0"
    "modificaAvatar\0scontroTraAvatar\0"
    "rimuoviAvatar\0ricercaAvatar\0caricaDb\0"
    "carica\0salva\0scontro\0resetRicerca\0"
    "calcoloValori\0Avatar*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x0a /* Public */,
       3,    0,  110,    2, 0x0a /* Public */,
       4,    0,  111,    2, 0x0a /* Public */,
       5,    0,  112,    2, 0x0a /* Public */,
       6,    0,  113,    2, 0x0a /* Public */,
       7,    0,  114,    2, 0x0a /* Public */,
       8,    0,  115,    2, 0x0a /* Public */,
       9,    0,  116,    2, 0x0a /* Public */,
      10,    0,  117,    2, 0x0a /* Public */,
      11,    0,  118,    2, 0x0a /* Public */,
      12,    0,  119,    2, 0x0a /* Public */,
      13,    0,  120,    2, 0x0a /* Public */,
      14,    0,  121,    2, 0x0a /* Public */,
      15,    0,  122,    2, 0x0a /* Public */,
      16,    0,  123,    2, 0x0a /* Public */,
      17,    0,  124,    2, 0x0a /* Public */,
      18,    0,  125,    2, 0x0a /* Public */,
      19,    0,  126,    2, 0x0a /* Public */,
      20,    1,  127,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,    2,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mostraHome(); break;
        case 1: _t->mostraCrea(); break;
        case 2: _t->mostraLista(); break;
        case 3: _t->mostraScontro(); break;
        case 4: _t->mostraSviluppatori(); break;
        case 5: _t->mostraInformazioniSistema(); break;
        case 6: _t->infoPopHome(); break;
        case 7: _t->infoPopLista(); break;
        case 8: _t->inserisciAvatar(); break;
        case 9: _t->modificaAvatar(); break;
        case 10: _t->scontroTraAvatar(); break;
        case 11: _t->rimuoviAvatar(); break;
        case 12: _t->ricercaAvatar(); break;
        case 13: _t->caricaDb(); break;
        case 14: _t->carica(); break;
        case 15: _t->salva(); break;
        case 16: _t->scontro(); break;
        case 17: _t->resetRicerca(); break;
        case 18: _t->calcoloValori((*reinterpret_cast< Avatar*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Controller.data,
    qt_meta_data_Controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
