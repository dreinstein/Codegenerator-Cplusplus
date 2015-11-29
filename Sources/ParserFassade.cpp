///////////////////////////////////////////////////////////
//  ParserFassade.cpp
//  Implementation of the Class ParserFassade
//  Created on:      01-Nov-2015 20:03:25
//  Original author: udo_2
///////////////////////////////////////////////////////////

#include <memory>

#include <QtGlobal>

#include "ParserFassade.h"
#include "Utilities.h"
#include "KeywordsCPlusPlus.h"
#include "GeneratorCPlusPlus.h"
#include "Parser.h"


using namespace General;






ParserFassade::ParserFassade(BaseGenerator* generator,General::Languages::Parserlanguage lang){
    language = lang;
    keyParser = new KeywordsCPlusPlus();
    keyParser->registerObservers(generator);
}


ParserFassade::~ParserFassade(){

}


void ParserFassade::ParseKeyword(){
     Q_ASSERT(keyParser);
     keyParser->Parse();
}

void ParserFassade::giveKeywordData(){
     Q_ASSERT(keyParser);
     keyParser->giveData();
}


// void ParserFassade::notify(int id)
 //{
     // lock data
   /*  mtx.lock();
     switch(id)
     {
     case keywordId:
         keywordIdNotificated = true;
         break;

     }
     mtx.unlock();*/
// }


/*void ParserFassade::receiveData(std::vector<std::string> strv,int parserId)
{
  /*  switch(parserId)
    {
        case ParserId::Id::Keyword:
            keywordRules = strv;
            // signal to the logic interface
            break;
    }*/
//}*/






