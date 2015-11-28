///////////////////////////////////////////////////////////
//  ParserFassade.cpp
//  Implementation of the Class ParserFassade
//  Created on:      01-Nov-2015 20:03:25
//  Original author: udo_2
///////////////////////////////////////////////////////////

#include <memory>
#include <thread>
#include <mutex>
#include <QtGlobal>

#include "ParserFassade.h"
#include "Utilities.h"
#include "KeywordsCPlusPlus.h"
#include "Parser.h"


using namespace General;

std::mutex mtx;




ParserFassade::ParserFassade(General::Languages::Parserlanguage lang){
    language = lang;
    keyParser = new KeywordsCPlusPlus();
    keyParser->registerObservers(this);
}


ParserFassade::~ParserFassade(){

}


 void ParserFassade::ParseKeyword(){
     Q_ASSERT(keyParser);
     keyParser->Parse();
 /*    while(1)
     {
        Sleep(100);
        mtx.lock();
        if(keywordIdNofificated)
        {
            keyParser->GiveData();
            break;

        }
         mtx.unlock();
     }*/
}


 void ParserFassade::notify(int id)
 {
     // lock data
   /*  mtx.lock();
     switch(id)
     {
     case keywordId:
         keywordIdNotificated = true;
         break;

     }
     mtx.unlock();*/
 }


void ParserFassade::receiveData(std::vector<std::string> strv,int parserId)
{
  /*  switch(parserId)
    {
        case ParserId::Id::Keyword:
            keywordRules = strv;
            // signal to the logic interface
            break;
    }*/
}






