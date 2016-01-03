///////////////////////////////////////////////////////////
//  ParserFassade.cpp
//  Implementation of the Class ParserFassade
//  Created on:      01-Nov-2015 20:03:25
//  Original author: udo_2
///////////////////////////////////////////////////////////


#include <QtGlobal>


#include "Utilities.h"
#include "KeywordsCPlusPlus.h"
#include "Rulescplusplus.h"
#include "Script.h"
#include "GeneratorCPlusPlus.h"
#include "Parser.h"
#include "ParserFassade.h"
#include "Utilities.h"
#include <QString>


using namespace General;


ParserFassade::ParserFassade(BaseGenerator* generator,General::Languages::Parserlanguage lang)
{
    switch (lang)
    {
        case Languages::CPLUSPLUS:
            buildForCPlusPlus(generator);
        break;
        default:
            Q_ASSERT(true);
    }
}


ParserFassade::~ParserFassade()
{
    delete keyParser;
    delete rulesParser;
    delete scriptParser;
}


void ParserFassade::ParseKeyword(QString strKeywords)
{
     Q_ASSERT(keyParser);
     keyParser->Parse(strKeywords);
}

void ParserFassade::ParseRules(QString strRules)
{
     Q_ASSERT(rulesParser);
     rulesParser->Parse(strRules);
}

void ParserFassade::ParseScript(QString strScript)
{
     Q_ASSERT(scriptParser);
     scriptParser->Parse(strScript);
}


void ParserFassade::giveKeywordData()
{
     Q_ASSERT(keyParser);
     keyParser->giveData();
}

void ParserFassade::giveRulesData()
{
     Q_ASSERT(rulesParser);
     rulesParser->giveData();
}


void ParserFassade::giveScriptData()
{
     Q_ASSERT(scriptParser);
     scriptParser->giveData();
}


void ParserFassade::buildForCPlusPlus(BaseGenerator* generator)
{
     keyParser = new KeywordsCPlusPlus();
     keyParser->registerObservers(generator);
     rulesParser = new RulesCPlusPlus();
     rulesParser->registerObservers(generator);
     scriptParser = new Script();
     scriptParser->registerObservers(generator);
}









