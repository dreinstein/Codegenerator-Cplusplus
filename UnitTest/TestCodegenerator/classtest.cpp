
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


class Classtest: public ::testing::Test
{
protected:
    QString name;
    QString scriptPath;
    QFile fout;
    virtual void SetUp()
    {
        name = General::FilePath::HeaderFileName;
        QFile::remove(name);
        scriptPath = "..\\Files\\Scripts\\functionWithNoParameterReturnInt.txt";
        TestUtilities::FunctionTest(scriptPath);
        fout.setFileName(name);
    }

};




TEST_F(Classtest, headerFileExist)
{
    ASSERT_EQ(fout.exists(), true);
}

TEST_F(Classtest, headerProofClassString)
{
    ASSERT_EQ(fout.open(QIODevice::ReadOnly | QIODevice::Text),true);
    QByteArray line;
    line = fout.readLine();
    ASSERT_EQ(line,"Class");
}







