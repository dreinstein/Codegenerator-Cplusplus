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

    FuctionCodeGenerator(const BaseCodegenerator *r);
    virtual ~FuctionCodeGenerator();
    void generate() override final;
    void generate(const std::vector<QString> strVecScript, const std::map<QString,QString> strMapRules,const std::vector<QString> strVecKeys) override final;

private:
    FuctionCodeGenerator();
   // FunctionElements *functionElements = nullptr;
    void generateHeader();
    void generateSource();
    void generateHeaderList(std::list<QString>::iterator iterator, bool foundModifier);
};

}

#endif // FUCTIONCODEGENERATOR_H
