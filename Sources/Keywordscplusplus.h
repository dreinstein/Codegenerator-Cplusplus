#ifndef KEYWORDCPLUSPLUS
#define KEYWORDCPLUSPLUS

#include "Parser.h"
#include <string>


class KeywordsCPlusPlus:Parser{
public:
    bool Parse();
    std::vector<std::string> Read();
    void Write();
};


#endif // KEYWORDCPLUSPLUS
