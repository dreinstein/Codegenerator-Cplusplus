#ifndef FUCTIONCODEGENERATOR_H
#define FUCTIONCODEGENERATOR_H

#include <vector>
#include <list>
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
    void generateHeader(FunctionElements* elements);
    void generateSource(FunctionElements* elements);
    void generateHeaderList(FunctionElements* functionElements, std::list<QString>::iterator iterator, bool foundModifier);
};

}

#endif // FUCTIONCODEGENERATOR_H
