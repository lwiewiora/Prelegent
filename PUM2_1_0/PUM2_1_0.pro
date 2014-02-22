# The name of your app

QT       += core

QT       += network

QT       -= gui

TARGET = PUM2_1_0

# C++ sources
SOURCES += main.cpp \
    client.cpp \
    server.cpp \
    LabelClass.cpp \
    LabelClock.cpp

# C++ headers
HEADERS += \
    client.h \
    server.h \
    LabelClass.h \
    LabelClock.h \
    LabelSet.h \
    Common.h

# QML files and folders
qml.files = *.qml pages cover main.qml

# The .desktop file
desktop.files = PUM2_1_0.desktop

# Please do not modify the following line.
include(sailfishapplication/sailfishapplication.pri)

OTHER_FILES = \
    rpm/PUM2_1_0.yaml \
    rpm/PUM2_1_0.spec

RESOURCES +=

