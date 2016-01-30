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
//   ++index;
   nextElement();

}

void ClassGenerator::generate(std::vector<QString>, std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}

}

