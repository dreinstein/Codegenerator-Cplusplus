#include "functionload.h"
#include "Parsing/parserimplementationxml.h"
#include "../Codegen/Codegeneratorconstants.h"






 std::vector<std::vector<std::unique_ptr<Codegenerator::AttributeElements>>> FunctionLoad::loadDatasFromFile(QString path)
{
    std::vector<std::vector<std::unique_ptr<Codegenerator::AttributeElements>>> funcElements;
    std::unique_ptr<BaseParserImpl> parser(new NParser::ParserImplXML());
    auto script = parser->doParseForVec(path);
    QString v="";
    auto index = 0;
    auto vecIndex = 0;

    for(auto iterator = script.begin();iterator != script.end();++iterator,++index)
    {
        v = General::ExtractString::extractFirst(script[index]);
     /*   if(v == "attribute")
        {
            elementVec.push_back(std::unique_ptr<Codegenerator::AttributeElements>(new Codegenerator::AttributeElements()));
            elementVec[vecIndex].get()->resetData();
            elementVec[vecIndex].get()->setElements(script[index]);
            vecIndex++;
        }*/
    }
    return std::move(funcElements);
}


