
#include <QtGlobal>
#include <mutex>

#include "Parser.h"
#include "BaseGenerator.h"
#include "GeneratorCPlusPlus.h"
#include "ParserFassade.h"
#include "Utilities.h"


using namespace NParser;


namespace NGenerator
{


std::mutex mtx;



GeneratorCPlusPlus::GeneratorCPlusPlus()
{
    pFassade = new ParserFassade(this,General::Languages::CPLUSPLUS);
}


GeneratorCPlusPlus::~GeneratorCPlusPlus()
{
    if(pFassade)
    {
        delete pFassade;
    }
}

void GeneratorCPlusPlus::generate()
{
    Q_ASSERT(pFassade);
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

void GeneratorCPlusPlus::receiveData(std::vector<std::string> strv,int parserId)
{
    switch(parserId)
    {
        case General::ParserId::Id::Keyword:
            keywords = strv;
            break;
        case General::ParserId::Id::Rules:
            rules = strv;
            break;
        case General::ParserId::Id::Script:
            script = strv;
            break;
        default:
            Q_ASSERT(false);
    }
}

}



