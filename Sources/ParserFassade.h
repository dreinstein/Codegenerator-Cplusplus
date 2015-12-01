///////////////////////////////////////////////////////////
//  ParserFassade.h
//  Implementation of the Class ParserFassade
//  Created on:      01-Nov-2015 20:03:25
//  Original author: udo_2
///////////////////////////////////////////////////////////

#if !defined(EA_BF356F96_D102_426f_A476_1891C7E56F5F__INCLUDED_)
#define EA_BF356F96_D102_426f_A476_1891C7E56F5F__INCLUDED_



#include <Vector>
#include<string>
#include <cstddef>

#include "BaseGenerator.h"
#include "Utilities.h"

class Parser;

using namespace Logic;




class ParserFassade
{

public:	
    ParserFassade(BaseGenerator* generator,General::Languages::Parserlanguage lang);
    ~ParserFassade();
    void ParseKeyword();
    void ParseRules();
    void ParseScript();

//    void receiveData(std::vector<std::string> strv,int parserId);
//    void notify(int id);
    void giveKeywordData();
    void giveScriptData();
    void giveRulesData();

private:
    Parser *keyParser;
    Parser *scriptParser;
    Parser *rulesParser;
    General::Languages::Parserlanguage language;

    ParserFassade(const ParserFassade& f);
    ParserFassade& operator = (const ParserFassade& src);

};
#endif // !defined(EA_BF356F96_D102_426f_A476_1891C7E56F5F__INCLUDED_)
