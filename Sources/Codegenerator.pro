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
    mainwindow.cpp\
    Parsing/KeywordsCPlusPlus.cpp \
    GeneratorCPusPlus.cpp \
    Evaluator.cpp \
    Codegeneratorfassade.cpp \
    Codegen/CPluspluscodegenerator.cpp \    
    Utilities.cpp \
    Errorhandling/OpenfileException.cpp \
    Codegen/Basecodegenerator.cpp \
    Codegen/Classgenerator.cpp \
    Errorhandling/Scriptexception.cpp \
    Errorhandling/Attributescriptexception.cpp \
    Errorhandling/FileNotvalidexception.cpp \
    Codegen/Attributegenerator.cpp \
    Parsing/parserimplementation.cpp \
    Parsing/Rulescplusplus.cpp \
    Parsing/Script.cpp \
    ParserFassade.cpp \
    Codegen/Fuctioncodegenerator.cpp \
    Codegen/Attributeelements.cpp

HEADERS  += mainwindow.h \
    Utilities.h\
    ParserFassade.h \
    GeneratorCPlusPlus.h \
    Rulescplusplus.h \
    Parserimplementation.h \
    Script.h \
    Parser.h \
    Base/BaseParserImplementation.h \
    Evaluator.h \
    Base/BaseEvaluator.h \
    Base/BaseGenerator.h \
    Base/baseKeywordChecker.h \
    Base/BaseParserImplementation.h \
    Parserimplementation.h \
    Codegeneratorfassade.h \
    Codegen/Basecodegenerator.h \
    Codegen/CPluspluscodegenerator.h \
    Execptionhandling/OpenfileException.h \
    Errorhandling/Exceptionhandling.h \
    Errorhandling/OpenfileException.h \
    Codegen/Classgenerator.h \
    Errorhandling/Scriptexception.h \
    Errorhandling/Attributescriptexception.h \
    Errorhandling/FileNotvalidexception.h \
    Codegen/Attributegenerator.h \
    Parsing/Parser.h \
    Parsing/Parserimplementation.h \
    Parsing/Rulescplusplus.h \
    Parsing/Script.h \
    Parsing/Keywordscplusplus.h \
    Codegen/Fuctioncodegenerator.h \
    Codegen/Attributeelements.h

FORMS    += mainwindow.ui
	
