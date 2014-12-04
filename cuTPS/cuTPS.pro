#-------------------------------------------------
#
# Project created by QtCreator 2014-12-03T17:33:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cuTPS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    login.h

FORMS    += mainwindow.ui \
    login.ui

OTHER_FILES +=

RESOURCES += \
    Assets/Assets.qrc
