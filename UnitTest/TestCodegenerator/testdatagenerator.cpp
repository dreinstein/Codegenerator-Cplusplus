#include "testdatagenerator.h"
#include "Codegen/Codegeneratorconstants.h"

std::list<QString> TestdataGenerator::testDataFunctionNoParamterReturnInt()
{
    std::list<QString> testDatalist;
    QString functionName = "functionNoParameterReturnInt";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPublic);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::colon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typInt);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketClose);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);
    return testDatalist;
}


std::list<QString>TestdataGenerator::testDataFunctionNoParamterReturnQStringPointer()
{
    std::list<QString> testDatalist;
    QString functionName = "functionNoParameterReturnQStringPointer";
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::modifierPrivate);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::colon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::typQString);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::pointer);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::tab);
    testDatalist.push_back(functionName);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketOpen);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::parameterBracketClose);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::semiColon);
    testDatalist.push_back(Codegenerator::CodegeneratorConstants::newLine);
    return testDatalist;
}
