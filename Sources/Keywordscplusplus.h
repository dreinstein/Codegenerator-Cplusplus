#ifndef KEYWORDCPLUSPLUS
#define KEYWORDCPLUSPLUS

#include "Parser.h"
#include "ParsingVectordata.h"
#include "Utilities.h"
#include <string>
#include <vector>

#define KEYFILE "Keywords"
#define KEYPATH "..\\Keywords\\Keywords.txt"


class KeywordsCPlusPlus:public Parser{
public:
    virtual ~KeywordsCPlusPlus(){;}
    void Parse();
    std::vector<std::string> getData();
    General::Types::DataTypes getDataType() {return General::Types::DataTypes::Vector;}

private:
    std::vector<std::string> values;
    const std::string keyfile = "Keywords";
    const std::string keypath = "..\\Keywords\\Keywords";
};

#endif // KEYWORDCPLUSPLUS
