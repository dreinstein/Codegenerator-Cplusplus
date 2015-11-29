#ifndef KEYWORDCPLUSPLUS
#define KEYWORDCPLUSPLUS

#include "Parser.h"
#include "Parser.h"
#include "Utilities.h"
#include <string>
#include <vector>



class BaseGenerator;

class KeywordsCPlusPlus:public Parser{
public:
    virtual ~KeywordsCPlusPlus(){;}
    void Parse();
    void giveData();
    General::Types::DataTypes getDataType() {return General::Types::DataTypes::Vector;}
    void registerObservers(BaseGenerator* observer);
private:
     std::string KEYWORDSPATH = "..\\Keywords\\Keywords.txt";
};

#endif // KEYWORDCPLUSPLUS
