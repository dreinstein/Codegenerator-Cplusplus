///////////////////////////////////////////////////////////
//  ParserFassade.cpp
//  Implementation of the Class ParserFassade
//  Created on:      01-Nov-2015 20:03:25
//  Original author: udo_2
///////////////////////////////////////////////////////////


#include "ParserFassade.h"
#include "Utilities.h"

using namespace General;


ParserFassade::ParserFassade(General::Languages::Parserlanguage lang){
    language = lang;
}


ParserFassade::~ParserFassade(){

}


void ParserFassade::ParseKeyword(){

}


void ParserFassade::ParseRules(){

}


int ParserFassade::ReadKeywords(){

	return 0;
}


int ParserFassade::ReadRules(){

	return 0;
}


std::vector<std::string> ParserFassade::GetKeywords(){

    std::vector<std::string> strv;
    return  strv;
}


std::vector<std::string> ParserFassade::GetRules(){

    std::vector<std::string> strv;
    return  strv;
}


std::vector<std::string> ParserFassade::ReadScript(){

    std::vector<std::string> strv;
    return  strv;
}
