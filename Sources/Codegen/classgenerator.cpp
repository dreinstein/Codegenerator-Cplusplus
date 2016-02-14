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

void ClassGenerator::generate(const std::vector<QString>, const std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}

}

