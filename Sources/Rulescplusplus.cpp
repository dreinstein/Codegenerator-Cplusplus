#include "Rulescplusplus.h"


#include <string>
#include "RulesCPlusPlus.h"
#include "Utilities.h"
#include "GeneratorCPlusPlus.h"
#include "Parserimplementation.h"

namespace Parser
{

using namespace std;


void  RulesCPlusPlus::registerObservers(BaseGenerator *observer)
{
    id = General::ParserId::Id::Rules;
    parserObservers.push_back(&*observer);
}

void RulesCPlusPlus::Parse(){
    ParserImpl* parser = new ParserImpl();
    values = parser->doParse(RULESPATH);
    for(int i=0; i < parserObservers.size(); i++){
        parserObservers[i]->notify(id);
    }
    delete parser;
}


void RulesCPlusPlus::giveData(){
    for(int i=0; i < parserObservers.size(); i++)
    {
        parserObservers[i]->receiveData(values,id);
    }
}

}
