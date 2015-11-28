#ifndef KEYWORDCPLUSPLUS
#define KEYWORDCPLUSPLUS

#include "Parser.h"
#include "ParsingVectordata.h"
#include "Utilities.h"
#include <string>
#include <vector>

#define KEYFILE "Keywords"
#define KEYPATH "..\\Keywords\\Keywords.txt"

class BaseGenerator;

class KeywordsCPlusPlus:public Parser{
public:
    virtual ~KeywordsCPlusPlus(){;}
    void Parse();
    void giveData();
    General::Types::DataTypes getDataType() {return General::Types::DataTypes::Vector;}
    void registerObservers(BaseGenerator* observer);

private:
    std::vector<std::string> values;
    int id;
    const std::string keyfile = "Keywords";
    const std::string keypath = "..\\Keywords\\Keywords";
};

#endif // KEYWORDCPLUSPLUS
