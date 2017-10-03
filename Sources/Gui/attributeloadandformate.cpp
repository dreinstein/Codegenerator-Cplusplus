#include "attributeloadandformate.h"
#include "Parsing/parserimplementationxml.h"



AttributeLoadAndFormate::AttributeLoadAndFormate()
{
    //elements =  std::unique_ptr<Codegenerator::AttributeElements>(new Codegenerator::AttributeElements());
}

QString AttributeLoadAndFormate::getFormatedString()
{
    QString str;
    str = "";
    return str;

}

std::vector<std::unique_ptr<Codegenerator::AttributeElements>> AttributeLoadAndFormate::loadDataSet(QString path)
{
    std::unique_ptr<BaseParserImpl> parser(new NParser::ParserImplXML());
    std::vector<QString> script = parser->doParseForVec(path);
    QString v="";
    int index = 0;
    int vecIndex = 0;
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


