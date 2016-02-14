#ifndef PARSERIMPLEMENTATION_H
#define PARSERIMPLEMENTATION_H

#include <vector>
#include <QString>
#include <map>

#include "Base/BaseParserImplementation.h"

namespace NParser
{

class ParserImpl:public BaseParserImpl
{
public:
    ParserImpl();
    virtual ~ParserImpl();
    std::vector<QString> doParseForVec(const QString)const override final;
    std::map<QString,QString> doParseForMap(const QString)const override final;
};

}
#endif // PARSERIMPLEMENTATION_H
