#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T15:01:57
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    ../lib/AbstractController.cpp \
    ../lib/Data.cpp \
    ../lib/DBManager.cpp \
    ../lib/FSM.cpp \
    ../lib/IONetworkManager.cpp \
    ../lib/Model.cpp \
    Controller.cpp

HEADERS  += Widget.h \
    ../lib/AbstractController.h \
    ../lib/Data.h \
    ../lib/DBManager.h \
    ../lib/FSM.h \
    ../lib/IONetworkManager.h \
    ../lib/Model.h \
    Controller.h
