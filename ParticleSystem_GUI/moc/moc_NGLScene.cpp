/****************************************************************************
** Meta object code from reading C++ file 'NGLScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/NGLScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NGLScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NGLScene_t {
    QByteArrayData data[25];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NGLScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NGLScene_t qt_meta_stringdata_NGLScene = {
    {
QT_MOC_LITERAL(0, 0, 8), // "NGLScene"
QT_MOC_LITERAL(1, 9, 12), // "editEmitter1"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "editEmitter2"
QT_MOC_LITERAL(4, 36, 12), // "editEmitter3"
QT_MOC_LITERAL(5, 49, 12), // "editEmitter4"
QT_MOC_LITERAL(6, 62, 10), // "setGravity"
QT_MOC_LITERAL(7, 73, 8), // "_gravity"
QT_MOC_LITERAL(8, 82, 15), // "setNumParticles"
QT_MOC_LITERAL(9, 98, 13), // "_numParticles"
QT_MOC_LITERAL(10, 112, 15), // "setParticleSize"
QT_MOC_LITERAL(11, 128, 13), // "_particleSize"
QT_MOC_LITERAL(12, 142, 9), // "setSpread"
QT_MOC_LITERAL(13, 152, 7), // "_spread"
QT_MOC_LITERAL(14, 160, 16), // "toggleSingleShot"
QT_MOC_LITERAL(15, 177, 12), // "addParticles"
QT_MOC_LITERAL(16, 190, 15), // "removeParticles"
QT_MOC_LITERAL(17, 206, 14), // "clearParticles"
QT_MOC_LITERAL(18, 221, 12), // "resetEmitter"
QT_MOC_LITERAL(19, 234, 8), // "redValue"
QT_MOC_LITERAL(20, 243, 4), // "_red"
QT_MOC_LITERAL(21, 248, 10), // "greenValue"
QT_MOC_LITERAL(22, 259, 6), // "_green"
QT_MOC_LITERAL(23, 266, 9), // "blueValue"
QT_MOC_LITERAL(24, 276, 5) // "_blue"

    },
    "NGLScene\0editEmitter1\0\0editEmitter2\0"
    "editEmitter3\0editEmitter4\0setGravity\0"
    "_gravity\0setNumParticles\0_numParticles\0"
    "setParticleSize\0_particleSize\0setSpread\0"
    "_spread\0toggleSingleShot\0addParticles\0"
    "removeParticles\0clearParticles\0"
    "resetEmitter\0redValue\0_red\0greenValue\0"
    "_green\0blueValue\0_blue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NGLScene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    1,   98,    2, 0x0a /* Public */,
       8,    1,  101,    2, 0x0a /* Public */,
      10,    1,  104,    2, 0x0a /* Public */,
      12,    1,  107,    2, 0x0a /* Public */,
      14,    0,  110,    2, 0x0a /* Public */,
      15,    0,  111,    2, 0x0a /* Public */,
      16,    0,  112,    2, 0x0a /* Public */,
      17,    0,  113,    2, 0x0a /* Public */,
      18,    0,  114,    2, 0x0a /* Public */,
      19,    1,  115,    2, 0x0a /* Public */,
      21,    1,  118,    2, 0x0a /* Public */,
      23,    1,  121,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   24,

       0        // eod
};

void NGLScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NGLScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->editEmitter1(); break;
        case 1: _t->editEmitter2(); break;
        case 2: _t->editEmitter3(); break;
        case 3: _t->editEmitter4(); break;
        case 4: _t->setGravity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setNumParticles((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setParticleSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setSpread((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->toggleSingleShot(); break;
        case 9: _t->addParticles(); break;
        case 10: _t->removeParticles(); break;
        case 11: _t->clearParticles(); break;
        case 12: _t->resetEmitter(); break;
        case 13: _t->redValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->greenValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->blueValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NGLScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_NGLScene.data,
    qt_meta_data_NGLScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NGLScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NGLScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NGLScene.stringdata0))
        return static_cast<void*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int NGLScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
