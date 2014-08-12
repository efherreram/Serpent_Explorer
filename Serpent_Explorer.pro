#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T16:16:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Serpent_Explorer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    explorerobject.cpp \
    efile.cpp \
    edirectory.cpp

HEADERS  += mainwindow.h \
    node.h \
    serpentlist.h \
    explorerobject.h \
    efile.h \
    edirectory.h

FORMS    += mainwindow.ui
