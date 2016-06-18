#include "functiontest.h"
#include <list>
#include <QString>
#include <vector>
#include <map>
#include "../../gtest/gtest.h"
#include "testdatagenerator.h"
#include "evaluatetest.h"
#include "testutilities.h"

FunctionTest::FunctionTest()
{

}

// Testcases Function with no Parameter

TEST(FunctionTest, functionNoParameterReturnInt)
{
    QString scriptPath = "..\\Files\\Scripts\\functionWithNoParameterReturnInt.txt";
    std::list<QString> expectedList;
    expectedList = TestdataGenerator::testDataFunctionNoParamterReturnInt();
    std::list<QString> classHeaderList = TestUtilities::FunctionTest(scriptPath);
    bool result = false;
    result = EvaluateTest::evaluate(classHeaderList, expectedList);
    EXPECT_EQ(result, true);
}

TEST(FunctionTest, functionNoParameterReturnQStringPointer)
{
    QString scriptPath = "..\\Files\\Scripts\\functionWithNoParameterReturnQStringPointer.txt";
    std::list<QString> expectedList;
    expectedList = TestdataGenerator::testDataFunctionNoParamterReturnQStringPointer();
    std::list<QString> classHeaderList = TestUtilities::FunctionTest(scriptPath);
    bool result = false;
    result = EvaluateTest::evaluate(classHeaderList, expectedList);
    EXPECT_EQ(result, true);
}

TEST(FunctionTest, functionNoParameterTestclassReference)
{
    QString scriptPath = "..\\Files\\Scripts\\functionWithNoParameterReturnTestClassReference.txt";
    std::list<QString> expectedList;
    expectedList = TestdataGenerator::testDataFunctionNoParamterTestClassReference();
    std::list<QString> classHeaderList = TestUtilities::FunctionTest(scriptPath);
    bool result = false;
    result = EvaluateTest::evaluate(classHeaderList, expectedList);
    EXPECT_EQ(result, true);
}


TEST(FunctionTest, functionOneParameterReturninParameterDouble)
{
    QString scriptPath = "..\\Files\\Scripts\\functionWithOneParameterReturnintParameterDouble.txt";
    std::list<QString> expectedList;
    expectedList = TestdataGenerator::testDataFunctionOneParmeterReturnIntParameterDouble();
    std::list<QString> classHeaderList = TestUtilities::FunctionTest(scriptPath);
    bool result = false;
    result = EvaluateTest::evaluate(classHeaderList, expectedList);
    EXPECT_EQ(result, true);
}




// Testcases Function with one Parameter



