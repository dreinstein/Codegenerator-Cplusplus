#include "Fuctioncodegenerator.h"

namespace Codegenerator
{

FuctionCodeGenerator::FuctionCodeGenerator()
{

}


FuctionCodeGenerator::~FuctionCodeGenerator()
{

}

void FuctionCodeGenerator::generate()
{
   nextElement();
}

void FuctionCodeGenerator::generate(const std::vector<QString>, const std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}

}


