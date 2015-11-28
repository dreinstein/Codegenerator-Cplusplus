///////////////////////////////////////////////////////////
//  KeywordsCPlusPlus.cpp
//  Implementation of the Class KeywordsCPlusPlus
//  Created on:      10-Nov-2015 20:34:05
//  Original author: udo_2
///////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "KeywordsCPlusPlus.h"
#include "Utilities.h"


using namespace std;


void  KeywordsCPlusPlus::registerObservers(ParserFassade *observer)
{
    id = General::ParserId::Id::Keyword;
    parserObservers.push_back(&*observer);
}

void KeywordsCPlusPlus::Parse(){
    ifstream  fin(KEYPATH);
    string row;
    while(getline(fin,row))
    {
        values.push_back(row);
    }
    fin.close();
    for(int i=0; i < parserObservers.size(); i++){
    parserObservers[i]->notify(id);
    }
}


void KeywordsCPlusPlus::giveData(){
    for(int i=0; i < parserObservers.size(); i++){
       parserObservers[i]->receiveData(values,id);
    }
}









