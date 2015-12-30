#ifndef RULESCPLUSPLUS_H
#define RULESCPLUSPLUS_H


#include <string>
#include <vector>

#include "Parser.h"
#include "Utilities.h"
#include "Base/BaseGenerator.h"


namespace NParser
{

using namespace NGenerator;


class RulesCPlusPlus:public Parser{
public:
    virtual ~RulesCPlusPlus(){;}
    void Parse(const std::string str);
    void giveData();
    General::Types::DataTypes getDataType() {return General::Types::DataTypes::Vector;}
    void registerObservers(BaseGenerator* observer);
};

}

#endif // RULESCPLUSPLUS_H
