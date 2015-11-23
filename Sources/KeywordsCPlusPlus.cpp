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


void KeywordsCPlusPlus::Parse(){
    ifstream  fin(KEYPATH);
    string row;
    while(getline(fin,row))
    {
        values.push_back(row);
    }
    fin.close();
}


std::vector<std::string> KeywordsCPlusPlus::getData(){
    return values;
}









