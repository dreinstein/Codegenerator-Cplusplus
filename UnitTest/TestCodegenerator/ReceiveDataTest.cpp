
#include <memory>
#include "../../gtest/gtest.h"
#include "../../gmock/gmock.h"
#include "GeneratorCPlusPlus.h"
#include "Parsing/Parserimplementation.h"

#include <vector>
#include <list>
#include <QString>

using namespace NGenerator;
using namespace NParser;
using ::testing::Return;

const QString parserstring = "Directory";

class ReceiveDataTest: public ::testing::Test
{
protected:
    std::unique_ptr<GeneratorCPlusPlus>generator;
    QString parserstring;
    virtual void SetUp()
    {
       parserstring = "Directory";
       generator = std::unique_ptr<GeneratorCPlusPlus>(new  GeneratorCPlusPlus(""));
    }
};



TEST_F(ReceiveDataTest, ReceiveKeyWordData) {
    std::vector<QString> value;
    value.push_back("Directory");
    generator->receiveData(value,General::ParserId::Id::Keyword);
    std::vector<QString> keywordstrings = generator->getKeywords();
    ASSERT_EQ(parserstring, keywordstrings[0]);
}


// check funcktion "receive data" rules in generator file
TEST_F(ReceiveDataTest, ReceiveDataRules) {
    std::map<QString,QString> value;
    value["Test"] = "Directory";
    generator->receiveData(value,General::ParserId::Id::Rules);
    std::map<QString,QString> rulesstrings = generator->getRules();
    QString asstr = rulesstrings["Test"];
    ASSERT_EQ(parserstring, asstr);
}


// check funcktion "receive data" script in generator file
TEST_F(ReceiveDataTest, ReceiveDataScript) {
    std::vector<QString> value;
    value.push_back("Directory");
    generator->receiveData(value,General::ParserId::Id::Script);
    std::vector<QString> scriptstrings = generator->getScripts();
    ASSERT_EQ(parserstring, scriptstrings[0]);
}




/*
TEST(BasicTest, extractStringFirst)
{
    QString testString = "@class::firstClass";
    testString = General::ExtractString::extractFirst(testString);
    EXPECT_EQ("class",testString);
}

TEST(BasicTest, extractStringLast)
{
    QString testString = "@class::firstClass";
    testString = General::ExtractString::extractLast(testString);
    EXPECT_EQ("firstClass",testString);
}


TEST(BasicTest, extractStringList)
{
    QString testString = "@modifier::private@typ::int@attribute::myfirstAttribute";
    QStringList stringList = General::ExtractString::extractStringList(testString);
    EXPECT_EQ("@modifier::private",stringList.at(0));
    EXPECT_EQ("@typ::int",stringList.at(1));
    EXPECT_EQ("@attribute::myfirstAttribute",stringList.at(2));
}

TEST(BasicTest, extractParameter)
{
    QString testString = "@modifier::public@typ::double@parameter::parameter1@typ::double";
    QString parameterString = General::ExtractString::extractParameter(testString);
    EXPECT_EQ("@typ::double",parameterString);
}


// test function evaluate in class Evaluator
TEST(BasicTest, generateClassCode) {
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
    delete parser;
    delete generator;
}*/

