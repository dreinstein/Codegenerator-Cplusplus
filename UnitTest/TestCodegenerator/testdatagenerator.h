#ifndef TESTDATAGENERATOR
#define TESTDATAGENERATOR

#include <List>
#include <QString>

class TestdataGenerator
{
public:
    static std::list<QString> testDataFunctionNoParamterReturnInt();
    static std::list<QString> testDataFunctionNoParamterReturnQStringPointer();
    static std::list<QString> testDataFunctionNoParamterTestClassReference();
    static std::list<QString> testDataFunctionConstNoParamterVectorInt();

    static std::list<QString> testDataFunctionOneParmeterReturnIntParameterDouble();
    static std::list<QString> testDataFunctionOneParmeterReturnTestClassParameterTestClassReference();
    static std::list<QString> testDataConstFunctionOneParmeterReturnVectorIntParameterVectorInt();
    static std::list<QString> testDataConstFunctionOneParmeterReturnIntRefernceParameterConstVoidPointer();
    static std::list<QString> testDataFunctionOneParmeterReturnDoubleParameterTestClassConstPointer();
    static std::list<QString>  testDatafunctionOneParameterReturnIntParameterIntDefaultValue31();
    static std::list<QString> testDataFunctionConstOneParmeterReturnConstPointerDoubleParameterConstPointerConstInt();
    static std::list<QString> testDataFunctionTwoParmeterReturnTestParameterParameterOneIntParameterTwoConstTestParameterReference();
    static std::list<QString> testDataFunctionConstTwoParameterReturnLongReferenceParameter1ConstReferenceDoubleParameter2ConstReferenceConstTestClass();
    static std::list<QString> testDatafunctionThreeParameterReturnDoubleParameter1DoubleParameter2intParameter3TestClass();
    static std::list<QString> testDatafunctionThreeParameterReturnDoubleParameter1DoubleParameter2intParameter3LongDefault12_2();
    static std::list<QString> testDataTwoEasyFunctions();
    static std::list<QString> testDataFourFunctionsMixedModifiers();
    static std::list<QString> testDataThreeComplexFunctions();
    static std::list<QString> testOneAttribute();
    static std::list<QString> testDataFourAttributesMixedModifiers();
    static std::list<QString> testDataFunctionsAttributesMixedModifiers();
    static std::list<QString> testSimpleClass();
    static std::list<QString> testDataClass();
    static std::list<QString> DatatestSourceFileFunctionNoParamterReturnInt();
    static std::list<QString> DatatestSourceFileFunctionOneParamterReturnDouble();


private:
    TestdataGenerator();
    static std::list<QString>testDataFunctionBegin(std::list<QString> testDatalist);
    static std::list<QString>testDataFunctionEnd(std::list<QString> testDatalist);
    static std::list<QString>testDataFunctionEndForConst(std::list<QString> testDatalist);
}
;

#endif // TESTDATAGENERATOR

