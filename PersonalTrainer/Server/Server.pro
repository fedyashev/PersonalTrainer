QT += core
QT += network
QT -= gui

CONFIG += c++11

TARGET = Server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Server.cpp \
    ServerController.cpp \
    ../lib/AbstractController.cpp \
    ../lib/Data.cpp \
    ../lib/DBManager.cpp \
    ../lib/FSM.cpp \
    ../lib/IONetworkManager.cpp \
    ../lib/Model.cpp

HEADERS += \
    Server.h \
    ServerController.h \
    ../lib/AbstractController.h \
    ../lib/Data.h \
    ../lib/DBManager.h \
    ../lib/FSM.h \
    ../lib/IONetworkManager.h \
    ../lib/Model.h
