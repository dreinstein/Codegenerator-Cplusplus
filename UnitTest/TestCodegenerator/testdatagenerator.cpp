#include "testdatagenerator.h"
#include "Codegen/Codegeneratorconstants.h"

std::list<QString> TestdataGenerator::testDataFunctionNoParamterReturnInt()
{
    std::list<QString> testDatalist;
    QString functionName = "functionNoParameterReturnInt";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
     testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);
    return testDatalist;
}


std::list<QString>TestdataGenerator::testDataFunctionNoParamterReturnQStringPointer()
{
    std::list<QString> testDatalist;
    QString functionName = "functionNoParameterReturnQStringPointer";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPrivate);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typQString);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::pointer);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
     testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);
    return testDatalist;
}

std::list<QString>TestdataGenerator::testDataFunctionNoParamterTestClassReference()
{
    std::list<QString> testDatalist;
    QString functionName = "functionNoParameterReturnTestClassReference";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typTestClass);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::reference);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
     testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);
    return testDatalist;
}

std::list<QString>TestdataGenerator::testDataFunctionConstNoParamterVectorInt()
{
    std::list<QString> testDatalist;
    QString functionName = "functionConstWithNoParameterReturnVectorInt";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typVectorInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist = TestdataGenerator::testDataFunctionEndForConst(testDatalist);
    return testDatalist;
}



std::list<QString>TestdataGenerator::testDataFunctionOneParmeterReturnIntParameterDouble()
{
    std::list<QString> testDatalist;
    QString functionName = "functionWithOnParameterReturnintParameterDouble";
    QString parameterName = "parameter";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPrivate);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName);
    testDatalist = testDataFunctionEnd(testDatalist);
    return testDatalist;
}

std::list<QString>TestdataGenerator::testDataFunctionOneParmeterReturnTestClassParameterTestClassReference()
{
    std::list<QString> testDatalist;
    QString functionName = "functionWithOnParameterReturnTestClassParameterTestClassReference";
    QString parameterName = "TestClassParameter";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierProtected);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::reference);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName);
    testDatalist = testDataFunctionEnd(testDatalist);
    return testDatalist;
}


std::list<QString>TestdataGenerator::testDataConstFunctionOneParmeterReturnVectorIntParameterVectorInt()
{
    std::list<QString> testDatalist;
    QString functionName = "functionConstWithOneParameterReturnVectorIntParameterReferenceVectorInt";
    QString parameterName = "ParameterVectorInt";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierProtected);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typVectorInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typVectorInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::reference);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName);
    testDatalist = TestdataGenerator::testDataFunctionEndForConst(testDatalist);
    return testDatalist;
}

std::list<QString>TestdataGenerator::testDataConstFunctionOneParmeterReturnIntRefernceParameterConstVoidPointer()
{
    std::list<QString> testDatalist;
    QString functionName = "functionWithOnParameterReturnIntReferenceParameterConstVoidPointer";
    QString parameterName = "VoidConstPointerParameter";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::reference);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typVoid);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::pointer);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName);
    testDatalist = TestdataGenerator::testDataFunctionEndForConst(testDatalist);
    return testDatalist;
}


std::list<QString>TestdataGenerator::testDataFunctionOneParmeterReturnDoubleParameterTestClassConstPointer()
{
    std::list<QString> testDatalist;
    QString functionName = "functionWithOnParameterReturnDoubleParameterTestClassConstPointer";
    QString parameterName = "TestClassParameter";
    QString parameterTyp = "TestClass";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierProtected);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(parameterTyp);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::pointer);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);
    return testDatalist;
}


std::list<QString>TestdataGenerator::testDataFunctionConstOneParmeterReturnConstPointerDoubleParameterConstPointerConstInt()
{
    std::list<QString> testDatalist;
    QString functionName = "functionConstWithOneParameterReturnConstPointerDoubleParameterTestConstPointerConstInteger";
    QString parameterName = "ConstPointerConstInteger";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPrivate);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::pointer);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::pointer);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName);
    testDatalist = TestdataGenerator::testDataFunctionEndForConst(testDatalist);
    return testDatalist;
}



std::list<QString>TestdataGenerator::testDatafunctionOneParameterReturnIntParameterIntDefaultValue31()
{
    std::list<QString> testDatalist;
    QString functionName = "functionOneParameterReturnIntParameterIntDefaultValue31";
    QString parameterName = "IntDefaultValue31";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::equal);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back("31");
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);
    return testDatalist;
}





std::list<QString>TestdataGenerator::testDataFunctionTwoParmeterReturnTestParameterParameterOneIntParameterTwoConstTestParameterReference()
{
    std::list<QString> testDatalist;
    QString functionName = "functionWithTwoParameterReturnIntReferenceParameterConstVoidPointer";
    QString parameterName1 = "intParameter";
    QString parameterName2 = "TestParameter";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPrivate);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName1);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::comma);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::reference);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName2);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);
    return testDatalist;
}





std::list<QString>TestdataGenerator::testDataFunctionConstTwoParameterReturnLongReferenceParameter1ConstReferenceDoubleParameter2ConstReferenceConstTestClass()
{
    std::list<QString> testDatalist;
    QString functionName = "functionConstWithTwoParameterReturnLongReferenceParameter1ConstReferenceDoubleParameter2ConstReferenceConstTestClass";
    QString parameterName1 = "constReferenceDouble";
    QString parameterName2 = "ConstReferenceConstTestClass";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPrivate);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typLong);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::reference);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::reference);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName1);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::comma);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::reference);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName2);
    testDatalist = TestdataGenerator::testDataFunctionEndForConst(testDatalist);
    return testDatalist;
}

std::list<QString>TestdataGenerator::testDatafunctionThreeParameterReturnDoubleParameter1DoubleParameter2intParameter3TestClass()
{
    std::list<QString> testDatalist;
    QString functionName = "functionThreeParameterReturnDoubleParameter1DoubleParameter2intParameter3TestClass";
    QString parameterName1 = "doubleParameter";
    QString parameterName2 = "intParameter";
    QString parameterName3 = "TestClassParameter";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName1);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::comma);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName2);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::comma);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName3);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);
    return testDatalist;
}


std::list<QString>TestdataGenerator::testDatafunctionThreeParameterReturnDoubleParameter1DoubleParameter2intParameter3LongDefault12_2()
{
    std::list<QString> testDatalist;
    QString functionName = "functionThreeParameterReturnDoubleParameter1DoubleParameter2intParameter3TestClass";
    QString parameterName1 = "doubleParameter";
    QString parameterName2 = "intParameter";
    QString parameterName3 = "longParameterDefault12_2";
    QString parameter3Value = "12,2";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName1);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::comma);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName2);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::comma);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typLong);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName3);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::equal);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameter3Value);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);
    return testDatalist;
}


std::list<QString>TestdataGenerator::testDataTwoEasyFunctions()
{
    std::list<QString> testDatalist;
    QString function1Name = "functionReturnDoubleNoParameter";
    QString function2Name = "functionReturnIntParameterDouble";
    QString parameterName = "doubleParameter";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(function1Name);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(function2Name);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);
    return testDatalist;
}


// Function one:  public int* (const double&,TestClass*, int = 5) const
// Function two:  public double (int *, long)
// Function three: privat const Testclass& (const * const double, int) const
std::list<QString>TestdataGenerator::testDataThreeComplexFunctions()
{
    std::list<QString> testDatalist;
    QString function1Name = "functionintPointer";
    QString function2Name = "functionReturndouble";
    QString function3Name = "functionReturnTestClassReference";
    QString parameterName1 = "constDoubleReferenceParameter";
    QString parameterName2 = "TestClassPointerParameter";
    QString parameterName3 = "intParameter";
    QString parameterName4 = "intPointerParameter";
    QString parameterName5 = "longParameter";
    QString parameterName6 = "constPointerconstParameter";
    QString parameterName7 = "intParameter";

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::pointer);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(function1Name);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::reference);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName1);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::comma);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::pointer);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName2);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::comma);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName3);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::equal);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back("5");
    testDatalist = TestdataGenerator::testDataFunctionEndForConst(testDatalist);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(function2Name);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::pointer);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName4);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::comma);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typLong);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName5);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);


    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPrivate);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::reference);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(function3Name);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::pointer);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName6);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::comma);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(parameterName7);
    testDatalist = TestdataGenerator::testDataFunctionEndForConst(testDatalist);

    return testDatalist;
}



std::list<QString>TestdataGenerator::testDataFourFunctionsMixedModifiers()
{
    std::list<QString> testDatalist;
    QString function1Name = "functionint";
    QString function2Name = "functionReturndouble";
    QString function3Name = "functionReturnTestClass";
    QString function4Name = "functionReturnlong";
    QString functionReturnTestClass = "functionReturnTestClass";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(function1Name);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typLong);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(function4Name);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(function3Name);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);


    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPrivate);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(function2Name);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist = TestdataGenerator::testDataFunctionEnd(testDatalist);

    return testDatalist;
}


std::list<QString>TestdataGenerator::testOneAttribute()
{
    QString attributeName1 = "doubleAttribute";
    std::list<QString> testDatalist;
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName1);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);
    return testDatalist;
}



std::list<QString>TestdataGenerator::testDataFunctionsAttributesMixedModifiers()
{
    QString functionName1 = "functionint";
    QString functionName2 = "functiondouble";
    QString functionName3 = "functionlong";
    QString functionName4 = "functionTestClass";
    QString attributeName1 = "attributeint";
    QString attributeName2 = "attributendouble";
    QString attributeName3 = "attributelong";
    QString attributeName4 = "attributeTestClass";

    std::list<QString> testDatalist;

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);

    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName2);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketClose);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName4);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketClose);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);


    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName1);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typLong);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName3);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);


    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName4);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPrivate);

    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName1);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketClose);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typLong);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName3);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketClose);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName2);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    return testDatalist;
}


std::list<QString>TestdataGenerator::testDataFourAttributesMixedModifiers()
{
    QString attributeName1 = "attributeint";
    QString attributeName2 = "attributendouble";
    QString attributeName3 = "attributelong";
    QString attributeName4 = "attributeTestClass";
    std::list<QString> testDatalist;
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName1);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typLong);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName3);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName4);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPrivate);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName2);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    return testDatalist;
}


std::list<QString>TestdataGenerator::testSimpleClass()
{
    std::list<QString> testDatalist;
    testDatalist.push_back("Class");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back("firstClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    return testDatalist;
}


std::list<QString>TestdataGenerator::testDataFunctionBegin(std::list<QString> testDatalist)
{
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::colon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    return testDatalist;
}

std::list<QString>TestdataGenerator::testDataFunctionEnd(std::list<QString> testDatalist)
{

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketClose);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);
    return testDatalist;
}

std::list<QString>TestdataGenerator::testDataFunctionEndForConst(std::list<QString> testDatalist)
{

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketClose);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::constant);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);
    return testDatalist;
}

std::list<QString>TestdataGenerator::testDataClass()
{
    QString className = "myClass";
    QString functionName1 = "functionint";
    QString functionName2 = "functiondouble";
    QString functionName3 = "functionlong";
    QString functionName4 = "functionTestClass";
    QString attributeName1 = "attributeint";
    QString attributeName2 = "attributendouble";
    QString attributeName3 = "attributelong";
    QString attributeName4 = "attributeTestClass";

    std::list<QString> testDatalist;

    testDatalist.push_back("class");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(className);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::bracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);


    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName2);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketClose);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName4);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketClose);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);


    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName1);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typLong);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName3);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);


    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back("TestClass");
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName4);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPrivate);

    testDatalist = TestdataGenerator::testDataFunctionBegin(testDatalist);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName1);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketClose);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typLong);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName3);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketClose);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typDouble);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(attributeName2);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    testDatalist.push_back(Codegenerator::CodegeneratorConstants::BracketWithSemiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);
  //  testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);

    return testDatalist;
}











