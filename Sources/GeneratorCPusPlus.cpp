
#include <QtGlobal>

#include "Parser.h"
#include "BaseEvaluator.h"
#include "Evaluator.h"
#include "BaseGenerator.h"
#include "GeneratorCPlusPlus.h"
#include "ParserFassade.h"
#include "Utilities.h"




using namespace NParser;

namespace NGenerator
{


GeneratorCPlusPlus::GeneratorCPlusPlus()
{
    pFassade = new ParserFassade(this,General::Languages::CPLUSPLUS);
  //  Evaluator eval;
    pEvaluator = new ScriptEvaluator();
}


GeneratorCPlusPlus::~GeneratorCPlusPlus()
{
    if(pEvaluator)
    {
         delete pEvaluator;
    }
    if(pFassade)
    {
        delete pFassade;
    }
}

void GeneratorCPlusPlus::generate()
{
    Q_ASSERT(pFassade);
    keywordsReceived = false;
    rulesReceived = false;
    rulesReceived = false;
    pFassade->ParseKeyword();
    pFassade->ParseRules();
    pFassade->ParseScript();
}

void GeneratorCPlusPlus::notify(int parserId)
{
    // lock data
    switch(parserId)
    {
        case General::ParserId::Keyword:
            pFassade->giveKeywordData();
        break;
    }
}

void GeneratorCPlusPlus::allDatasReceived()
{
    pEvaluator->evaluate(keywords,script);
}

bool GeneratorCPlusPlus::areAllDatasReceived()
{
    if(keywordsReceived && rulesReceived && scriptReceived )
    {
        keywordsReceived = false;
        rulesReceived = false;
        scriptReceived = false;
        return true;
    }
    return false;
}




void GeneratorCPlusPlus::receiveData(std::vector<std::string> strv,int parserId)
{
    switch(parserId)
    {
        case General::ParserId::Id::Keyword:
            keywords = strv;
            keywordsReceived = true;
            if(areAllDatasReceived())
            {
                allDatasReceived();
            }
            break;
        case General::ParserId::Id::Rules:
            rules = strv;
            rulesReceived = true;
            if(areAllDatasReceived())
            {
                allDatasReceived();
            }
            break;
        case General::ParserId::Id::Script:
            script = strv;
            scriptReceived = true;
            if(areAllDatasReceived())
            {
                allDatasReceived();
            }
            // this is the last, assume all is received
            break;
        default:
            Q_ASSERT(false);
    }
}

}



