#-------------------------------------------------
#
# Project created by QtCreator 2014-10-20T20:25:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = new360
TEMPLATE = app


SOURCES += main.cpp\
    src/mainwidget.cpp \
    src/commom/staticbutton.cpp \
    src/commom/dynamicbutton.cpp \
    src/commom/dynamicwidget.cpp \
    src/commom/dynamicscaledwidget.cpp

HEADERS  += \
    src/mainwidget.h \
    src/commom/staticbutton.h \
    src/commom/dynamicbutton.h \
    src/commom/dynamicwidget.h \
    src/commom/dynamicscaledwidget.h

RESOURCES += \
    resource/360.qrc
