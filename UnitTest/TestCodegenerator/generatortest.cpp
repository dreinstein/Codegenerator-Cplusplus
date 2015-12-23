#include "generatortest.h"
#include "../../gtest/gtest.h"
//#include "../../gmock/gmock.h"
#include "evaluator.h"
#include "BaseEvaluator.h"
#include "GeneratorCPlusPlus.h"
#include "mockparser.h"
#include "BaseGenerator.h"
#include "Parserimplementation.h"
#include "Utilities.h"

#include <vector>
#include <string>

using namespace NGenerator;
using ::testing::Return;

const std::string parserstring = "Parser Test successfully done";

GeneratorTest::GeneratorTest()
{
}

TEST(GeneratorTest, ReceiveDataKeyWords) {

    std::vector<std::string> value;
    value.push_back("Parser Test successfully done");
    BaseGenerator *generator = new GeneratorCPlusPlus();
    generator->receiveData(value,General::ParserId::Id::Keyword);
    std::vector<std::string> keywordstrings = generator->getKeywords();
    EXPECT_EQ(parserstring, keywordstrings[0]);
    delete generator;
}

TEST(GeneratorTest, ReceiveDataRules) {
    std::vector<std::string> value;
    value.push_back("Parser Test successfully done");
    BaseGenerator *generator = new GeneratorCPlusPlus();
    generator->receiveData(value,General::ParserId::Id::Rules);
    std::vector<std::string> rulesstrings = generator->getRules();
    EXPECT_EQ(parserstring, rulesstrings[0]);
    delete generator;
}

TEST(GeneratorTest, ReceiveDataScript) {
    std::vector<std::string> value;
    value.push_back("Parser Test successfully done");
    BaseGenerator *generator = new GeneratorCPlusPlus();
    generator->receiveData(value,General::ParserId::Id::Script);
    std::vector<std::string> scriptstrings = generator->getScripts();
    EXPECT_EQ(parserstring, scriptstrings[0]);
    delete generator;
}

TEST(GeneratorTest, EvaluatorTest) {
    std::vector<std::string> keys;
    std::vector<std::string> script;
    keys.push_back("Class");
    keys.push_back("Function");
    keys.push_back("Name myFunctionName");
    keys.push_back("Attribute");
    keys.push_back("Public");
    keys.push_back("Value");
    script.push_back("@Class");
    script.push_back("@Name");
    script.push_back("@CFunction");
    script.push_back("@Name");
    script.push_back("@Value string");
    BaseEvaluator *evaluator = new ScriptEvaluator();
    bool ok = evaluator->evaluate(keys,script);
    EXPECT_EQ(ok, true);
}


