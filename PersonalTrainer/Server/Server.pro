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
    Client.cpp \
    IONetworkManager.cpp

HEADERS += \
    Server.h \
    Client.h \
    IONetworkManager.h
