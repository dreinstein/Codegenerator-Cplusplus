#include "testutilities.h"
#include <vector>
#include <map>
#include <memory>
#include "testutilities.h"
#include "Codegen/Basecodegenerator.h"
#include "Parsing/ParserimplementationText.h"




std::list<QString> TestUtilities::FunctionTestHeaderList(QString codescript)
{
    std::unique_ptr<Codegenerator::CPlusPlusCodegenerator>generator(new Codegenerator::CPlusPlusCodegenerator());
    generate(generator.get(),codescript);
    std::list<QString>retValue =  generator->getHeaderListData();
    return retValue;
}

std::list<QString> TestUtilities::FunctionTestSourceList(QString codescript)
{
    std::unique_ptr<Codegenerator::CPlusPlusCodegenerator>generator(new Codegenerator::CPlusPlusCodegenerator());
    generate(generator.get(),codescript);
    std::list<QString>retValue =  generator->getSourceListData();
    return retValue;
}



void TestUtilities::generate(Codegenerator::BaseCodegenerator* generator,QString codescript)
{
    std::unique_ptr<NParser::ParserImplText> parser(new NParser::ParserImplText());
    QString keywordPath = "..\\Files\\Keywords\\myFirstKeywords.txt";
    QString rulesPath = "..\\Files\\Rules\\";
    std::vector<QString> keywords = parser->doParseForVec(keywordPath);
    std::vector<QString> script = parser->doParseForVec(codescript);
    std::map<QString,QString> rules = parser->doParseForMap(rulesPath);
    generator->generate(script,rules,keywords);
}
