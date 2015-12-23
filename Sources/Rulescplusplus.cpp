#include "Rulescplusplus.h"


#include <string>
#include "RulesCPlusPlus.h"
#include "Utilities.h"
#include "GeneratorCPlusPlus.h"
#include "Parserimplementation.h"
#include "BaseParserImplementation.h"


namespace NParser
{

using namespace std;


void  RulesCPlusPlus::registerObservers(BaseGenerator *observer)
{
    id = General::ParserId::Id::Rules;
    parserObservers.push_back(&*observer);
}

void RulesCPlusPlus::Parse(){
    BaseParserImpl* parser = new ParserImpl();
    values = parser->doParse(RULESPATH);
    for(unsigned int i=0; i < parserObservers.size(); i++){
        parserObservers[i]->notify(id);
    }
    delete parser;
}


void RulesCPlusPlus::giveData(){
    for(unsigned int i=0; i < parserObservers.size(); i++)
    {
        parserObservers[i]->receiveData(values,id);
    }
}


}


