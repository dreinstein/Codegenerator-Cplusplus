#include "functionload.h"
#include "Parsing/parserimplementationxml.h"
#include "../Codegen/Codegeneratorconstants.h"






std::vector<std::unique_ptr<Codegenerator::FunctionElements>> FunctionLoad::loadDatasFromFile(QString path)
{
    std::vector<std::unique_ptr<Codegenerator::FunctionElements>>  funcElements;
    std::unique_ptr<BaseParserImpl> parser(new NParser::ParserImplXML());
    auto script = parser->doParseForVec(path);
    QString v="";
    auto index = 0;
    auto vecIndex = 0;

    for(auto iterator = script.begin();iterator != script.end();++iterator,++index)
    {
        v = General::ExtractString::extractFirst(script[index]);
        if(v == "function")
        {
            funcElements.push_back(std::unique_ptr<Codegenerator::FunctionElements>(new Codegenerator::FunctionElements()));
            funcElements[vecIndex].get()->resetData();
            funcElements[vecIndex].get()->setElements(script[index]);
            vecIndex++;
        }
    }
    return std::move(funcElements);
}


