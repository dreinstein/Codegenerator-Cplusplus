#ifndef PARSERIMPLEMENTATION_H
#define PARSERIMPLEMENTATION_H

#include <vector>
#include <QString>
#include <map>

#include "Base/BaseParserImplementation.h"

namespace NParser
{

class ParserImplText:public BaseParserImpl
{
public:
    ParserImplText(){;}
    virtual ~ParserImplText(){;}
    std::vector<QString> doParseForVec(const QString) override final;
    std::map<QString,QString> doParseForMap(const QString)const override final;
};

}
#endif // PARSERIMPLEMENTATION_H
