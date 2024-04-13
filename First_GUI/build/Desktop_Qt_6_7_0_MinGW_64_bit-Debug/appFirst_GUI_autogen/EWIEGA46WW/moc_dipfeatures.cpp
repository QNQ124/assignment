/****************************************************************************
** Meta object code from reading C++ file 'dipfeatures.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../dipfeatures.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dipfeatures.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDIPFeaturesENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDIPFeaturesENDCLASS = QtMocHelpers::stringData(
    "DIPFeatures",
    "dipStartTimer",
    "",
    "dipStopTimer",
    "dipSetImageSource",
    "source",
    "dipLoadImage",
    "getInputWidth",
    "getInputHeight",
    "getInputDepth",
    "getOutputWidth",
    "getOutputHeight",
    "getOutputDepth",
    "dipResetData",
    "dipWriteBmp",
    "dipCalculateHistogramInput",
    "dipCalculateHistogramOutput",
    "dipGetHistogramInputAt",
    "channel",
    "pos",
    "dipGetHistogramOutputAt",
    "dipHistogramEqualization",
    "graylevels",
    "newgrays",
    "dipConvertInput2QImage",
    "dipConvertOutput2QImage",
    "dipConvertRGBToGrayScale",
    "dipFlipVertical",
    "dipFlipHorizontal",
    "dipRotation90",
    "dipRotation180",
    "dipRotation270",
    "dipRotation",
    "xorigin",
    "yorigin",
    "angle",
    "dipMathAdd",
    "value",
    "dipMathSubtract",
    "dipMathAnd",
    "dipMathOr",
    "dipMathXor",
    "dipMathNot",
    "dipMathNand",
    "dipMathNor",
    "dipOverlayNonZero",
    "startrowofimg1",
    "startrowofimg2",
    "newheight",
    "startcolofimg1",
    "startcolofimg2",
    "newwidth",
    "dipOverlayZero",
    "dipOverlayGreater",
    "dipOverlayLess",
    "dipOverlayAverage",
    "dipInvert",
    "dipGeometry",
    "xstretch",
    "ystretch",
    "xdisplace",
    "ydisplace",
    "xcross",
    "ycross",
    "dipStretch",
    "dipCrop",
    "startrow",
    "startcol",
    "dipPaste",
    "dipWarp",
    "xcontrol",
    "ycontrol",
    "dipObjectWarp",
    "x1",
    "y1",
    "x2",
    "y2",
    "x3",
    "y3",
    "x4",
    "y4",
    "dipFilterImage",
    "masktype",
    "lowhigh",
    "dipMedianFilter",
    "size"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDIPFeaturesENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  302,    2, 0x0a,    1 /* Public */,
       3,    0,  303,    2, 0x0a,    2 /* Public */,
       4,    1,  304,    2, 0x0a,    3 /* Public */,
       6,    0,  307,    2, 0x0a,    5 /* Public */,
       7,    0,  308,    2, 0x0a,    6 /* Public */,
       8,    0,  309,    2, 0x0a,    7 /* Public */,
       9,    0,  310,    2, 0x0a,    8 /* Public */,
      10,    0,  311,    2, 0x0a,    9 /* Public */,
      11,    0,  312,    2, 0x0a,   10 /* Public */,
      12,    0,  313,    2, 0x0a,   11 /* Public */,
      13,    0,  314,    2, 0x0a,   12 /* Public */,
      14,    1,  315,    2, 0x0a,   13 /* Public */,
      15,    0,  318,    2, 0x0a,   15 /* Public */,
      16,    0,  319,    2, 0x0a,   16 /* Public */,
      17,    2,  320,    2, 0x0a,   17 /* Public */,
      20,    2,  325,    2, 0x0a,   20 /* Public */,
      21,    2,  330,    2, 0x0a,   23 /* Public */,
      24,    0,  335,    2, 0x0a,   26 /* Public */,
      25,    0,  336,    2, 0x0a,   27 /* Public */,
      26,    0,  337,    2, 0x0a,   28 /* Public */,
      27,    0,  338,    2, 0x0a,   29 /* Public */,
      28,    0,  339,    2, 0x0a,   30 /* Public */,
      29,    0,  340,    2, 0x0a,   31 /* Public */,
      30,    0,  341,    2, 0x0a,   32 /* Public */,
      31,    0,  342,    2, 0x0a,   33 /* Public */,
      32,    3,  343,    2, 0x0a,   34 /* Public */,
      36,    1,  350,    2, 0x0a,   38 /* Public */,
      38,    1,  353,    2, 0x0a,   40 /* Public */,
      39,    1,  356,    2, 0x0a,   42 /* Public */,
      40,    1,  359,    2, 0x0a,   44 /* Public */,
      41,    1,  362,    2, 0x0a,   46 /* Public */,
      42,    0,  365,    2, 0x0a,   48 /* Public */,
      43,    1,  366,    2, 0x0a,   49 /* Public */,
      44,    1,  369,    2, 0x0a,   51 /* Public */,
      45,    6,  372,    2, 0x0a,   53 /* Public */,
      52,    6,  385,    2, 0x0a,   60 /* Public */,
      53,    6,  398,    2, 0x0a,   67 /* Public */,
      54,    6,  411,    2, 0x0a,   74 /* Public */,
      55,    6,  424,    2, 0x0a,   81 /* Public */,
      56,    0,  437,    2, 0x0a,   88 /* Public */,
      57,    7,  438,    2, 0x0a,   89 /* Public */,
      64,    2,  453,    2, 0x0a,   97 /* Public */,
      65,    4,  458,    2, 0x0a,  100 /* Public */,
      68,    6,  467,    2, 0x0a,  105 /* Public */,
      69,    2,  480,    2, 0x0a,  112 /* Public */,
      72,    8,  485,    2, 0x0a,  115 /* Public */,
      81,    2,  502,    2, 0x0a,  124 /* Public */,
      84,    1,  507,    2, 0x0a,  127 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Float,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   18,   19,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   18,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   22,   23,
    QMetaType::QImage,
    QMetaType::QImage,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double,   33,   34,   35,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   46,   47,   48,   49,   50,   51,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   46,   47,   48,   49,   50,   51,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   46,   47,   48,   49,   50,   51,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   46,   47,   48,   49,   50,   51,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   46,   47,   48,   49,   50,   51,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::Float, QMetaType::Float,   35,   58,   59,   60,   61,   62,   63,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   58,   59,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   66,   67,   48,   51,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   46,   47,   48,   49,   50,   51,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   70,   71,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   73,   74,   75,   76,   77,   78,   79,   80,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   82,   83,
    QMetaType::Void, QMetaType::Int,   85,

       0        // eod
};

Q_CONSTINIT const QMetaObject DIPFeatures::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDIPFeaturesENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDIPFeaturesENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDIPFeaturesENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DIPFeatures, std::true_type>,
        // method 'dipStartTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dipStopTimer'
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'dipSetImageSource'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'dipLoadImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getInputWidth'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getInputHeight'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getInputDepth'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getOutputWidth'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getOutputHeight'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getOutputDepth'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipResetData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dipWriteBmp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'dipCalculateHistogramInput'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dipCalculateHistogramOutput'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dipGetHistogramInputAt'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipGetHistogramOutputAt'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipHistogramEqualization'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipConvertInput2QImage'
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'dipConvertOutput2QImage'
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'dipConvertRGBToGrayScale'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dipFlipVertical'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dipFlipHorizontal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dipRotation90'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dipRotation180'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dipRotation270'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dipRotation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'dipMathAdd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipMathSubtract'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipMathAnd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipMathOr'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipMathXor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipMathNot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dipMathNand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipMathNor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipOverlayNonZero'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipOverlayZero'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipOverlayGreater'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipOverlayLess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipOverlayAverage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipInvert'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dipGeometry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'dipStretch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'dipCrop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipPaste'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipWarp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipObjectWarp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipFilterImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dipMedianFilter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void DIPFeatures::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DIPFeatures *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dipStartTimer(); break;
        case 1: { float _r = _t->dipStopTimer();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->dipSetImageSource((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->dipLoadImage(); break;
        case 4: { int _r = _t->getInputWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->getInputHeight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->getInputDepth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->getOutputWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->getOutputHeight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->getOutputDepth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->dipResetData(); break;
        case 11: _t->dipWriteBmp((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->dipCalculateHistogramInput(); break;
        case 13: _t->dipCalculateHistogramOutput(); break;
        case 14: { int _r = _t->dipGetHistogramInputAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->dipGetHistogramOutputAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->dipHistogramEqualization((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 17: { QImage _r = _t->dipConvertInput2QImage();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 18: { QImage _r = _t->dipConvertOutput2QImage();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->dipConvertRGBToGrayScale(); break;
        case 20: _t->dipFlipVertical(); break;
        case 21: _t->dipFlipHorizontal(); break;
        case 22: _t->dipRotation90(); break;
        case 23: _t->dipRotation180(); break;
        case 24: _t->dipRotation270(); break;
        case 25: _t->dipRotation((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 26: _t->dipMathAdd((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->dipMathSubtract((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->dipMathAnd((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->dipMathOr((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->dipMathXor((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 31: _t->dipMathNot(); break;
        case 32: _t->dipMathNand((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 33: _t->dipMathNor((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 34: _t->dipOverlayNonZero((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        case 35: _t->dipOverlayZero((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        case 36: _t->dipOverlayGreater((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        case 37: _t->dipOverlayLess((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        case 38: _t->dipOverlayAverage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        case 39: _t->dipInvert(); break;
        case 40: _t->dipGeometry((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[7]))); break;
        case 41: _t->dipStretch((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2]))); break;
        case 42: _t->dipCrop((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 43: _t->dipPaste((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        case 44: _t->dipWarp((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 45: _t->dipObjectWarp((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8]))); break;
        case 46: _t->dipFilterImage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 47: _t->dipMedianFilter((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *DIPFeatures::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DIPFeatures::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDIPFeaturesENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DIPFeatures::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 48;
    }
    return _id;
}
QT_WARNING_POP
