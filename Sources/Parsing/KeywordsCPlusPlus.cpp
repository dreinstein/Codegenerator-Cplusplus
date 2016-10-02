

///////////////////////////////////////////////////////////
//  KeywordsCPlusPlus.cpp
//  Implementation of the Class KeywordsCPlusPlus
//  Created on:      10-Nov-2015 20:34:05
//  Original author: udo_2
///////////////////////////////////////////////////////////


#include <QString>
#include "KeywordsCPlusPlus.h"
#include "Utilities.h"
#include "GeneratorCPlusPlus.h"
#include "ParserimplementationText.h"
#include "Base/BaseGenerator.h"
#include "../Errorhandling/Exceptionhandling.h"
#include "Base/BaseParserImplementation.h"
#include "iostream"

namespace NParser
{


using namespace std;
using namespace NGenerator;
#include "memory"


void  KeywordsCPlusPlus::registerObservers(NGenerator::BaseGenerator *observer)
{
    id = General::ParserId::Id::Keyword;
    parserObservers.push_back(&*observer);
}


void KeywordsCPlusPlus::Parse(const QString str)
{
    std::unique_ptr<ParserImplText> parser (new ParserImplText());
    try
    {
        vecValues = parser->doParseForVec(str);
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


void KeywordsCPlusPlus::giveData() const
{
   for(unsigned int i=0; i < parserObservers.size(); i++)
   {
       parserObservers[i]->receiveData(vecValues,id);
   }
}

}









