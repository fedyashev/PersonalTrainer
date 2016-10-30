#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T15:01:57
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    Client.cpp \
    FSM.cpp \
    Data.cpp

HEADERS  += Widget.h \
    Client.h \
    FSM.h \
    Data.h
