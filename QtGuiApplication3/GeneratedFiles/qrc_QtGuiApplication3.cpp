/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.10.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // C:/Users/Irena/source/repos/QtGuiApplication3/QtGuiApplication3/icons/BNicon.png
  0x0,0x0,0x0,0xa1,
  0x89,
  0x50,0x4e,0x47,0xd,0xa,0x1a,0xa,0x0,0x0,0x0,0xd,0x49,0x48,0x44,0x52,0x0,
  0x0,0x0,0x20,0x0,0x0,0x0,0x20,0x8,0x2,0x0,0x0,0x0,0xfc,0x18,0xed,0xa3,
  0x0,0x0,0x0,0x6,0x62,0x4b,0x47,0x44,0x0,0x0,0x0,0x0,0x0,0x0,0xf9,0x43,
  0xbb,0x7f,0x0,0x0,0x0,0x9,0x70,0x48,0x59,0x73,0x0,0x0,0x2e,0x23,0x0,0x0,
  0x2e,0x23,0x1,0x78,0xa5,0x3f,0x76,0x0,0x0,0x0,0x41,0x49,0x44,0x41,0x54,0x48,
  0x4b,0xed,0xcd,0x41,0xd,0x0,0x30,0xc,0xc3,0xc0,0xf2,0x1a,0xa4,0x71,0x1a,0xa2,
  0x81,0x1a,0x4,0x3f,0xda,0x48,0x53,0x94,0x7b,0x5b,0x72,0x5d,0xb1,0xa2,0xa0,0x4b,
  0x3f,0x38,0x1a,0x4e,0x83,0x3d,0xca,0x72,0xb0,0x26,0x78,0xf,0x3a,0x32,0x40,0x19,
  0xa0,0xc,0x50,0x6,0x28,0x3,0x94,0x1,0xfa,0x62,0xf0,0x0,0x2b,0xd2,0xf8,0xb0,
  0x95,0xeb,0x9b,0x40,0x0,0x0,0x0,0x0,0x49,0x45,0x4e,0x44,0xae,0x42,0x60,0x82,
  
  
};

static const unsigned char qt_resource_name[] = {
  // icons
  0x0,0x5,
  0x0,0x6f,0xa6,0x53,
  0x0,0x69,
  0x0,0x63,0x0,0x6f,0x0,0x6e,0x0,0x73,
    // BNicon.png
  0x0,0xa,
  0xa,0x69,0xbe,0xa7,
  0x0,0x42,
  0x0,0x4e,0x0,0x69,0x0,0x63,0x0,0x6f,0x0,0x6e,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/icons
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/icons/BNicon.png
  0x0,0x0,0x0,0x10,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x62,0x69,0xa8,0x21,0x27,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_QtGuiApplication3)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_QtGuiApplication3)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_QtGuiApplication3)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_QtGuiApplication3)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_QtGuiApplication3)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_QtGuiApplication3)(); }
   } dummy;
}
