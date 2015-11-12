///////////////////////////////////////////////////////////
//  RulesC++.cpp
//  Implementation of the Class RulesCPlusPlus
//  Created on:      01-Nov-2015 19:25:21
//  Original author: Udo
///////////////////////////////////////////////////////////
namespace Parsing
{
	
#include "RulesC++.h"


RulesCPlusPlus::RulesCPlusPlus(){

}



RulesCPlusPlus::~RulesCPlusPlus(){

}





hash_map<string,vector<char>> RulesCPlusPlus::getARules(){

	return ARules;
}


void RulesCPlusPlus::setARules(hash_map<string,vector<char>> newVal){

	ARules = newVal;
}

}


hash_map RulesCPlusPlus::Get(){

	return  NULL;
}


void RulesCPlusPlus::Read(){

}


bool RulesCPlusPlus::Parse(){

	return false;
}