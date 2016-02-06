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
    std::vector<QString> doParseForVec(QString);
    std::map<QString,QString> doParseForMap(QString);
};

}
#endif // PARSERIMPLEMENTATION_H
