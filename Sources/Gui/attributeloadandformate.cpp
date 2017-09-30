#include "attributeloadandformate.h"
#include "Parsing/parserimplementationxml.h"



AttributeLoadAndFormate::AttributeLoadAndFormate()
{
    elements =  std::unique_ptr<Codegenerator::AttributeElements>(new Codegenerator::AttributeElements());
}

QString AttributeLoadAndFormate::getFormatedString()
{
    QString str;
    str = "";
    return str;

}

void AttributeLoadAndFormate::loadDataSet(QString path)
{
    std::unique_ptr<BaseParserImpl> parser(new NParser::ParserImplXML());
    std::vector<QString> script = parser->doParseForVec(path);
    QString v="";
    v = General::ExtractString::extractFirst(script[attributePos]);
    if(v == "attribute")
    {
        elements.get()->setElements(script[attributePos]);
    }
}

std::unique_ptr<Codegenerator::AttributeElements> AttributeLoadAndFormate::getElement()
{
    return std::move(elements);
}

