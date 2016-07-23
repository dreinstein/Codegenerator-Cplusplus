#include "classtest.h"


#include "../../gtest/gtest.h"
//#include "../../gmock/gmock.h"
#include "mockparser.h"
#include "Parsing/Parserimplementation.h"
#include "Codegen/Basecodegenerator.h"
#include "Codegen/CPluspluscodegenerator.h"
#include "Codegen/Functionelements.h"
#include "codegen/Basecodegenerator.h"
#include "testutilities.h"
#include "testdatagenerator.h"
#include "evaluatetest.h"

using namespace NGenerator;
using namespace NParser;
using ::testing::Return;


Classtest::Classtest()
{

}


// test function evaluate in class Evaluator
/*
TEST(ClassTest, generateClassCode) {
    QString scriptPath = "..\\Files\\Scripts\\classTestScript.txt";
    std::list<QString> expectedList = TestdataGenerator::testSimpleClass();
    std::list<QString> classHeaderList = TestUtilities::FunctionTest(scriptPath);
    //int result = EvaluateTest::evaluate(classHeaderList, expectedList);
    EXPECT_TRUE(EvaluateTest::evaluate(classHeaderList, expectedList));
}*/

/*
// test function evaluate in class Evaluator
TEST(Classtest, generateAttribute) {
    ParserImpl *parser = new ParserImpl();
    std::vector<QString> keywords = parser->doParseForVec("..\\Files\\Keywords\\myFirstKeywords.txt");
    std::vector<QString> script = parser->doParseForVec("..\\Files\\Scripts\\attributeTestScript.txt");
    std::map<QString,QString> rules = parser->doParseForMap("..\\Files\\Rules\\");
    Codegenerator::BaseCodegenerator *generator = new Codegenerator::CPlusPlusCodegenerator();
    generator->generate(script,rules,keywords);
    std::list<QString> classHeaderList = generator->getHeaderListData();
    std::list<QString>::iterator iter = classHeaderList.begin();
    bool isIncluded = (*iter == "class");
    std::advance(iter, 6);
    isIncluded = (*iter == "public");
    std::advance(iter, 4);
    isIncluded = (*iter  == "double");
    std::advance(iter, 2);
    isIncluded = (*iter == "myDoubleAttribute");
    std::advance(iter, 7);
    isIncluded = (*iter == "const int");
    std::advance(iter, 2);
    isIncluded = (*iter  == "myConstIntAttribute");
    std::advance(iter, 4);
    isIncluded = (*iter  == "char");
    std::advance(iter, 2);
    isIncluded = (*iter  == "myCharAttribute");
    EXPECT_EQ(isIncluded, true);
    delete parser;
    delete generator;
}


TEST(Classtest, generateClassAndFunctionWithNoParameter)
{
    ParserImpl *parser = new ParserImpl();
    std::vector<QString> keywords = parser->doParseForVec("..\\Files\\Keywords\\myFirstKeywords.txt");
    std::vector<QString> script = parser->doParseForVec("..\\Files\\Scripts\\functionTestScriptWithNoParameter.txt");
    std::map<QString,QString> rules = parser->doParseForMap("..\\Files\\Rules\\");
    Codegenerator::BaseCodegenerator *generator = new Codegenerator::CPlusPlusCodegenerator();
    generator->generate(script,rules,keywords);
    std::list<QString> classHeaderList = generator->getHeaderListData();
    std::list<QString>::iterator iter = classHeaderList.begin();
    bool isIncluded = (*iter == "class");
    std::advance(iter, 6);
    isIncluded = (*iter == "public");
    std::advance(iter, 6);
    isIncluded = (*iter  == "functionWithNoParameter");
    std::advance(iter, 1);
    isIncluded = (*iter == "(");
    std::advance(iter, 1);
    isIncluded = (*iter == ")");
    std::advance(iter, 1);
    isIncluded = (*iter  == ";");
    std::advance(iter, 2);
    isIncluded = (*iter  == "};");
    EXPECT_EQ(isIncluded, true);
    delete parser;
    delete generator;
}


TEST(Classtest, generateClassAndFunctionWithOneParameter)
{
    ParserImpl *parser = new ParserImpl();
    std::vector<QString> keywords = parser->doParseForVec("..\\Files\\Keywords\\myFirstKeywords.txt");
    std::vector<QString> script = parser->doParseForVec("..\\Files\\Scripts\\functionTestScriptWithOneParameter.txt");
    std::map<QString,QString> rules = parser->doParseForMap("..\\Files\\Rules\\");
    Codegenerator::BaseCodegenerator *generator = new Codegenerator::CPlusPlusCodegenerator();
    generator->generate(script,rules,keywords);
  //  Codegenerator::FunctionElements elements = generator->getFunctionElements();

    std::list<QString> classHeaderList = generator->getHeaderListData();
    std::list<QString>::iterator iter = classHeaderList.begin();
    bool isIncluded = (*iter == "class");
    std::advance(iter,2 );
    isIncluded = (*iter == "firstClass");
    std::advance(iter, 2);
    isIncluded = (*iter  == "{");
    std::advance(iter, 2);
    isIncluded = (*iter == "public");
    std::advance(iter, 1);
    isIncluded = (*iter == ":");
    std::advance(iter, 3);
    isIncluded = (*iter  == "double");
    std::advance(iter, 2);
    isIncluded = (*iter  == "functionwithOneParameter");
    std::advance(iter, 1);
    isIncluded = (*iter  == "(");
    std::advance(iter, 1);
    isIncluded = (*iter  == "double");
    std::advance(iter, 2);
    isIncluded = (*iter  == "parameter1");
    std::advance(iter, 1);
    isIncluded = (*iter  == ")");
    std::advance(iter, 1);
    isIncluded = (*iter  == ";");
    std::advance(iter, 2);
    isIncluded = (*iter  == "};");

    EXPECT_EQ(isIncluded, true);
    delete parser;
    delete generator;
}*/
