///////////////////////////////////////////////////////////
//  ParserFassade.cpp
//  Implementation of the Class ParserFassade
//  Created on:      01-Nov-2015 20:03:25
//  Original author: udo_2
///////////////////////////////////////////////////////////

using namespace General;
#include "ParserFassade.h"
#include "Utilities.h"




ParserFassade::ParserFassade(int lang){
    language = lang;
}


ParserFassade::~ParserFassade(){

}


void ParserFassade::ParseKeyword(){

}


void ParserFassade::ParseRules(Language prm1){

}


int ParserFassade::ReadKeywords(){

	return 0;
}


int ParserFassade::ReadRules(){

	return 0;
}


hash_map ParserFassade::GetKeywords(){

	return  NULL;
}


hash_map ParserFassade::GetRules(){

	return  NULL;
}


hash_map ParserFassade::ReadScript(){

	return  NULL;
}
