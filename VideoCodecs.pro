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
    MsvdClass.cpp

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
    include/wimage.hpp

FORMS    += mainwindow.ui
