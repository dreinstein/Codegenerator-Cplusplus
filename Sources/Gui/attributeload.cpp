#include "attributeload.h"
#include "Parsing/parserimplementationxml.h"
#include "../Codegen/Codegeneratorconstants.h"




 

 std::vector<std::unique_ptr<Codegenerator::AttributeElements>> AttributeLoad::loadDatasFromFile(QString path)
{
    std::vector<std::unique_ptr<Codegenerator::AttributeElements>>  vecElements;
    std::unique_ptr<BaseParserImpl> parser(new NParser::ParserImplXML());
    auto script = parser->doParseForVec(path);

    QString v="";
    auto index = 0;
    auto vecIndex = 0;
    for(auto iterator = script.begin();iterator != script.end();++iterator,++index)
    {
        v = General::ExtractString::extractFirst(script[index]);
        if(v == "attribute")
        {
            vecElements.push_back(std::unique_ptr<Codegenerator::AttributeElements>(new Codegenerator::AttributeElements()));
            vecElements[vecIndex].get()->resetData();
            vecElements[vecIndex].get()->setElements(script[index]);
            vecIndex++;
        }
    }
    return std::move(vecElements);
}


