#include "../../gtest/gtest.h"
#include "../../gmock/gmock.h"
#include "Parsing\ParserimplementationText.h"
#include "Parsing\ParserimplementationXML.h"
#include <vector>
#include <map>
#include <QString>
#include <QtGlobal>
#include <memory>

using namespace NParser;

class ParserTest : public ::testing::Test {
 protected:
  std::unique_ptr<ParserImplText> parserText;
  std::unique_ptr<ParserImplXML> parserXML;
  virtual void SetUp()
  {
      parserText  =  std::unique_ptr<ParserImplText>(new ParserImplText());
      parserXML  =   std::unique_ptr<ParserImplXML>(new ParserImplXML());
  }

};


// check function to parser vector values
TEST_F(ParserTest, GetVecValuesFromParserImplementationForTextFile)
{
    std::vector<QString> value = parserText->doParseForVec("..\\Files\\Keywords\\myFirstKeywords.txt");
    EXPECT_EQ("class", value[0]);
    EXPECT_EQ("attribute", value[1]);
    EXPECT_EQ("function", value[2]);
}

// check function to parse map values
TEST_F(ParserTest, GetHashValuesFromParserImplementation) {
    std::map<QString, QString> value = parserText->doParseForMap(("..\\Files\\Rules"));
    QString cwd = "..\\Files\\Rules\\class.txt";
    EXPECT_EQ(cwd, value["class"]);
}

// check function to parser vector values
TEST_F(ParserTest, GetVecValuesFromParserImplementationForXMLFile)
{
    std::vector<QString> value = parserXML.get()->doParseForVec("..\\Files\\Scripts\\xml\\functionWithNoParameterReturnInt.xml");
    EXPECT_EQ("class", value[0]);
  //  EXPECT_EQ("attribute", value[1]);
  //  EXPECT_EQ("function", value[2]);
}



