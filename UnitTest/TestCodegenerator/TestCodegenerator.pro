QT += core
QT -= gui

CONFIG   += c++11

TARGET = TestCodegenerator
CONFIG += console
CONFIG -= app_bundle
CONFIG += no_batch

TEMPLATE = app

INCLUDEPATH += ../../
INCLUDEPATH += ../../Sources


LIBS +=  ../../gmock/staticlib/libgmock.lib

SOURCES += Main.cpp \
    parsertest.cpp \
    ../../Sources/GeneratorCPusPlus.cpp \
    ../../Sources/ParserFassade.cpp \
    ../../Sources/Evaluator.cpp \
    ../../Sources/Codegen/CPluspluscodegenerator.cpp \
    ../../Sources/Codegeneratorfassade.cpp \
    ../../Sources/utilities.cpp \
    mockcpluspluscodegenerator.cpp \
    ../../Sources/Errorhandling/openfileexception.cpp \
    ../../Sources/Errorhandling/Scriptexception.cpp \
    ../../Sources/Errorhandling/Attributescriptexception.cpp \
    ../../Sources/Errorhandling/FileNotvalidexception.cpp \
    ../../Sources/Parsing/KeywordsCPlusPlus.cpp \
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
    classtest.cpp \
    ReceiveDataTest.cpp \
    extractstringstest.cpp \
    ../../Sources/Parsing/parserimplementationText.cpp \
    ../../Sources/Parsing/parserimplementationxml.cpp \
    ../../Sources/Errorhandling/Xmlfileexception.cpp \
    guiattribute.cpp \
    ../../Sources/Codegen/classelements.cpp \
    ../../Sources/keywordchecker.cpp \
    ../../Sources/Codegen/Attributegenerator.cpp \
    ../../Sources/Codegen/basecodegenerator.cpp \
    ../../Sources/Codegen/classgenerator.cpp \
    ../../Sources/Gui/attributeload.cpp \
    guidatamanagertest.cpp \
    ../../Sources/Gui/guidatamanager.cpp

HEADERS += \
    ../../Sources/GeneratorCPlusPlus.h \
    ../../Sources/ParserFassade.h \
    mockparser.h \
    ../../Sources/Evaluator.h \
    ../../Sources/Base/BaseGenerator.h \
    ../../Sources/Codegen/CPluspluscodegenerator.h \
    ../../Sources/Base/baseKeywordChecker.h \
    ../../Sources/Base/BaseParserImplementation.h \
    ../../Sources/Codegeneratorfassade.h \
    systemtest.h \
    mockcpluspluscodegenerator.h \
    ../../Sources/Errorhandling/Exceptionhandling.h \
    ../../Sources/Errorhandling/OpenfileException.h \
    ../../Sources/Errorhandling/Scriptexception.h \
    ../../Sources/Errorhandling/FileNotvalidexception.h \
    ../../Sources/Errorhandling/Attributescriptexception.h \
    baseevaluator.h \
    ../../Sources/Parsing/Keywordscplusplus.h \
    ../../Sources/Parsing/Parser.h \
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
    testutilities.h \
    ../../Sources/Parsing/parserimplementationxml.h \
    ../../Sources/Errorhandling/Xmlfileexception.h \
    ../../Sources/Codegen/classelements.h \
    ../../Sources/Gui/iwidget.h \
    ../../Sources/keywordchecker.h \
    ../../Sources/ui_mainwindow.h \
    ../../Sources/Utilities.h \
    ../../Sources/Base/BaseGenerator.h \
    ../../Sources/Codegen/Basecodegenerator.h \
    ../../Sources/Codegen/classgenerator.h \
    ../../Sources/Gui/attributeload.h \
    ../../Sources/Parsing/Parser.h \
    ../../Sources/Parsing/ParserimplementationText.h \
    ../../Sources/Parsing/RulesC++.h \
    ../../Sources/GeneratorCPlusPlus.h \
    ../../Sources/ui_attributewidget.h \
    ../../Sources/Gui/loadDatas.h \
    ../../Sources/Gui/guidatamanager.h

SUBDIRS += \
    ../../Sources/Codegenerator.pro

FORMS +=

DISTFILES += \
    ../../Sources/object_script.Codegenerator.Debug \
    ../../Sources/object_script.Codegenerator.Release

