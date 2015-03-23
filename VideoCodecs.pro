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
    VideoUtility.cpp

HEADERS  += mainwindow.h \
    PsnrClass.h \
    VideoUtility.h

FORMS    += mainwindow.ui
