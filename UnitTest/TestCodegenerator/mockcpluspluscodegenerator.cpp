#include "mockcpluspluscodegenerator.h"
#include "Codegeneratorfassade.h"
#include <QString>
#include "Utilities.h"
#include "Parser.h"
#include "Base/BaseGenerator.h"
#include "Base/BaseEvaluator.h"
#include "Evaluator.h"
#include "GeneratorCPlusPlus.h"
#include "Codegen/CPluspluscodegenerator.h"
#include "ParserFassade.h"
#include "Codegeneratorfassade.h"

MockCPlusPlusCodegenerator::MockCPlusPlusCodegenerator()
{
    pCodegeneratorFassade = new CodegeneratorFassade(this,Languages::CPLUSPLUS);
    pParserFassade = new ParserFassade(this,Languages::CPLUSPLUS);
}


MockCPlusPlusCodegenerator::~MockCPlusPlusCodegenerator()
{
    if(pParserFassade)
    {
        delete pParserFassade;
    }
    if(pCodegeneratorFassade)
    {
        delete pCodegeneratorFassade;
    }
}

void MockCPlusPlusCodegenerator::generate()
{
    Q_ASSERT(pParserFassade);
    keywordsReceived = false;
    rulesReceived = false;
    rulesReceived = false;
    pathScript = "..\\Files\\Scripts\\myFirstScript.txt";
    QString pathKeywords = "..\\Files\\Keywords\\myFirstKeywords.txt";
    QString pathRules = "..\\Files\\Rules\\";
    pParserFassade->ParseKeyword(pathKeywords);
    pParserFassade->ParseRules(pathRules);
    pParserFassade->ParseScript(pathScript);
}

void MockCPlusPlusCodegenerator::notify(int parserId)
{
    // lock data
    switch(parserId)
    {
        case General::ParserId::Keyword:
            pParserFassade->giveKeywordData();
        break;
        case General::ParserId::Rules:
            pParserFassade->giveRulesData();
            break;
        case General::ParserId::Script:
            pParserFassade->giveScriptData();
            break;
        default:
            Q_ASSERT(false);
    }
}



void MockCPlusPlusCodegenerator::allDatasReceived()
{
    pCodegeneratorFassade->generate(script,keywords,rules);
}


bool MockCPlusPlusCodegenerator::areAllDatasReceived()
{
    if(keywordsReceived && scriptReceived && rulesReceived)
    {
        return true;
    }
    return false;
}


void MockCPlusPlusCodegenerator::receiveData(std::vector<QString> strv,int parserId)
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
            Q_ASSERT(false);
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

void MockCPlusPlusCodegenerator::receiveData(std::map<QString,QString> strv,int parserId)
{
    switch(parserId)
    {
        case General::ParserId::Id::Keyword:
            Q_ASSERT(false);
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
            Q_ASSERT(false);
            break;
        default:
            Q_ASSERT(false);
    }
}







