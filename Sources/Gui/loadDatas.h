#ifndef FUNCTIONLOAD_H
#define FUNCTIONLOAD_H


#include "Codegen/Functionelements.h"
#include <memory>
#include "Parsing/parserimplementationxml.h"
#include "../Codegen/Codegeneratorconstants.h"
#include <qDebug>
#include <QTextStream>




namespace Ui
{
    class AttributeWidget;
}



template<class T>
class DatasLoad
{
public:
    DatasLoad(){;}
    ~DatasLoad(){;}
    std::vector<std::shared_ptr<T>> loadDatasFromFile(QString path);
};


template<class T>
std::vector<std::shared_ptr<T>> DatasLoad<T>::loadDatasFromFile(QString path)
{
    std::vector<std::shared_ptr<T>> element;
   // std::vector<std::unique_ptr<Codegenerator::FunctionElements>>  funcElements;
    std::unique_ptr<BaseParserImpl> parser(new NParser::ParserImplXML());
    auto script = parser->doParseForVec(path);
    QString v="";
    auto index = 0;
    auto vecIndex = 0;
    QTextStream out(stdout);
    for(auto iterator = script.begin();iterator != script.end();++iterator,++index)
    {
        v = General::ExtractString::extractFirst(script[index]);
        if((v == "function") || (v == "attribute") )
        {
            element.push_back(std::unique_ptr<T>(new T));
            element[vecIndex].get()->resetData();
            out << script[index] << endl;
            element[vecIndex].get()->setElements(script[index]);
            vecIndex++;
        }
    }
    return element;
}
#endif
