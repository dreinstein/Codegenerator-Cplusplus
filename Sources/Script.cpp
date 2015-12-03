#include "Script.h"

#include <string>
#include "RulesCPlusPlus.h"
#include "Utilities.h"
#include "GeneratorCPlusPlus.h"
#include "Parserimplementation.h"

//namespace NParser
//{


using namespace std;


void  Script::registerObservers(BaseGenerator *observer)
{
    id = General::ParserId::Id::Script;
    parserObservers.push_back(&*observer);
}

void Script::Parse(){
    ParserImpl* parser = new ParserImpl();
    values = parser->doParse(SCRIPTPATH);
    for(unsigned int i=0; i < parserObservers.size(); i++){
        parserObservers[i]->notify(id);
    }
    delete parser;
}


void Script::giveData(){
    for(unsigned int i=0; i < parserObservers.size(); i++)
    {
        parserObservers[i]->receiveData(values,id);
    }
}

//}

