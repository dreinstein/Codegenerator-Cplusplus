#include "generatortest.h"
#include "../../gtest/gtest.h"
//#include "../../gmock/gmock.h"
#include "Utilities.h"
#include "evaluator.h"
#include "GeneratorCPlusPlus.h"
#include "Base/BaseGenerator.h"
#include "Base/BaseEvaluator.h"
#include "mockparser.h"
#include "Parserimplementation.h"


#include <vector>
#include <QString>

using namespace NGenerator;
using ::testing::Return;

const QString parserstring = "Parser Test successfully done";

GeneratorTest::GeneratorTest()
{
}

TEST(GeneratorTest, ReceiveDataKeyWords) {

    std::vector<QString> value;
    value.push_back("Parser Test successfully done");
    BaseGenerator *generator = new GeneratorCPlusPlus("");
    generator->receiveData(value,General::ParserId::Id::Keyword);
    std::vector<QString> keywordstrings = generator->getKeywords();
    EXPECT_EQ(parserstring, keywordstrings[0]);
    delete generator;
}

TEST(GeneratorTest, ReceiveDataRules) {
    std::vector<QString> value;
    value.push_back("Parser Test successfully done");
    BaseGenerator *generator = new GeneratorCPlusPlus("");
    generator->receiveData(value,General::ParserId::Id::Rules);
    std::vector<QString> rulesstrings = generator->getRules();
    EXPECT_EQ(parserstring, rulesstrings[0]);
    delete generator;
}

TEST(GeneratorTest, ReceiveDataScript) {
    std::vector<QString> value;
    value.push_back("Parser Test successfully done");
    BaseGenerator *generator = new GeneratorCPlusPlus("");
    generator->receiveData(value,General::ParserId::Id::Script);
    std::vector<QString> scriptstrings = generator->getScripts();
    EXPECT_EQ(parserstring, scriptstrings[0]);
    delete generator;
}

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


