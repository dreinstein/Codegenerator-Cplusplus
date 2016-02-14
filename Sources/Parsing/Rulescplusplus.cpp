#include "Rulescplusplus.h"


#include <QString>
#include "RulesCPlusPlus.h"
#include "Utilities.h"
#include "GeneratorCPlusPlus.h"
#include "Parserimplementation.h"
#include "Base/BaseParserImplementation.h"


namespace NParser
{

using namespace std;


void  RulesCPlusPlus::registerObservers(BaseGenerator *observer)
{
    id = General::ParserId::Id::Rules;
    parserObservers.push_back(&*observer);
}

void RulesCPlusPlus::Parse(const QString str)
{
    BaseParserImpl* parser = new ParserImpl();
    mapValues = parser->doParseForMap(str);
    for(unsigned int i=0; i < parserObservers.size(); i++){
        parserObservers[i]->notify(id);
    }
    delete parser;
}


void RulesCPlusPlus::giveData() const {
    for(unsigned int i=0; i < parserObservers.size(); i++)
    {
        parserObservers[i]->receiveData(mapValues,id);
    }
}


}


