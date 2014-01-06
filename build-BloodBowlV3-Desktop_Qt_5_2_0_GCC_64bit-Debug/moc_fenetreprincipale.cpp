/****************************************************************************
** Meta object code from reading C++ file 'fenetreprincipale.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BloodBowlV3/fenetreprincipale.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetreprincipale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FenetrePrincipale_t {
    QByteArrayData data[14];
    char stringdata[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FenetrePrincipale_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FenetrePrincipale_t qt_meta_stringdata_FenetrePrincipale = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 22),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 16),
QT_MOC_LITERAL(4, 59, 5),
QT_MOC_LITERAL(5, 65, 16),
QT_MOC_LITERAL(6, 82, 19),
QT_MOC_LITERAL(7, 102, 19),
QT_MOC_LITERAL(8, 122, 26),
QT_MOC_LITERAL(9, 149, 9),
QT_MOC_LITERAL(10, 159, 19),
QT_MOC_LITERAL(11, 179, 6),
QT_MOC_LITERAL(12, 186, 14),
QT_MOC_LITERAL(13, 201, 8)
    },
    "FenetrePrincipale\0fenetreSelectionEquipe\0"
    "\0changerEquipesJ1\0index\0changerEquipesJ2\0"
    "changerIconEquipeJ1\0changerIconEquipeJ2\0"
    "validationSelectionEquipes\0finDeTour\0"
    "updatePanneauJoueur\0action\0QStandardItem*\0"
    "leJoueur\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenetrePrincipale[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a,
       3,    1,   55,    2, 0x0a,
       5,    1,   58,    2, 0x0a,
       6,    1,   61,    2, 0x0a,
       7,    1,   64,    2, 0x0a,
       8,    0,   67,    2, 0x0a,
       9,    0,   68,    2, 0x0a,
      10,    2,   69,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,   11,   13,

       0        // eod
};

void FenetrePrincipale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FenetrePrincipale *_t = static_cast<FenetrePrincipale *>(_o);
        switch (_id) {
        case 0: _t->fenetreSelectionEquipe(); break;
        case 1: _t->changerEquipesJ1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changerEquipesJ2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changerIconEquipeJ1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changerIconEquipeJ2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->validationSelectionEquipes(); break;
        case 6: _t->finDeTour(); break;
        case 7: _t->updatePanneauJoueur((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStandardItem*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject FenetrePrincipale::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FenetrePrincipale.data,
      qt_meta_data_FenetrePrincipale,  qt_static_metacall, 0, 0}
};


const QMetaObject *FenetrePrincipale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenetrePrincipale::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FenetrePrincipale.stringdata))
        return static_cast<void*>(const_cast< FenetrePrincipale*>(this));
    return QWidget::qt_metacast(_clname);
}

int FenetrePrincipale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
