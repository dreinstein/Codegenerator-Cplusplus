#include "parsertest.h"
#include "../../gtest/gtest.h"
//#include "../../gmock/gmock.h"
#include "Parserimplementation.h"
#include <vector>
#include <string>

using namespace NParser;

ParserTest::ParserTest()
{
}

TEST(ParserTest, ReadFile) {
    ParserImpl *parser = new ParserImpl();
    std::vector<std::string> value = parser->doParse("..\\Files\\TestParser.txt");
    EXPECT_EQ("Parser Test successfully done", value[0]);
    delete parser;
}


TEST(ParserTest, GetValueFromParserImplementation) {
    ParserImpl *parser = new ParserImpl();
    std::vector<std::string> value = parser->doParse("..\\Files\\TestParser.txt");
    EXPECT_EQ("Parser Test successfully done", value[0]);
    delete parser;
}
