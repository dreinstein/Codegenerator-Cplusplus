#ifndef FUCTIONCODEGENERATOR_H
#define FUCTIONCODEGENERATOR_H

#include <vector>
#include <map>
#include "Basecodegenerator.h"

namespace Codegenerator
{


class FuctionCodeGenerator:public BaseCodegenerator
{
public:
    FuctionCodeGenerator();
    FuctionCodeGenerator(const BaseCodegenerator *r){BaseCodegenerator::clone(r);}
    virtual ~FuctionCodeGenerator();
    void generate() override final;
    void generate(const std::vector<QString> strVecScript, const std::map<QString,QString> strMapRules,const std::vector<QString> strVecKeys) override final;
};

}

#endif // FUCTIONCODEGENERATOR_H
