#include "../../gtest/gtest.h"
#include "../../gmock/gmock.h"
#include "Parsing\ParserimplementationText.h"
#include "Parsing\ParserimplementationXML.h"
#include "evaluatetest.h"
#include <vector>
#include <map>
#include <QString>
#include <QtGlobal>
#include <memory>

using namespace NParser;

class ParserTest : public ::testing::Test {
 protected:
  QString String0 = "@path::..\\Files\\Generated\\myFirstGeneratedFile";
  QString String1 = {"@function::functionint@modifier::private@typ::int"};
  QString String2 = {"@function::functiondouble@modifier::public@typ::double"};
  QString String3 = {"@function::functionlong@modifier::private@typ::long"};
  QString String4 = {"@function::functionTestClass@modifier::public@typ::TestClass"};
  QString String5 = {"@attribute::attributeint@modifier::public@typ::int"};
  QString String6 = {"@attribute::attributedouble@modifier::private@typ::double"};
  QString String7 = {"@attribute::attributelong@modifier::public@typ::long"};
  QString String8 = {"@attribute::attributeTestClass@modifier::public@typ::TestClass"};

  std::vector<QString> refValues = {String0,String1,String2,String3,String4,String5,String6,String7,String8};


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
    std::vector<QString> values = parserText->doParseForVec("..\\Files\\Scripts\\MixedFunctionsAndAttributes.txt");
    EvaluateTest::evaluateParserVector(values,refValues);


}

// check function to parser vector values
TEST_F(ParserTest, GetVecValuesFromParserImplementationForXMLFile)
{
    std::vector<QString> values = parserXML->doParseForVec("..\\Files\\Scripts\\xml\\MixedFunctionsAndAttributes.xml");
    EvaluateTest::evaluateParserVector(values,refValues);
}




// check function to parse map values
TEST_F(ParserTest, GetHashValuesFromParserImplementation) {
    std::map<QString, QString> value = parserText->doParseForMap(("..\\Files\\Rules"));
    QString cwd = "..\\Files\\Rules\\class.txt";
    ASSERT_EQ(cwd, value["class"]);
}









