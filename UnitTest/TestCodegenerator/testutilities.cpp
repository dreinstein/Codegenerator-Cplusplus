#include "testutilities.h"
#include <vector>
#include <map>
#include <memory>
#include "testutilities.h"
#include "Codegen/Basecodegenerator.h"
#include "Parsing/Parserimplementation.h"




std::list<QString> TestUtilities::FunctionTest(QString codescript)
{
    std::unique_ptr<Codegenerator::CPlusPlusCodegenerator>generator(new Codegenerator::CPlusPlusCodegenerator());
    generate(generator.get(),codescript);
/*    std::unique_ptr<NParser::ParserImpl> parser(new NParser::ParserImpl());
    QString keywordPath = "..\\Files\\Keywords\\myFirstKeywords.txt";
    QString rulesPath = "..\\Files\\Rules\\";
    std::vector<QString> keywords = parser->doParseForVec(keywordPath);
    std::vector<QString> script = parser->doParseForVec(codescript);
    std::map<QString,QString> rules = parser->doParseForMap(rulesPath);
    std::unique_ptr<Codegenerator::CPlusPlusCodegenerator>generator(new Codegenerator::CPlusPlusCodegenerator());
    generator->generate(script,rules,keywords);*/
    std::list<QString>retValue =  generator->getHeaderListData();
    return retValue;
}


void TestUtilities::generate(Codegenerator::CPlusPlusCodegenerator* generator,QString codescript)
{
    std::unique_ptr<NParser::ParserImpl> parser(new NParser::ParserImpl());
    QString keywordPath = "..\\Files\\Keywords\\myFirstKeywords.txt";
    QString rulesPath = "..\\Files\\Rules\\";
    std::vector<QString> keywords = parser->doParseForVec(keywordPath);
    std::vector<QString> script = parser->doParseForVec(codescript);
    std::map<QString,QString> rules = parser->doParseForMap(rulesPath);
    generator->generate(script,rules,keywords);
}
