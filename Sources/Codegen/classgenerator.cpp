#include "Classgenerator.h"


namespace Codegenerator
{


ClassGenerator::ClassGenerator()
{

}

ClassGenerator::~ClassGenerator()
{

}

void ClassGenerator::generate(CodegeneratorImpl* _impl)
{
   _impl->write();
}

void ClassGenerator::generate(std::vector<QString> strVecScript, std::map<QString,QString> strMapRules)
{
    Q_ASSERT(false);
}

}

