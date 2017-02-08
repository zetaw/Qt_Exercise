#-------------------------------------------------
#
# Project created by QtCreator 2016-10-22T10:02:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = puzzle
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    body3.cpp \
    dialog.cpp

HEADERS  += widget.h \
    body3.h \
    dialog.h

FORMS    += widget.ui \
    body3.ui \
    dialog.ui
