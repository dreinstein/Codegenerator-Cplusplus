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
    Parser.cpp \
    Keywordchecker.cpp \
    Evaluator.cpp

HEADERS  += mainwindow.h \
    Utilities.h\
	ParserFassade.h \
    Keywordscplusplus.h \
    GeneratorCPlusPlus.h \
    BaseGenerator.h \
    Rulescplusplus.h \
    Parserimplementation.h \
    Script.h \
    Parser.h \
    BaseParserImplementation.h \
    BaseKeywordChecker.h \
    Keywordchecker.h \
    Evaluator.h \
    BaseEvaluator.h



FORMS    += mainwindow.ui
	