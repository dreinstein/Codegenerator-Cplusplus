

///////////////////////////////////////////////////////////
//  KeywordsCPlusPlus.cpp
//  Implementation of the Class KeywordsCPlusPlus
//  Created on:      10-Nov-2015 20:34:05
//  Original author: udo_2
///////////////////////////////////////////////////////////


#include <string>
#include "KeywordsCPlusPlus.h"
#include "Utilities.h"
#include "GeneratorCPlusPlus.h"
#include "Parserimplementation.h"
#include "Base/BaseGenerator.h"
#include "Base/BaseParserImplementation.h"

namespace NParser
{


using namespace std;
using namespace NGenerator;


void  KeywordsCPlusPlus::registerObservers(NGenerator::BaseGenerator *observer)
{
    id = General::ParserId::Id::Keyword;
    parserObservers.push_back(&*observer);
}


void KeywordsCPlusPlus::Parse(const std::string str)
{
    BaseParserImpl* parser = new ParserImpl();
    values = parser->doParse(str);
    for(unsigned int i=0; i < parserObservers.size(); i++){
        parserObservers[i]->notify(id);
    }
    delete parser;
}


void KeywordsCPlusPlus::giveData(){
   for(unsigned int i=0; i < parserObservers.size(); i++)
   {
       parserObservers[i]->receiveData(values,id);
   }
}

}









