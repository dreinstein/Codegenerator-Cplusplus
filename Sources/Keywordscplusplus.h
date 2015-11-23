#ifndef KEYWORDCPLUSPLUS
#define KEYWORDCPLUSPLUS

#include "Parser.h"
#include <string>
#include <vector>

#define KEYFILE "Keywords"
#define KEYPATH "..\\Keywords\\Keywords.txt"


class KeywordsCPlusPlus:public Parser{
public:
    virtual ~KeywordsCPlusPlus(){};
    void Parse();
    void GetType();
    void GetDatas();

private:
    std::vector<std::string> values;
    const std::string keyfile = "Keywords";
    const std::string keypath = "..\\Keywords\\Keywords";
};

#endif // KEYWORDCPLUSPLUS
