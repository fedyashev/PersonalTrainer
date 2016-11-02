QT += core network
QT -= gui

TARGET = TesServerLib
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    cabstructionetworkmanager.cpp \
    cabstructfsm.cpp \
    cabstructcontrolleritem.cpp \
    cabstructdbmanager.cpp \
    cserverionetworkmanager.cpp \
    cserverfsm.cpp \
    cserverdbmanager.cpp \
    cservercontroller.cpp \
    cserver.cpp

HEADERS += \
    cabstructionetworkmanager.h \
    cabstructfsm.h \
    cabstructcontrolleritem.h \
    cabstructdbmanager.h \
    cserverionetworkmanager.h \
    cserverfsm.h \
    cserverdbmanager.h \
    cservercontroller.h \
    cserver.h

