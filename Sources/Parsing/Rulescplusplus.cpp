#include "Rulescplusplus.h"


#include <QString>
#include "RulesCPlusPlus.h"
#include "Utilities.h"
#include "GeneratorCPlusPlus.h"
#include "ParserimplementationText.h"
#include "Base/BaseParserImplementation.h"
#include "../Errorhandling/Exceptionhandling.h"
#include "Base/BaseParserImplementation.h"
#include "iostream"


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
    std::unique_ptr<BaseParserImpl> parser (new ParserImplText());
    try
    {
        mapValues = parser->doParseForMap(str);
    }
    catch(Errorhandling::Exceptionhandling &error)
    {
        // @todo:: log
        std::cout << error.whatDescription();
    }
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


