#include "parsertest.h"
#include "../../gtest/gtest.h"
//#include "../../gmock/gmock.h"
#include "Parsing\Parserimplementation.h"
#include <vector>
#include <map>
#include <QString>
#include <unistd.h>
#include <QtGlobal>

using namespace NParser;

ParserTest::ParserTest()
{
}

// check function to parser vector values
TEST(ParserTest, GetVecValuesFromParserImplementation) {
    ParserImpl *parser = new ParserImpl();
    std::vector<QString> value = parser->doParseForVec("..\\Files\\Keywords\\myFirstKeywords.txt");
    EXPECT_EQ("class", value[0]);
    delete parser;
}

// check function to parse map values
TEST(ParserTest, GetHashValuesFromParserImplementation) {
    ParserImpl *parser = new ParserImpl();
    std::map<QString, QString> mapValues = parser->doParseForMap(("..\\Files\\Rules"));
    QString cwd = "..\\Files\\Rules\\class.txt";
    EXPECT_EQ(cwd, mapValues["class"]);
    delete parser;
}
