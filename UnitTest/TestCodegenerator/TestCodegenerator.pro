QT += core
QT -= gui

CONFIG   += c++11

TARGET = TestCodegenerator
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../Sources/
INCLUDEPATH += ../../

LIBS +=  ../../gtest/staticlib/lgtest.lib
LIBS +=  ../../gmock/staticlib/lgmock.lib

SOURCES += main.cpp \
    parsertest.cpp \
    ../../Sources/parserimplementation.cpp

HEADERS += \
    parsertest.h \
    ../../Sources/Parserimplementation.h

