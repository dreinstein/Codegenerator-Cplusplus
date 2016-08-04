///////////////////////////////////////////////////////////
//  ParserFassade.cpp
//  Implementation of the Class ParserFassade
//  Created on:      01-Nov-2015 20:03:25
//  Original author: udo_2
///////////////////////////////////////////////////////////


#include <QtGlobal>


#include "Utilities.h"


#include "GeneratorCPlusPlus.h"
#include "Parsing/Parser.h"
#include "ParserFassade.h"
#include "Utilities.h"
#include <QString>


using namespace General;


ParserFassade::ParserFassade(BaseGenerator* generator,General::Languages::Parserlanguage lang)
{
    switch (lang)
    {
        case Languages::Parserlanguage::CPLUSPLUS:
            buildForCPlusPlus(generator);
        break;
        default:
            Q_ASSERT(true);
    }
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
     keyParser =  std::unique_ptr<KeywordsCPlusPlus>(new KeywordsCPlusPlus());
     rulesParser =  std::unique_ptr<RulesCPlusPlus>(new RulesCPlusPlus());
     scriptParser =  std::unique_ptr<Script>(new Script());
     keyParser->registerObservers(generator);
     rulesParser->registerObservers(generator);
     scriptParser->registerObservers(generator);
}









