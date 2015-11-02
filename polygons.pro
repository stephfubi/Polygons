#-------------------------------------------------
#
# Project created by QtCreator 2015-10-25T12:08:09
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = polygons
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    inout.cpp \
    poligons.cpp \
    global.cpp \
    tests/test_parsevertexlist.cpp \
    tests/test_graham.cpp \
    tests/test_sortlist.cpp

HEADERS += \
    inout.h \
    poligons.h \
    global.h \
    tests/test_parsevertexlist.h \
    tests/test_graham.h \
    tests/test_sortlist.h
