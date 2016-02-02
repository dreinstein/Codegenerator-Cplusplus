#include <QFile>
#include <iostream>
#include <qglobal.h>
#include "Utilities.h"
#include "CPluspluscodegenerator.h"
#include "Basecodegenerator.h"
#include "../Errorhandling/Exceptionhandling.h"


using namespace Errorhandling;


namespace Codegenerator
{

CPlusPlusCodegenerator::CPlusPlusCodegenerator()
{

}


CPlusPlusCodegenerator::~CPlusPlusCodegenerator()
{

}

void CPlusPlusCodegenerator::registerObservers(BaseGenerator *observer)
{
    codegeratorObservers.push_back(&*observer);
}

void CPlusPlusCodegenerator::generate()
{
}


void CPlusPlusCodegenerator::generate(std::vector<QString> strVecScript,std::map<QString,QString> strMapRules,std::vector<QString> strVecKeys)
{
    script = strVecScript;
    rules = strMapRules;
    keys = strVecKeys;
    index = 0;
    nextElement();
}



}

