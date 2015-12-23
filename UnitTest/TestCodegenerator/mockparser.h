



#ifndef MOCKPARSER_H
#define MOCKPARSER_H

#include<string>
#include<vector>
#include "gmock/gmock.h"
#include "BaseParserImplementation.h"


class MockParser:public BaseParserImpl
{
public:
    MOCK_METHOD1(doParse, std::vector<std::string>(std::string));
};

#endif // MOCKPARSER_H
