#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T20:43:13
#
#-------------------------------------------------

QT       += core gui

CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Codegenerator
TEMPLATE = app


SOURCES += main.cpp\
    Parsing/KeywordsCPlusPlus.cpp \
    GeneratorCPusPlus.cpp \
    Evaluator.cpp \
    Codegeneratorfassade.cpp \
    Codegen/CPluspluscodegenerator.cpp \    
    Utilities.cpp \
    Errorhandling/OpenfileException.cpp \
    Codegen/Classgenerator.cpp \
    Errorhandling/Scriptexception.cpp \
    Errorhandling/Attributescriptexception.cpp \
    Errorhandling/FileNotvalidexception.cpp \
    Codegen/Attributegenerator.cpp \
    Parsing/Rulescplusplus.cpp \
    Parsing/Script.cpp \
    ParserFassade.cpp \
    Codegen/Fuctioncodegenerator.cpp \
    Codegen/Functionelements.cpp \
    Errorhandling/Functionscriptexception.cpp \
    Codegen/Codegeneratorconstants.cpp \
    Parsing/parserimplementationText.cpp \
    Parsing/parserimplementationxml.cpp \
    Errorhandling/Xmlfileexception.cpp \
    Codegen/Attributeelements.cpp \
    Gui/classform.cpp \
    Gui/functionwidged.cpp \
    Codegen/basecodegenerator.cpp \
    Gui/attributeload.cpp \
    Gui/attributewidget.cpp \
    mainwindow.cpp \
    Gui/functionload.cpp

HEADERS  += mainwindow.h \
    Utilities.h\
    ParserFassade.h \
    GeneratorCPlusPlus.h \
    Base/BaseParserImplementation.h \
    Evaluator.h \
    Base/BaseEvaluator.h \
    Base/BaseGenerator.h \
    Base/baseKeywordChecker.h \
    Base/BaseParserImplementation.h \
    Codegeneratorfassade.h \
    Codegen/Basecodegenerator.h \
    Codegen/CPluspluscodegenerator.h \
    Errorhandling/Exceptionhandling.h \
    Errorhandling/OpenfileException.h \
    Codegen/Classgenerator.h \
    Errorhandling/Scriptexception.h \
    Errorhandling/Attributescriptexception.h \
    Errorhandling/FileNotvalidexception.h \
    Codegen/Attributegenerator.h \
    Parsing/Parser.h \
    Parsing/Rulescplusplus.h \
    Parsing/Script.h \
    Parsing/Keywordscplusplus.h \
    Codegen/Fuctioncodegenerator.h \
    Codegen/Functionelements.h \
    Errorhandling/Functionscriptexception.h \
    Codegen/Codegeneratorconstants.h \
    Codegen/Attributeelements.h \
    Parsing/ParserimplementationText.h \
    Parsing/parserimplementationxml.h \
    Errorhandling/Xmlfileexception.h \
    Gui/classform.h \
    Gui/functionwidged.h \
    Gui/attributewidget.h \
    Gui/attributeload.h \
    Gui/attributewidget.h \
    mainwindow.h \
    Gui/functionload.h

FORMS    += mainwindow.ui \
    Gui/classform.ui \
    Gui/functionwidged.ui \
    Gui/attributewidget.ui
	

DISTFILES +=
