#include "Rulescplusplus.h"


#include <QString>
#include "RulesCPlusPlus.h"
#include "Utilities.h"
#include "GeneratorCPlusPlus.h"
#include "ParserimplementationText.h"
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
    std::unique_ptr<ParserImplText> parser (new ParserImplText());
    mapValues = parser->doParseForMap(str);
    for(unsigned int i=0; i < parserObservers.size(); i++){
        parserObservers[i]->notifyDatasGenerated(id);
    }
}


void RulesCPlusPlus::giveData() const {
    for(unsigned int i=0; i < parserObservers.size(); i++)
    {
        parserObservers[i]->receiveData(mapValues,id);
    }
}


}


