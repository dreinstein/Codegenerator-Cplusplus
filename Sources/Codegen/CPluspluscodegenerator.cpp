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

void CPlusPlusCodegenerator::generate()
{
    for(unsigned int i=0; i < codegeratorObservers.size(); i++)
    {
        codegeratorObservers[i]->notifyCodeGenerated();
    }
}

}

