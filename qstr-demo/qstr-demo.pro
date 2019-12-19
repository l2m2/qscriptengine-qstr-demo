QT += core script
QT -= gui

CONFIG += c++11

TARGET = qstr-demo
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

RESOURCES += \
    res.qrc

TRANSLATIONS += qstr-demo_zhcn.ts
