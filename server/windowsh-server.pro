#-------------------------------------------------
#
# Project created by QtCreator 2014-10-31T06:48:18
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = windowsh-server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    server.cpp \
    connection.cpp \
    studentmanager.cpp \
    sharedmanager.cpp \
    ctmmanager.cpp \
    item.cpp \
    course.cpp

HEADERS += \
    server.h \
    connection.h \
    studentmanager.h \
    sharedmanager.h \
    ctmmanager.h \
    item.h \
    course.h
