#ifndef KEYWORDCPLUSPLUS
#define KEYWORDCPLUSPLUS

#include "Parser.h"
#include <string>


class KeywordsCPlusPlus:public Parser{
public:
    std::vector<std::string> Parse();
   // std::vector<std::string> Read();
    void Write();
};


#endif // KEYWORDCPLUSPLUS
