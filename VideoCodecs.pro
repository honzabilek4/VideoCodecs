#-------------------------------------------------
#
# Project created by QtCreator 2015-03-23T13:40:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = VideoCodecs
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    PsnrClass.cpp \
    VideoUtility.cpp \
    SsimClass.cpp \
    MsvdClass.cpp \
    encode.cpp \
    decode.cpp \
    test.cpp \
    settings.cpp \
    qcustomplot.cpp \
    graph.cpp

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
    encode.h \
    decode.h \
    test.h \
    settings.h \
    qcustomplot.h \
    graph.h

FORMS    += mainwindow.ui \
    encode.ui \
    decode.ui \
    test.ui \
    settings.ui \
    graph.ui

RESOURCES += \
    images.qrc


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lopencv_core2410
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lopencv_core2410d

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

DISTFILES +=
