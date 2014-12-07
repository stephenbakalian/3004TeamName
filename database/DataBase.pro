#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T15:58:41
#
#-------------------------------------------------
QT  += sql
QT  += core
QT  += network
QT  -= gui

TARGET    = DataBase
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    database.cpp \
    tcpserver.cpp

HEADERS += \
    database.h \
    tcpserver.h
