#ifndef FUNCTIONELEMENTS_H
#define FUNCTIONELEMENTS_H

#include<vector>

#include "Attributeelements.h"
#include "QString"


namespace Codegenerator
{
class FunctionElements
{
public:
    FunctionElements();
    void setElements(QString element);
    QString getFunction() {return function;}
    QString getModifier() {return modifier;}
    QString getTyp() {return typ;}
    bool getIsRef() {return isRef;}
    bool getIsPointer() {return isPointer;}
    bool getIsConstant() {return isConstant;}
    std::vector<AttributeElements> getFunctionParameters(){return functionParameters;}
private:
    QString function;
    QString modifier;
    QString typ;
    bool isRef;
    bool isPointer;
    bool isConstant;
    std::vector<AttributeElements> functionParameters;
};
}

#endif // FUNCTIONELEMENTS_H
