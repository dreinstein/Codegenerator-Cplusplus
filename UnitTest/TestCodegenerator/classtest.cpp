
#include "../../gtest/gtest.h"
//#include "../../gmock/gmock.h"
#include "mockparser.h"
#include "Parsing/Parserimplementation.h"
#include "Codegen/Basecodegenerator.h"
#include "Codegen/CPluspluscodegenerator.h"
#include "Codegen/Functionelements.h"
#include "codegen/Basecodegenerator.h"
#include "testutilities.h"
#include "testdatagenerator.h"
#include "evaluatetest.h"

using namespace NGenerator;
using namespace NParser;
using ::testing::Return;


class Classtest
{
protected:
    Classtest();
};




TEST(Classtest, headerFileExist)
{
    QString name = General::FilePath::HeaderFileName;
    QFile::remove(name);
    QString scriptPath = "..\\Files\\Scripts\\functionWithNoParameterReturnInt.txt";
    TestUtilities::FunctionTest(scriptPath);
    QFile Fout(name);
    EXPECT_EQ(Fout.exists(), true);
}



