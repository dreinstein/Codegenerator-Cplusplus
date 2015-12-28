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
    ../../Sources/parserimplementation.cpp \
    generatortest.cpp \
    ../../Sources/GeneratorCPusPlus.cpp \
    ../../Sources/ParserFassade.cpp \
    ../../Sources/KeywordsCPlusPlus.cpp \
    ../../Sources/Parser.cpp \
    ../../Sources/Script.cpp \
    ../../Sources/Rulescplusplus.cpp \
    ../../Sources/Evaluator.cpp

HEADERS += \
    parsertest.h \
    ../../Sources/Parserimplementation.h \
    generatortest.h \
    ../../Sources/GeneratorCPlusPlus.h \
    ../../Sources/BaseGenerator.h \
    ../../Sources/ParserFassade.h \
    ../../Sources/Keywordscplusplus.h \
    ../../Sources/Parser.h \
    ../../Sources/Script.h \
    ../../Sources/Rulescplusplus.h \
    mockparser.h \
    ../../Sources/Evaluator.h \
    ../../Sources/BaseEvaluator.h

