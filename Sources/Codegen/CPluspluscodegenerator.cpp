#include "CPluspluscodegenerator.h"

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


void CPlusPlusCodegenerator::generate(std::vector<QString> strVecScript, std::vector<QString> strVecKeywords, std::map<QString,QString> strMapRules)
{

    for(unsigned int i=0;i<strVecScript.size();++i)
    {

    }
    for(unsigned int i=0;i<strVecKeywords.size();++i)
    {

    }
    for(unsigned int i=0;i<strMapRules.size();++i)
    {

    }
    for(unsigned int i=0; i < codegeratorObservers.size(); i++)
    {
        codegeratorObservers[i]->notifyCodeGenerated();
    }
}

}

