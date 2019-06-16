



#ifndef MOCKPARSER_H
#define MOCKPARSER_H

#include<QString>
#include<vector>
#include "gmock/gmock.h"
#include "Base/BaseParserImplementation.h"


class MockParser:public BaseParserImpl
{
public:
    MOCK_METHOD1(doParse, std::vector<QString>(QString));
};

#endif // MOCKPARSER_H
