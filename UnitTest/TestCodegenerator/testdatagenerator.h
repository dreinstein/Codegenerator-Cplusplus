#ifndef TESTDATAGENERATOR
#define TESTDATAGENERATOR

#include <List>
#include <QString>

class TestdataGenerator
{
public:
    static std::list<QString> testDataFunctionNoParamterReturnInt();
    static std::list<QString> testDataFunctionNoParamterReturnQStringPointer();

private:
    TestDataGenerator();
}
;

#endif // TESTDATAGENERATOR

