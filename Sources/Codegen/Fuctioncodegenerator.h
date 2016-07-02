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
    // @ToDo document functions
   // std::list<QString>::iterator foundPositionToAppendToHeaderList();
   // bool hasElementModifier();
    void generateHeader();
    void generateSource();
    void generateHeaderList(std::list<QString>::iterator iterator, bool foundModifier);
    void generateHeaderList(bool foundModifier);
    void setHeaderParameterElements(FunctionElements* parameterElements);
    void setHeaderFunctionElements(bool modifier);
    void setHeaderClassFinal();
    void setHeaderClassFinalForConstant();
    void setHeaderTyp(FunctionElements* element);
    void setHeaderTypForFunctionElements(FunctionElements* element);
    void setHeaderTypForParameterElements(FunctionElements* element);

};

}

#endif // FUCTIONCODEGENERATOR_H
