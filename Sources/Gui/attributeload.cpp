#include "attributeload.h"
#include "Parsing/parserimplementationxml.h"



AttributeLoad::AttributeLoad()
{
    //elements =  std::unique_ptr<Codegenerator::AttributeElements>(new Codegenerator::AttributeElements());
}

AttributeLoad::~AttributeLoad()
{
}


std::vector<std::unique_ptr<Codegenerator::AttributeElements>> AttributeLoad::loadDataSet(QString path)
{
    std::unique_ptr<BaseParserImpl> parser(new NParser::ParserImplXML());
    //std::vector<QString> script = parser->doParseForVec(path);
    auto script = parser->doParseForVec(path);
    QString v="";
    auto index = 0;
    auto vecIndex = 0;
    for(auto iterator = script.begin();iterator != script.end();++iterator,++index)
    {
        v = General::ExtractString::extractFirst(script[index]);
        if(v == "attribute")
        {
            elementVec.push_back(std::unique_ptr<Codegenerator::AttributeElements>(new Codegenerator::AttributeElements()));
            elementVec[vecIndex].get()->resetData();
            elementVec[vecIndex].get()->setElements(script[index]);
            vecIndex++;
        }
    }
    return std::move(elementVec);
}


