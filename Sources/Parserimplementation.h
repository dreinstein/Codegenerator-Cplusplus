#ifndef PARSERIMPLEMENTATION_H
#define PARSERIMPLEMENTATION_H

#include <vector>
#include <string>
#include "BaseParserImplementation.h"
//namespace NParser
//{

class ParserImpl:public BaseParserImpl
{
public:
    ParserImpl();
    virtual ~ParserImpl();
    std::vector<std::string> doParse(std::string);
};

//}
#endif // PARSERIMPLEMENTATION_H
