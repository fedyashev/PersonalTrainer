#-------------------------------------------------
#
# Project created by QtCreator 2016-11-03T21:06:07
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../lib/cabstructcontrolleritem.cpp \
    ../lib/cabstructdbmanager.cpp \
    ../lib/cabstructfsm.cpp \
    ../lib/cabstructionetworkmanager.cpp \
    cclientionetworkmanager.cpp \
    cclientfsm.cpp \
    cclientdbmanager.cpp \
    cclientcontroller.cpp

HEADERS  += mainwindow.h \
    ../lib/cabstructcontrolleritem.h \
    ../lib/cabstructdbmanager.h \
    ../lib/cabstructfsm.h \
    ../lib/cabstructionetworkmanager.h \
    cclientionetworkmanager.h \
    cclientfsm.h \
    cclientdbmanager.h \
    cclientcontroller.h
