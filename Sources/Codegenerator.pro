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
    ParserFassade.cpp \
    KeywordsCPlusPlus.cpp \
    GeneratorCPusPlus.cpp \
    Rulescplusplus.cpp \
    parserimplementation.cpp \
    Script.cpp \
    Keywordchecker.cpp \
    Evaluator.cpp \
    Codegeneratorfassade.cpp \
    Codegen/CPluspluscodegenerator.cpp   

HEADERS  += mainwindow.h \
    Utilities.h\
    ParserFassade.h \
    Keywordscplusplus.h \
    GeneratorCPlusPlus.h \
    Rulescplusplus.h \
    Parserimplementation.h \
    Script.h \
    Parser.h \
    Base/BaseParserImplementation.h \
    Keywordchecker.h \
    Evaluator.h \
    Base/BaseEvaluator.h \
    Base/BaseGenerator.h \
    Base/baseKeywordChecker.h \
    Base/BaseParserImplementation.h \
    Parserimplementation.h \
    Codegeneratorfassade.h \
    Codegen/Basecodegenerator.h \
    Codegen/CPluspluscodegenerator.h

FORMS    += mainwindow.ui
	
