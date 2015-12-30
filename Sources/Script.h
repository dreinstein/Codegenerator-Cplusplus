#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>
#include <vector>

#include "Parser.h"
#include "Utilities.h"
#include "Base/BaseGenerator.h"

using namespace NGenerator;

namespace NParser
{

class Script:public Parser
{
public:
    virtual ~Script(){;}
    void Parse(const std::string str);
    void giveData();
    General::Types::DataTypes getDataType() {return General::Types::DataTypes::Vector;}
    void registerObservers(BaseGenerator* observer);
};
}
#endif // SCRIPT_H
