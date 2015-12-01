#ifndef KEYWORDCPLUSPLUS
#define KEYWORDCPLUSPLUS

#include "Parser.h"
#include "BaseGenerator.h"
#include "Utilities.h"
#include <string>
#include <vector>



using namespace Logic;

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
