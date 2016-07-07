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
    settingsdb.cpp\
    function_to_date_base.cpp

HEADERS += \
    datebaseconnect.h \
    settingsdb.h\
    function_to_date_base.h

