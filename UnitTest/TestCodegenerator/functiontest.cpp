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

// Testcases Functions with no Parameter
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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

TEST(FunctionTest, functionNoParameterConstReturnvectorintConst)
{
    QString scriptPath = "..\\Files\\Scripts\\functionConstWithNoParameterReturnvectorint.txt";
    std::list<QString> expectedList;
    expectedList = TestdataGenerator::testDataFunctionConstNoParamterVectorInt();
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


// functions with one Parameter
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
TEST(FunctionTest, functionOneParameterReturnTestClassParameterTestClassReference)
{
    QString scriptPath = "..\\Files\\Scripts\\functionWithOneParameterReturnTestClassParameterTestClassReference.txt";
    std::list<QString> expectedList;
    expectedList = TestdataGenerator::testDataFunctionOneParmeterReturnTestClassParameterTestClassReference();
    std::list<QString> classHeaderList = TestUtilities::FunctionTest(scriptPath);
    bool result = false;
    result = EvaluateTest::evaluate(classHeaderList, expectedList);
    EXPECT_EQ(result, true);
}



TEST(FunctionTest, functionConstOneParameterReturnVectorIntParameterReferenceVectorInt)
{
    QString scriptPath = "..\\Files\\Scripts\\functionConstWithoneParameterReturnVectorIntParameterReferenceVectorInt.txt";
    std::list<QString> expectedList;
    expectedList = TestdataGenerator::testDataConstFunctionOneParmeterReturnVectorIntParameterVectorInt();
    std::list<QString> classHeaderList = TestUtilities::FunctionTest(scriptPath);
    bool result = false;
    result = EvaluateTest::evaluate(classHeaderList, expectedList);
    EXPECT_EQ(result, true);
}


TEST(FunctionTest, functionConstOneParameterReturnintReferenceParameterconstPointervoid)
{
    QString scriptPath = "..\\Files\\Scripts\\functionConstWithoneParameterReturnintReferneceParameterConstPointervoid.txt";
    std::list<QString> expectedList;
    expectedList = TestdataGenerator::testDataConstFunctionOneParmeterReturnIntRefernceParameterVoidConstPointer();
    std::list<QString> classHeaderList = TestUtilities::FunctionTest(scriptPath);
    bool result = false;
    result = EvaluateTest::evaluate(classHeaderList, expectedList);
    EXPECT_EQ(result, true);
}


// function with two parameter
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TEST(FunctionTest, functionTwoParameterReturnTestParameterPointerParameter1IntParameter2ConstTestParameterReference)
{
    QString scriptPath = "..\\Files\\Scripts\\functionWithTwoParameterReturnTestParameterPointerParameter1IntParameter2TestParameterConstReference.txt";
    std::list<QString> expectedList;
    expectedList = TestdataGenerator::testDataFunctionTwoParmeterReturnTestParameterParameterOneIntParameterTwoConstTestParameterReference();
    std::list<QString> classHeaderList = TestUtilities::FunctionTest(scriptPath);
    bool result = false;
    result = EvaluateTest::evaluate(classHeaderList, expectedList);
    EXPECT_EQ(result, true);
}





