#-------------------------------------------------
#
# Project created by QtCreator 2014-01-11T16:12:20
#
#-------------------------------------------------

QT       += core gui\
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PUM2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    server.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    server.h \
    client.h

FORMS    += mainwindow.ui
