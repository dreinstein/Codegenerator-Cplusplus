#include <QFile>
#include <QTextStream>
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
#include "Codegen/Basecodegenerator.h"
#include "Codegen/CPluspluscodegenerator.h"



#include <vector>
#include <QString>

using namespace NGenerator;
using namespace NParser;
using ::testing::Return;

const QString parserstring = "Directory";

GeneratorTest::GeneratorTest()
{
}


// check funcktion "receive data" keywords in generator file
TEST(GeneratorTest, ReceiveDataKeyWords) {

    std::vector<QString> value;
    value.push_back("Directory");
    BaseGenerator *generator = new GeneratorCPlusPlus("");
    generator->receiveData(value,General::ParserId::Id::Keyword);
    std::vector<QString> keywordstrings = generator->getKeywords();
    EXPECT_EQ(parserstring, keywordstrings[0]);
    delete generator;
}


// check funcktion "receive data" rules in generator file
TEST(GeneratorTest, ReceiveDataRules) {
    std::map<QString,QString> value;
    value["Test"] = "Directory";
    BaseGenerator *generator = new GeneratorCPlusPlus("");
    generator->receiveData(value,General::ParserId::Id::Rules);
    std::map<QString,QString> rulesstrings = generator->getRules();
    QString asstr = rulesstrings["Test"];
    EXPECT_EQ(parserstring, asstr);
    delete generator;
}


// check funcktion "receive data" script in generator file
TEST(GeneratorTest, ReceiveDataScript) {
    std::vector<QString> value;
    value.push_back("Directory");
    BaseGenerator *generator = new GeneratorCPlusPlus("");
    generator->receiveData(value,General::ParserId::Id::Script);
    std::vector<QString> scriptstrings = generator->getScripts();
    EXPECT_EQ(parserstring, scriptstrings[0]);
    delete generator;
}

// test function evaluate in class Evaluator
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

// test function evaluate in class Evaluator
TEST(GeneratorTest, generateClassCode) {
    QString path = "..\\Files\\Generated\\myFirstGeneratedFile.h";
    QFile fin(path);
    fin.remove();
    Codegenerator::BaseCodegenerator *generator = new Codegenerator::CPlusPlusCodegenerator();
    ParserImpl *parser = new ParserImpl();
    std::vector<QString> keywords = parser->doParseForVec("..\\Files\\Keywords\\myFirstKeywords.txt");
    std::vector<QString> script = parser->doParseForVec("..\\Files\\Scripts\\myFirstScript.txt");
    std::map<QString,QString> rules = parser->doParseForMap("..\\Files\\Rules\\");
    generator->generate(script,rules);
    bool open = fin.open(QIODevice::ReadOnly);
    EXPECT_EQ(true, open);
    QTextStream in (&fin);
    QString line;
    bool expectedValue = false;
    do
    {
        line = in.readLine();
        if (line.contains("class firstClass", Qt::CaseSensitive))
        {
            expectedValue = true;
        }
    }while (!line.isNull());
    fin.close();
    EXPECT_EQ(expectedValue, true);
}


