CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(CodegeneratorUnitTest
        LANGUAGES CXX)


add_definitions(-DGTEST_LANGUAGE_CXX11)

include_directories(../../../Sources)

find_package(Threads REQUIRED)
find_package (Qt5Core CONFIG REQUIRED)


set( CMAKE_AUTOMOC ON )

if ($ENV{GOOGLETEST_DIR})
    SET(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
else ()
    message(WARNING "Using googletest src dir specified at Qt Creator wizard")
    SET(GOOGLETEST_DIR "C:/codegenerator/Codegenerator-Cplusplus/googletest_forqt519/googletest-master")
endif ()
if (EXISTS ${GOOGLETEST_DIR})
    SET(GTestSrc ${GOOGLETEST_DIR}/googletest)
    SET(GMockSrc ${GOOGLETEST_DIR}/googlemock)
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()


include_directories(${GTestSrc} ${GTestSrc}/include ${GMockSrc} ${GMockSrc}/include)

add_executable(${PROJECT_NAME} ../../../Sources/Utilities.h ../../../Sources/Utilities.cpp
               ../../../Sources/Codegen/Attributeelements.h ../../../Sources/Codegen/Attributeelements.cpp
               ../../../Sources/Codegen/codegeneratorconstants.h ../../../Sources/Codegen/codegeneratorconstants.cpp
               ../../../Sources/Codegen/Functionelements.h ../../../Sources/Codegen/Functionelements.cpp
               ../../../Sources/Gui/guidatamanager.h ../../../Sources/Gui/guidatamanager.cpp
               ../../../Sources/Codegeneratorfassade.h ../../../Sources/Codegeneratorfassade.cpp
               ../../../Sources/Base/BaseGenerator.h
               ../../../Sources/Codegen/Basecodegenerator.h ../../../Sources/Codegen/Basecodegenerator.cpp
               ../../../Sources/Codegen/CPluspluscodegenerator.h ../../../Sources/Codegen/CPluspluscodegenerator.cpp
               ../../../Sources/Errorhandling/OpenfileException.h ../../../Sources/Errorhandling/OpenfileException.cpp
               ../../../Sources/Codegen/Attributegenerator.h ../../../Sources/Codegen/Attributegenerator.cpp
               ../../../Sources/Codegen/Fuctioncodegenerator.h ../../../Sources/Codegen/Fuctioncodegenerator.cpp
               ../../../Sources/ParserFassade.h ../../../Sources/ParserFassade.cpp
               ../../../Sources/Parsing/Parser.h
               ../../../Sources/Codegen/classgenerator.h ../../../Sources/Codegen/classgenerator.cpp
               ../../../Sources/Parsing/KeywordsCPlusPlus.h ../../../Sources/Parsing/KeywordsCPlusPlus.cpp
               ../../../Sources/Parsing/Script.h ../../../Sources/Parsing/Script.cpp
               ../../../Sources/Parsing/Rulescplusplus.h ../../../Sources/Parsing/Rulescplusplus.cpp
               ../../../Sources/GeneratorCPlusPlus.h ../../../Sources/GeneratorCPusPlus.cpp
               ../../../Sources/evaluator.h ../../../Sources/evaluator.cpp
               ../../../Sources/Parsing/parserimplementationText.h ../../../Sources/Parsing/parserimplementationText.cpp
               ../../../Sources/Parsing/parserimplementationxml.h ../../../Sources/Parsing/parserimplementationxml.cpp
               ../../../Sources/Errorhandling/Xmlfileexception.h ../../../Sources/Errorhandling/Xmlfileexception.cpp
               main.cpp tst_testcodegenerator.h
               Source/mockparser.h Source/baseevaluator.h Source/evaluatetest.h Source/classTest.cpp
               Source/guiattribute.h Source/mockcpluspluscodegenerator.h Source/mockparser.h Source/systemtest.h Source/testdatagenerator.h Source/testutilities.h
               Source/evaluatetest.cpp Source/extractstringstest.cpp Source/functiontest.cpp Source/guiattribute.cpp Source/guidatamanagertest.cpp
               Source/mockcpluspluscodegenerator.cpp Source/parsertest.cpp Source/ReceiveDataTest.cpp Source/testdatagenerator.cpp Source/testutilities.cpp

               ${GTestSrc}/src/gtest-all.cc
               ${GMockSrc}/src/gmock-all.cc)
add_test(${PROJECT_NAME} COMMAND ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads Qt5::Core)

