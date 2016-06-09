#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include "generatortest.h"
#include "../../gtest/gtest.h"
//#include "../../gmock/gmock.h"
#include "Utilities.h"
#include "evaluator.h"
#include "GeneratorCPlusPlus.h"
#include "Base/BaseGenerator.h"
#include "Base/BaseEvaluator.h"
#include "mockparser.h"
#include "Parsing/Parserimplementation.h"
#include "Codegen/Basecodegenerator.h"
#include "Codegen/CPluspluscodegenerator.h"
#include "Codegen/Functionelements.h"
#include "codegen/Basecodegenerator.h"



#include <vector>
#include <QString>
#include <QStringList>
#include <algorithm>

using namespace NGenerator;
using namespace NParser;
using ::testing::Return;

const QString parserstring = "Directory";

GeneratorTest::GeneratorTest()
{
}


// check funcktion "receive data" keywords in generator file
TEST(GeneratorTest, ReceiveDataKeyWords) {
    std::vector<QString> value;
    value.push_back("Directory");
    BaseGenerator *generator = new GeneratorCPlusPlus("");
    generator->receiveData(value,General::ParserId::Id::Keyword);
    std::vector<QString> keywordstrings = generator->getKeywords();
    EXPECT_EQ(parserstring, keywordstrings[0]);
    delete generator;
}


// check funcktion "receive data" rules in generator file
TEST(GeneratorTest, ReceiveDataRules) {
    std::map<QString,QString> value;
    value["Test"] = "Directory";
    BaseGenerator *generator = new GeneratorCPlusPlus("");
    generator->receiveData(value,General::ParserId::Id::Rules);
    std::map<QString,QString> rulesstrings = generator->getRules();
    QString asstr = rulesstrings["Test"];
    EXPECT_EQ(parserstring, asstr);
    delete generator;
}


// check funcktion "receive data" script in generator file
TEST(GeneratorTest, ReceiveDataScript) {
    std::vector<QString> value;
    value.push_back("Directory");
    BaseGenerator *generator = new GeneratorCPlusPlus("");
    generator->receiveData(value,General::ParserId::Id::Script);
    std::vector<QString> scriptstrings = generator->getScripts();
    EXPECT_EQ(parserstring, scriptstrings[0]);
    delete generator;
}

// test function evaluate in class Evaluator
TEST(GeneratorTest, EvaluatorTest) {
    std::vector<QString> keys;
    std::vector<QString> script;
    keys.push_back("Class");
    keys.push_back("Function");
    keys.push_back("Name");
    keys.push_back("Attribute");
    keys.push_back("Public");
    keys.push_back("Value");
    script.push_back("@Class");
    script.push_back("@Name::myClassName");
    script.push_back("@Function");
    script.push_back("@Name::myFunctionName");
    script.push_back("@Value::string");
    BaseEvaluator *evaluator = new ScriptEvaluator();
    bool ok = evaluator->evaluate(keys,script);
    EXPECT_EQ(ok, true);
}

TEST(GeneratorTest, extractStringFirst)
{
    QString testString = "@class::firstClass";
    testString = General::ExtractString::extractFirst(testString);
    EXPECT_EQ("class",testString);
}

TEST(GeneratorTest, extractStringLast)
{
    QString testString = "@class::firstClass";
    testString = General::ExtractString::extractLast(testString);
    EXPECT_EQ("firstClass",testString);
}


TEST(GeneratorTest, extractStringList)
{
    QString testString = "@modifier::private@typ::int@attribute::myfirstAttribute";
    QStringList stringList = General::ExtractString::extractStringList(testString);
    EXPECT_EQ("@modifier::private",stringList.at(0));
    EXPECT_EQ("@typ::int",stringList.at(1));
    EXPECT_EQ("@attribute::myfirstAttribute",stringList.at(2));
}


// test function evaluate in class Evaluator
TEST(GeneratorTest, generateClassCode) {
    ParserImpl *parser = new ParserImpl();
    std::vector<QString> keywords = parser->doParseForVec("..\\Files\\Keywords\\myFirstKeywords.txt");
    std::vector<QString> script = parser->doParseForVec("..\\Files\\Scripts\\classTestScript.txt");
    std::map<QString,QString> rules = parser->doParseForMap("..\\Files\\Rules\\");
    Codegenerator::BaseCodegenerator *generator = new Codegenerator::CPlusPlusCodegenerator();
    generator->generate(script,rules,keywords);
    std::list<QString> classHeaderList = generator->getHeaderListData();
    bool isClassAttributeIncluded = (std::find(classHeaderList.begin(), classHeaderList.end(), "class") != classHeaderList.end());
    bool isBracketOpenIncluded = false;
    bool isClassNameIncluded = false;
    bool isAllIncluded = false;
    if(isClassAttributeIncluded)
    {
        isClassNameIncluded = (std::find(classHeaderList.begin(), classHeaderList.end(), "firstClass") != classHeaderList.end());
    }
    if(isClassAttributeIncluded && isClassNameIncluded )
    {
        isBracketOpenIncluded = (std::find(classHeaderList.begin(), classHeaderList.end(), "{") != classHeaderList.end());
    }
    if(isClassAttributeIncluded && isClassNameIncluded && isBracketOpenIncluded )
    {
        isAllIncluded = (std::find(classHeaderList.begin(), classHeaderList.end(), "};") != classHeaderList.end());
    }
    EXPECT_EQ(isAllIncluded, true);
}




// test function evaluate in class Evaluator
TEST(GeneratorTest, generateAttribute) {
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
}


TEST(GeneratorTest, generateFunctionWithNoParameter)
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
    isIncluded = (*iter  == "firstClass");
    std::advance(iter, 1);
    isIncluded = (*iter == ":");
    std::advance(iter, 1);
    isIncluded = (*iter == ":");
    std::advance(iter, 1);
    isIncluded = (*iter  == "functionwithNoParameter");
    std::advance(iter, 2);
    isIncluded = (*iter  == ")");
    std::advance(iter, 6);
    isIncluded = (*iter  == "};");
    EXPECT_EQ(isIncluded, true);
}


TEST(GeneratorTest, generateFunctionWithOneParameter)
{
    ParserImpl *parser = new ParserImpl();
    std::vector<QString> keywords = parser->doParseForVec("..\\Files\\Keywords\\myFirstKeywords.txt");
    std::vector<QString> script = parser->doParseForVec("..\\Files\\Scripts\\functionTestScriptWithOneParameter.txt");
    std::map<QString,QString> rules = parser->doParseForMap("..\\Files\\Rules\\");
    Codegenerator::BaseCodegenerator *generator = new Codegenerator::CPlusPlusCodegenerator();
    generator->generate(script,rules,keywords);
    Codegenerator::FunctionElements elements = generator->getFunctionElements();

    std::list<QString> classHeaderList = generator->getHeaderListData();
    std::list<QString>::iterator iter = classHeaderList.begin();
    bool isIncluded = (*iter == "class");
  /*  std::advance(iter, 6);
    isIncluded = (*iter == "public");
    std::advance(iter, 6);
    isIncluded = (*iter  == "firstClass");
    std::advance(iter, 1);
    isIncluded = (*iter == ":");
    std::advance(iter, 1);
    isIncluded = (*iter == ":");
    std::advance(iter, 1);
    isIncluded = (*iter  == "functionwithNoParameter");
    std::advance(iter, 2);
    isIncluded = (*iter  == ")");
    std::advance(iter, 6);
    isIncluded = (*iter  == "};");*/
    EXPECT_EQ(isIncluded, true);
}


// test function evaluate in class Evaluator
/*TEST(GeneratorTest, testHeaderFile) {
    ParserImpl *parser = new ParserImpl();
    std::vector<QString> keywords = parser->doParseForVec("..\\Files\\Keywords\\myFirstKeywords.txt");
    std::vector<QString> script = parser->doParseForVec("..\\Files\\Scripts\\attributeTestScript.txt");
    std::map<QString,QString> rules = parser->doParseForMap("..\\Files\\Rules\\");
    Codegenerator::BaseCodegenerator *generator = new Codegenerator::CPlusPlusCodegenerator();
    generator->generate(script,rules,keywords);

    QFile hfile(General::FilePath::HeaderFileName);
    hfile.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray line;
    bool classWritten = false;
    bool attributeWritten = false;
    bool bracketWritten = false;

    while (!hfile.atEnd())
    {
           QByteArray line = hfile.readLine();
           if("class firstClass\n" == line)
           {
               classWritten = true;
           }
           if("   const int myConstIntAttribute;\n" == line)
           {
               attributeWritten = true;
           }
           if("};\n" == line)
           {
               bracketWritten = true;
           }
    }


    EXPECT_EQ(classWritten && attributeWritten && bracketWritten , true);
}*/


