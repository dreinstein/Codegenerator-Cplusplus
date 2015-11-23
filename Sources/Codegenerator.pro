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
    KeywordsCPlusPlus.cpp

HEADERS  += mainwindow.h \
    Utilities.h\
	ParserFassade.h \
    Keywordscplusplus.h \
    Parser.h

FORMS    += mainwindow.ui
