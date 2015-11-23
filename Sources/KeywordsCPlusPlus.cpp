///////////////////////////////////////////////////////////
//  KeywordsCPlusPlus.cpp
//  Implementation of the Class KeywordsCPlusPlus
//  Created on:      10-Nov-2015 20:34:05
//  Original author: udo_2
///////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
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

void KeywordsCPlusPlus::GetType()
{
   // return General::Types::DataTypes::Vector;
}

void KeywordsCPlusPlus::GetDatas()
{
}






