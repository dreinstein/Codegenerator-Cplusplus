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
    void setElements(FunctionElements* funcElements,QString element);
    QString getFunction() const {return function;}
    QString getParameter() const {return parameter;}
    QString getModifier() const {return modifier;}
    QString getTyp()const {return typ;}
    bool getIsRef()const {return isRef;}
    bool getIsPointer() const {return isPointer;}
    bool getIsConstant() const {return isConstant;}
    getIsReturnConstant() const {return isReturnConstant;}
    getIsMemoryConstant() const {return isMemoryConstant;}
    void setParameter(const QString param) {parameter = param;}
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
    bool isMemoryConstant;
    bool isReturnConstant;
    std::vector<FunctionElements*> functionParameters;
};
}

#endif // FUNCTIONELEMENTS_H
