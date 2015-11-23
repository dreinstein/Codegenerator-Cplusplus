///////////////////////////////////////////////////////////
//  ParserFassade.cpp
//  Implementation of the Class ParserFassade
//  Created on:      01-Nov-2015 20:03:25
//  Original author: udo_2
///////////////////////////////////////////////////////////

#include <memory>

#include "ParserFassade.h"
#include "Utilities.h"
#include "KeywordsCPlusPlus.h"
#include "Parser.h"


using namespace General;


ParserFassade::ParserFassade(General::Languages::Parserlanguage lang){
    language = lang;
}


ParserFassade::~ParserFassade(){

}


 std::vector<std::string> ParserFassade::ParseKeyword(){
     std::vector<std::string> strv;
     Parser* keyParser = new KeywordsCPlusPlus();
     keyParser->Parse();
    // keyParser->
   //  keyParser->
     delete keyParser;
     return  strv;
}


