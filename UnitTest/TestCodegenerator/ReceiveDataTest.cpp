
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


