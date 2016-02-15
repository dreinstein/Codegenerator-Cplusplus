#ifndef FUCTIONCODEGENERATOR_H
#define FUCTIONCODEGENERATOR_H

#include <vector>
#include <map>
#include "QString"
#include "Basecodegenerator.h"
#include "Functionelements.h"

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
private:
    void generateHeaderList(FunctionElements* elements);
    void generateSourceList(FunctionElements* elements);
};

}

#endif // FUCTIONCODEGENERATOR_H
