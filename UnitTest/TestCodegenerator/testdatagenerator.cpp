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



