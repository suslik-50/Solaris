QT += core
QT -= gui
QT += sql
QT +=network

CONFIG += c++11
QMAKE_MAC_SDK = macosx10.12


TARGET = Solaris_back-end
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    timejd.cpp \
    earth_pos.cpp \
    potoc_sun.cpp \
    corners_solar_battery.cpp \
    setting.cpp \
    drain_parametrs_solar_battery.cpp \
    main_module.cpp \
    databaseconnect.cpp \
    functiondb.cpp \
    telnetserver.cpp \
    telnetsocketthread.cpp \
    command_parser.cpp \
    potoc_salleter2.cpp

HEADERS += \
    timejd.h \
    earth_pos.h \
    potoc_sun.h \
    structur.h \
    corners_solar_battery.h \
    setting.h \
    drain_parametrs_solar_battery.h \
    main_module.h \
    databaseconnect.h \
    functiondb.h \
    telnetserver.h \
    telnetsocketthread.h \
    command_parser.h \
    potoc_salleter2.h
