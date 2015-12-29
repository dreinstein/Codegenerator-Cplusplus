///////////////////////////////////////////////////////////
//  ParserFassade.h
//  Implementation of the Class ParserFassade
//  Created on:      01-Nov-2015 20:03:25
//  Original author: udo_2
///////////////////////////////////////////////////////////



#if !defined(EA_BF356F96_D102_426f_A476_1891C7E56F5F__INCLUDED_)
#define EA_BF356F96_D102_426f_A476_1891C7E56F5F__INCLUDED_


#include "Utilities.h"
#include <Vector>
#include <string>
#include <cstddef>
#include "Base/BaseGenerator.h"
#include "Parser.h"

#include "Utilities.h"


using namespace General;
using namespace NGenerator;
using namespace NParser;


//namespace NParser
//{
class ParserFassade
{
public:	

    ParserFassade(BaseGenerator* generator,Languages::Parserlanguage lang);
    ~ParserFassade();

    void ParseKeyword();
    void ParseRules();
    void ParseScript();
    void giveKeywordData();
    void giveScriptData();
    void giveRulesData();

private:
    Parser *keyParser;
    Parser *scriptParser;
    Parser *rulesParser;
    void buildForCPlusPlus(BaseGenerator* generator);
    ParserFassade(const ParserFassade& f);
    ParserFassade& operator = (const ParserFassade& src);

};



//}  // end Namespace

#endif // !defined(EA_BF356F96_D102_426f_A476_1891C7E56F5F__INCLUDED_)
