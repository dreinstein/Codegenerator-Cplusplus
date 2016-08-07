#include "../../gtest/gtest.h"
#include "../../gmock/gmock.h"
#include "Parsing\Parserimplementation.h"
#include <vector>
#include <map>
#include <QString>
#include <QtGlobal>
#include <memory>

using namespace NParser;

class ParserTest : public ::testing::Test {
 protected:
  std::unique_ptr<ParserImpl> parser;
  virtual void SetUp()
  {
      parser  =  std::unique_ptr<ParserImpl>(new ParserImpl());
  }

};


// check function to parser vector values
TEST_F(ParserTest, GetVecValuesFromParserImplementation)
{
    std::vector<QString> value = parser->doParseForVec("..\\Files\\Keywords\\myFirstKeywords.txt");
    EXPECT_EQ("class", value[0]);
}

// check function to parse map values
TEST_F(ParserTest, GetHashValuesFromParserImplementation) {
    std::map<QString, QString> value = parser->doParseForMap(("..\\Files\\Rules"));
    QString cwd = "..\\Files\\Rules\\class.txt";
    EXPECT_EQ(cwd, value["class"]);
}

