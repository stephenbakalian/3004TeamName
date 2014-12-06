#-------------------------------------------------
#
# Project created by QtCreator 2014-12-03T17:33:12
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cuTPS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    studentviewtextbooks.cpp \
    modifytextbook.cpp \
    ctmviewtextbooks.cpp \
    error.cpp \
    cart.cpp \
    requesthandler.cpp \
    ownedbooks.cpp \
    item.cpp

HEADERS  += mainwindow.h \
    login.h \
    studentviewtextbooks.h \
    modifytextbook.h \
    ctmviewtextbooks.h \
    error.h \
    cart.h \
    requesthandler.h \
    ownedbooks.h \
    item.h

FORMS    += mainwindow.ui \
    login.ui \
    studentviewtextbooks.ui \
    modifytextbook.ui \
    ctmviewtextbooks.ui \
    error.ui \
    cart.ui \
    ownedbooks.ui

OTHER_FILES +=

RESOURCES += \
    Assets/Assets.qr
