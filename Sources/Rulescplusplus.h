#ifndef RULESCPLUSPLUS_H
#define RULESCPLUSPLUS_H


#include <string>
#include <vector>

#include "Parser.h"
#include "Utilities.h"
#include "BaseGenerator.h"



using namespace Logic;

class RulesCPlusPlus:public Parser{
public:
    virtual ~RulesCPlusPlus(){;}
    void Parse();
    void giveData();
    General::Types::DataTypes getDataType() {return General::Types::DataTypes::Vector;}
    void registerObservers(BaseGenerator* observer);
private:
    std::string RULESPATH = "..\\Rules\\RulesC++.txt";


};


#endif // RULESCPLUSPLUS_H
