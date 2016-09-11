#include "Classgenerator.h"


namespace Codegenerator
{



ClassGenerator::~ClassGenerator()
{

}

void ClassGenerator::generate()
{
   BaseCodegenerator::generate();

//   ++index;
   nextElement();

}

void ClassGenerator::generate(const std::vector<QString>, const std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}

}

