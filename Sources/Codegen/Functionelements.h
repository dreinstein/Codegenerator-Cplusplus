#ifndef FUNCTIONELEMENTS_H
#define FUNCTIONELEMENTS_H

#include<vector>

#include "Attributeelements.h"
#include "QString"


namespace Codegenerator
{
class FunctionElements : public AttributeElements
{
public:
    FunctionElements();
    void setElements(QString element);
    QString getFunction() {return function;}
    std::vector<AttributeElements> getFunctionParameters(){return functionParameters;}
private:
    QString function;
    std::vector<AttributeElements> functionParameters;
};
}

#endif // FUNCTIONELEMENTS_H
