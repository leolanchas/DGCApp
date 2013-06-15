/****************************************************************************
** Meta object code from reading C++ file 'dgcapp.h'
**
** Created: Wed 18. Apr 16:30:17 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dgcapp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dgcapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dgcapp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,    7,    8,    7, 0x0a,
      35,    7,   31,    7, 0x0a,
      57,    7,   31,    7, 0x0a,
      75,    7,   31,    7, 0x0a,
     100,    7,   95,    7, 0x0a,
     119,    7,    7,    7, 0x0a,
     126,    7,    7,    7, 0x0a,
     134,    7,    7,    7, 0x0a,
     151,    7,    7,    7, 0x0a,
     162,    7,   31,    7, 0x0a,
     181,    7,  175,    7, 0x0a,
     195,    7,  175,    7, 0x0a,
     213,  209,    7,    7, 0x0a,
     250,    7,    7,    7, 0x0a,
     265,    7,   31,    7, 0x0a,
     280,    7,   31,    7, 0x0a,
     292,    7,   31,    7, 0x0a,
     304,    7,   31,    7, 0x0a,
     316,    7,   31,    7, 0x0a,
     335,    7,  328,    7, 0x0a,
     354,  349,    7,    7, 0x08,
     384,    7,    7,    7, 0x08,
     395,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dgcapp[] = {
    "dgcapp\0\0Canvas*\0getCanvas(int)\0int\0"
    "getCurrentTransform()\0getCurrentLayer()\0"
    "getCurrentShading()\0bool\0isBorderSelected()\0"
    "Draw()\0erase()\0deleteLayer(int)\0"
    "resetRev()\0getRevNumP()\0float\0"
    "getRevIX(int)\0getRevIY(int)\0,,,\0"
    "setRevPoint(float,float,float,float)\0"
    "revEraseLine()\0getIntensity()\0getLightX()\0"
    "getLightY()\0getLightZ()\0getNMerid()\0"
    "QColor\0getRefColor()\0item\0"
    "ToggleLayer(QListWidgetItem*)\0SetColor()\0"
    "SetRefColor()\0"
};

void dgcapp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        dgcapp *_t = static_cast<dgcapp *>(_o);
        switch (_id) {
        case 0: { Canvas* _r = _t->getCanvas((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Canvas**>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->getCurrentTransform();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->getCurrentLayer();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->getCurrentShading();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->isBorderSelected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->Draw(); break;
        case 6: _t->erase(); break;
        case 7: _t->deleteLayer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->resetRev(); break;
        case 9: { int _r = _t->getRevNumP();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { float _r = _t->getRevIX((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 11: { float _r = _t->getRevIY((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 12: _t->setRevPoint((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 13: _t->revEraseLine(); break;
        case 14: { int _r = _t->getIntensity();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 15: { int _r = _t->getLightX();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 16: { int _r = _t->getLightY();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 17: { int _r = _t->getLightZ();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 18: { int _r = _t->getNMerid();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 19: { QColor _r = _t->getRefColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 20: _t->ToggleLayer((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 21: _t->SetColor(); break;
        case 22: _t->SetRefColor(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dgcapp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dgcapp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dgcapp,
      qt_meta_data_dgcapp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dgcapp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dgcapp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dgcapp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dgcapp))
        return static_cast<void*>(const_cast< dgcapp*>(this));
    return QDialog::qt_metacast(_clname);
}

int dgcapp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
