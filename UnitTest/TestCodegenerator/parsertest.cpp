#include "parsertest.h"
#include "../../gtest/gtest.h"
//#include "../../gmock/gmock.h"
#include "Parserimplementation.h"
#include <vector>
#include <map>
#include <QString>
#include <unistd.h>
#include <QtGlobal>

using namespace NParser;

ParserTest::ParserTest()
{
}

TEST(ParserTest, ReadFile) {
    ParserImpl *parser = new ParserImpl();
    std::vector<QString> value = parser->doParseForVec("..\\Files\\TestParser.txt");
    EXPECT_EQ("Parser Test successfully done", value[0]);
    delete parser;
}


TEST(ParserTest, GetVecValuesFromParserImplementation) {
    ParserImpl *parser = new ParserImpl();
    std::vector<QString> value = parser->doParseForVec("..\\Files\\TestParser.txt");
    EXPECT_EQ("Parser Test successfully done", value[0]);
    delete parser;
}

TEST(ParserTest, GetHashValuesFromParserImplementation) {
    ParserImpl *parser = new ParserImpl();
    std::map<QString, QString> mapValues = parser->doParseForMap(("..\\Files"));
    QString cwd = "..\\Files\\Class.txt";
    EXPECT_EQ(cwd, mapValues["Class"]);
    delete parser;
}
