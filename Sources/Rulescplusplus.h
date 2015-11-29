#ifndef RULESCPLUSPLUS_H
#define RULESCPLUSPLUS_H


#include <string>
#include <vector>

#include "Parser.h"
#include "Utilities.h"


#define RULESFILE "Rules"
#define RULESPATH "..\\Rules\\Rules.txt"

class BaseGenerator;

class RulesCPlusPlus:public Parser{
public:
    virtual ~RulesCPlusPlus(){;}
    void Parse();
    void giveData();
    General::Types::DataTypes getDataType() {return General::Types::DataTypes::Vector;}
    void registerObservers(BaseGenerator* observer);

private:
    std::vector<std::string> values;
    int id;
 };


#endif // RULESCPLUSPLUS_H
