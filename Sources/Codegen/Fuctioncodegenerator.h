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
    void generateHeader();
    void generateSource();
    void generateHeaderList(std::list<QString>::iterator iterator, bool foundModifier);
    void generateHeaderList(bool foundModifier);
    void setHeaderParameterElements(std::list<QString>& codeList,AttributeElements* parameterElements, bool generateHeaderFile = true);
    void setHeaderFunctionElements(bool modifier);
    void setHeaderClassFinal();
    void setHeaderClassFinalForConstant();
    void setTypForFunctionElements(std::list<QString>& codeList,FunctionElements* element);
    void setTypForParameterElements(std::list<QString>& codeList,AttributeElements* element);
    void setTyp(std::list<QString>& codeList,FunctionElements* element);
    void setTyp(std::list<QString>& codeList,AttributeElements* element);

};

}

#endif // FUCTIONCODEGENERATOR_H
