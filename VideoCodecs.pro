#-------------------------------------------------
#
# Project created by QtCreator 2015-03-23T13:40:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VideoCodecs
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    PsnrClass.cpp \
    VideoUtility.cpp \
    SsimClass.cpp \
    MsvdClass.cpp \
    encode.cpp

HEADERS  += mainwindow.h \
    PsnrClass.h \
    VideoUtility.h \
    SsimClass.h \
    MsvdClass.h \
    include/core.hpp \
    include/mat.hpp \
    include/operations.hpp \
    include/types_c.h \
    include/version.hpp \
    include/affine.hpp \
    include/core_c.h \
    include/cuda_devptrs.hpp \
    include/devmem2d.hpp \
    include/eigen.hpp \
    include/gpumat.hpp \
    include/internal.hpp \
    include/opengl_interop.hpp \
    include/opengl_interop_deprecated.hpp \
    include/wimage.hpp \
    encode.h

FORMS    += mainwindow.ui \
    encode.ui

RESOURCES += \
    resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lopencv_core2410
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lopencv_core2410d

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/libopencv_core2410.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/libopencv_core2410d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/opencv_core2410.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/opencv_core2410d.lib
