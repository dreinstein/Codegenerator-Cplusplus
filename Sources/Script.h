#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>
#include <vector>

#include "Parser.h"
#include "Utilities.h"

namespace Parser
{

class Script:public Parser
{
public:
    virtual ~Script(){;}
    void Parse();
    void giveData();
    General::Types::DataTypes getDataType() {return General::Types::DataTypes::Vector;}
    void registerObservers(BaseGenerator* observer);
private:
    std::string SCRIPTPATH = "..\\Scripts\\Script.txt";
};

}

#endif // SCRIPT_H
