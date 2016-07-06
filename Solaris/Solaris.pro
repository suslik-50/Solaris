QT += core
QT -= gui
QT += sql

CONFIG += c++11

TARGET = Solaris
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    datebaseconnect.cpp \
    xml.cpp

HEADERS += \
    datebaseconnect.h \
    xml.h
