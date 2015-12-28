#ifndef PARSERIMPLEMENTATION_H
#define PARSERIMPLEMENTATION_H

#include <vector>
#include <string>

#include "parserimplementationbase.h"
//namespace NParser
//{

class ParserImpl:ParserImplementationBase
{
public:
    ParserImpl();
    virtual ~ParserImpl();
    std::vector<std::string> doParse(std::string);
};

//}
#endif // PARSERIMPLEMENTATION_H
