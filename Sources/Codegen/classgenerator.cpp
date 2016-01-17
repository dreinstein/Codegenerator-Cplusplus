#include "Classgenerator.h"


namespace Codegenerator
{


ClassGenerator::ClassGenerator()
{

}

ClassGenerator::~ClassGenerator()
{

}

void ClassGenerator::generate()
{
   generateDefault();

}

void ClassGenerator::generate(std::vector<QString>, std::map<QString,QString>)
{
    Q_ASSERT(false);
}

}

