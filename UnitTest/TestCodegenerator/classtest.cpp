
#include "../../gtest/gtest.h"
#include "../../gmock/gmock.h"
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


class HeaderFiletest: public ::testing::Test
{
protected:
    QString nameHeader;
    QString scriptPathHeader;
    QFile foutHeader;
    virtual void SetUp()
    {
        nameHeader = General::FilePath::HeaderFileName;
        QFile::remove(nameHeader);
        scriptPathHeader = "..\\Files\\Scripts\\attributeTestScript.txt";
        TestUtilities::FunctionTestHeaderList(scriptPathHeader);
        foutHeader.setFileName(nameHeader);
    }
};


class SourceFiletest: public ::testing::Test
{
protected:
    QString nameSource;
    QString scriptPathSource;
    QFile foutSource;
    virtual void SetUp()
    {
        nameSource = General::FilePath::SourceFileName;
        QFile::remove(nameSource);
        scriptPathSource = "..\\Files\\Scripts\\ClassMixedFunctionsAndAttributes.txt";
        TestUtilities::FunctionTestSourceList(scriptPathSource);
        foutSource.setFileName(nameSource);
    }
};




TEST_F(HeaderFiletest, headerFileExist)
{
    ASSERT_EQ(foutHeader.exists(), true);
}

TEST_F(HeaderFiletest, headerProofClassString)
{
    ASSERT_EQ(foutHeader.open(QIODevice::ReadOnly | QIODevice::Text),true);
    QByteArray line;
    line = foutHeader.readLine();
    ASSERT_THAT(line,testing::Eq("class   myTestClass\n"));
    
}


TEST_F(SourceFiletest, sourceFileExist)
{
    ASSERT_EQ(foutSource.exists(), true);
}



TEST_F(SourceFiletest, sourceFileProof)
{
    ASSERT_EQ(foutSource.open(QIODevice::ReadOnly | QIODevice::Text),true);
    QByteArray line;
    line = foutSource.readLine();
    line = foutSource.readLine();
    ASSERT_THAT(line,testing::Eq("int   myClass::functionint()\n"));
    line = foutSource.readLine();
    line = foutSource.readLine();
    line = foutSource.readLine();
    line = foutSource.readLine();
    line = foutSource.readLine();
    line = foutSource.readLine();
    line = foutSource.readLine();
    line = foutSource.readLine();
    line = foutSource.readLine();
    ASSERT_THAT(line,testing::Eq("TestClass   myClass::functionTestClass()\n"));
}







