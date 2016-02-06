#ifndef RULESCPLUSPLUS_H
#define RULESCPLUSPLUS_H


#include <QString>
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
    void Parse(const QString str);
    void giveData();
    General::Types::DataTypes getDataType() {return General::Types::DataTypes::Vector;}
    void registerObservers(BaseGenerator* observer);
};

}

#endif // RULESCPLUSPLUS_H
