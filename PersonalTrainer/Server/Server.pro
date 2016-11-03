QT += core network
QT -= gui

CONFIG += c++11

TARGET = Server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    cserver.cpp \
    cservercontroller.cpp \
    cserverdbmanager.cpp \
    cserverfsm.cpp \
    cserverionetworkmanager.cpp \
    ../lib/cabstructcontrolleritem.cpp \
    ../lib/cabstructdbmanager.cpp \
    ../lib/cabstructfsm.cpp \
    ../lib/cabstructionetworkmanager.cpp

HEADERS += \
    cserver.h \
    cservercontroller.h \
    cserverdbmanager.h \
    cserverfsm.h \
    cserverionetworkmanager.h \
    ../lib/cabstructcontrolleritem.h \
    ../lib/cabstructdbmanager.h \
    ../lib/cabstructfsm.h \
    ../lib/cabstructionetworkmanager.h
