#include "functiontest.h"
#include <list>
#include <QString>
#include <vector>
#include <map>
#include "../../gtest/gtest.h"
#include "Codegen/Basecodegenerator.h"
#include "Codegen/CPluspluscodegenerator.h"
#include "Parsing/Parserimplementation.h"
#include "testdatagenerator.h"
#include "evaluatetest.h"

FunctionTest::FunctionTest()
{

}

TEST(FunctionTest, functionNoParameterReturnInt)
{
    std::list<QString> expectedList;
    expectedList = TestdataGenerator::testDataFunctionNoParamterReturnInt();
    NParser::ParserImpl *parser = new NParser::ParserImpl();
    QString keywordPath = "..\\Files\\Keywords\\myFirstKeywords.txt";
    QString scriptPath = "..\\Files\\Scripts\\functionWithNoParameterReturnInt.txt";
    QString rulesPath = "..\\Files\\Rules\\";
    std::vector<QString> keywords = parser->doParseForVec(keywordPath);
    std::vector<QString> script = parser->doParseForVec(scriptPath);
    std::map<QString,QString> rules = parser->doParseForMap(rulesPath);
    Codegenerator::BaseCodegenerator *generator = new Codegenerator::CPlusPlusCodegenerator();
    generator->generate(script,rules,keywords);
    std::list<QString> classHeaderList = generator->getHeaderListData();
    bool result = false;
    result = EvaluateTest::evaluate(classHeaderList, expectedList);
    EXPECT_EQ(result, true);
    delete parser;
    delete generator;
}

TEST(FunctionTest, functionNoParameterReturnQStringPointer)
{
    std::list<QString> expectedList;
    expectedList = TestdataGenerator::testDataFunctionNoParamterReturnQStringPointer();
    NParser::ParserImpl *parser = new NParser::ParserImpl();
    QString keywordPath = "..\\Files\\Keywords\\myFirstKeywords.txt";
    QString scriptPath = "..\\Files\\Scripts\\functionWithNoParameterReturnQStringPointer.txt";
    QString rulesPath = "..\\Files\\Rules\\";
    std::vector<QString> keywords = parser->doParseForVec(keywordPath);
    std::vector<QString> script = parser->doParseForVec(scriptPath);
    std::map<QString,QString> rules = parser->doParseForMap(rulesPath);
    Codegenerator::BaseCodegenerator *generator = new Codegenerator::CPlusPlusCodegenerator();
    generator->generate(script,rules,keywords);
    std::list<QString> classHeaderList = generator->getHeaderListData();
    bool result = false;
    result = EvaluateTest::evaluate(classHeaderList, expectedList);
    EXPECT_EQ(result, true);
    delete parser;
    delete generator;
}




