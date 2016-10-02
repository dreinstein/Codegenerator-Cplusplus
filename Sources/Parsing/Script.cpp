#include "Script.h"

#include <QString>
#include "RulesCPlusPlus.h"
#include "Utilities.h"
#include "GeneratorCPlusPlus.h"
#include "parserimplementationxml.h"
#include "Base/BaseParserImplementation.h"

namespace NParser
{


using namespace std;


void  Script::registerObservers(BaseGenerator *observer)
{
    id = General::ParserId::Id::Script;
    parserObservers.push_back(&*observer);
}

void Script::Parse(const QString str)
{
    std::unique_ptr<ParserImplXML> parser (new ParserImplXML());
    vecValues = parser->doParseForVec(str);
    for(unsigned int i=0; i < parserObservers.size(); i++){
        parserObservers[i]->notifyDatasGenerated(id);
    }
}


void Script::giveData() const{
    for(unsigned int i=0; i < parserObservers.size(); i++)
    {
        parserObservers[i]->receiveData(vecValues,id);
    }
}

}

