

#ifndef KEYWORDCPLUSPLUS
#define KEYWORDCPLUSPLUS

#include "Utilities.h"
#include <string>
#include <vector>
#include "Base/BaseGenerator.h"
#include "Parser.h"

using namespace NGenerator;

namespace NParser
{



class KeywordsCPlusPlus:public Parser{
public:
    virtual ~KeywordsCPlusPlus(){;}
    void Parse(const std::string std);
    void giveData();
    General::Types::DataTypes getDataType() {return General::Types::DataTypes::Vector;}
    void registerObservers(BaseGenerator* observer);
};
}

#endif // KEYWORDCPLUSPLUS


