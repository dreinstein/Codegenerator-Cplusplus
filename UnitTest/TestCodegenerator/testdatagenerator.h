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
    static std::list<QString> testDataFunctionOneParmeterReturnIntParameterDouble();



private:
    TestDataGenerator();
    static std::list<QString> testDataFunctionBegin(std::list<QString> testDatalist);
    static std::list<QString>testDataFunctionEnd(std::list<QString> testDatalist);
}
;

#endif // TESTDATAGENERATOR

