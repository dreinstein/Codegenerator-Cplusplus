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
    ~FunctionElements();
    void setElements(QString element);
    QString getFunction() {return function;}
    QString getParameter() {return parameter;}
    QString getModifier() {return modifier;}
    QString getTyp() {return typ;}
    bool getIsRef() {return isRef;}
    bool getIsPointer() {return isPointer;}
    bool getIsConstant() {return isConstant;}
    std::vector<FunctionElements*> getFunctionParameters(){return functionParameters;}
private:
    //@TODO as union
    QString function;
    QString parameter;
    QString modifier;
    QString typ;
    bool isRef;
    bool isPointer;
    bool isConstant;
    std::vector<FunctionElements*> functionParameters;
};
}

#endif // FUNCTIONELEMENTS_H
