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
    ../../Sources/GeneratorCPusPlus.cpp \
    ../../Sources/ParserFassade.cpp \
    ../../Sources/Evaluator.cpp \
    ../../Sources/Codegen/CPluspluscodegenerator.cpp \
    ../../Sources/Codegeneratorfassade.cpp \
    ../../Sources/utilities.cpp \
    systemtest.cpp \
    mockcpluspluscodegenerator.cpp \
    ../../Sources/Errorhandling/openfileexception.cpp \
    ../../Sources/Codegen/Classgenerator.cpp \
    ../../Sources/Codegen/Basecodegenerator.cpp \
    ../../Sources/Codegen/Attributegenerator.cpp \
    ../../Sources/Errorhandling/Scriptexception.cpp \
    ../../Sources/Errorhandling/Attributescriptexception.cpp \
    ../../Sources/Errorhandling/FileNotvalidexception.cpp \
    ../../Sources/Parsing/KeywordsCPlusPlus.cpp \
    ../../Sources/Parsing/parserimplementation.cpp \
    ../../Sources/Parsing/Rulescplusplus.cpp \
    ../../Sources/Parsing/Script.cpp \
    ../../Sources/Codegen/Attributeelements.cpp \
    ../../Sources/Codegen/Fuctioncodegenerator.cpp \
    ../../Sources/Codegen/Functionelements.cpp \
    ../../Sources/Errorhandling/Functionscriptexception.cpp \
    ../../Sources/Codegen/codegeneratorconstants.cpp \
    testdatagenerator.cpp \
    evaluatetest.cpp \
    functiontest.cpp \
    testutilities.cpp \
    Basictest.cpp \
    classtest.cpp

HEADERS += \
    parsertest.h \
    ../../Sources/GeneratorCPlusPlus.h \
    ../../Sources/ParserFassade.h \
    mockparser.h \
    ../../Sources/Evaluator.h \
    ../../Sources/Base/BaseGenerator.h \
    ../../Sources/Codegen/CPluspluscodegenerator.h \
    ../../Sources/Codegen/Basecodegenerator.h \
    ../../Sources/Base/BaseEvaluator.h \
    ../../Sources/Base/baseKeywordChecker.h \
    ../../Sources/Base/BaseParserImplementation.h \
    ../../Sources/Codegeneratorfassade.h \
    systemtest.h \
    mockcpluspluscodegenerator.h \
    ../../Sources/Errorhandling/Exceptionhandling.h \
    ../../Sources/Errorhandling/OpenfileException.h \
    ../../Sources/Codegen/Classgenerator.h \
    ../../Sources/Codegen/Attributegenerator.h \
    ../../Sources/Errorhandling/Scriptexception.h \
    ../../Sources/Errorhandling/FileNotvalidexception.h \
    ../../Sources/Errorhandling/Attributescriptexception.h \
    baseevaluator.h \
    ../../Sources/Parsing/Keywordscplusplus.h \
    ../../Sources/Parsing/Parser.h \
    ../../Sources/Parsing/Parserimplementation.h \
    ../../Sources/Parsing/RulesC++.h \
    ../../Sources/Parsing/Rulescplusplus.h \
    ../../Sources/Parsing/Script.h \
    ../../Sources/Codegen/Attributeelements.h \
    ../../Sources/Codegen/Fuctioncodegenerator.h \
    ../../Sources/Codegen/Functionelements.h \
    ../../Sources/Errorhandling/Functionscriptexception.h \
    ../../Sources/Codegen/codegeneratorconstants.h \
    testdatagenerator.h \
    evaluatetest.h \
    functiontest.h \
    testutilities.h \
    classtest.h \
    Basictest.h

