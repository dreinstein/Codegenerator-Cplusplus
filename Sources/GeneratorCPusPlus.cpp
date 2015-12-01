
#include <QtGlobal>
#include <mutex>

#include "GeneratorCPlusPlus.h"
#include "ParserFassade.h"
#include "Utilities.h"


namespace Logic
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
            // signal to the logic interface
            break;
    }
}

}


