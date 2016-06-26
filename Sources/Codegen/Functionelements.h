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
    QString getDefaultValue() const {return defaultValue;}
    bool getIsDefaultValue() const;
    void setParameter(const QString param) {parameter = param;}
    std::vector<FunctionElements*> getFunctionParameters(){return functionParameters;}
private:

    //@TODO as union
    //@TODO some missmatch with Attributeelements, merge
    QString function;
    QString parameter;
    QString modifier;
    QString typ;
    bool isRef;
    bool isPointer;
    bool isConstant;
    bool isMemoryConstant;
    bool isReturnConstant;
    QString defaultValue;
    std::vector<FunctionElements*> functionParameters;

    const QString NO_VALUE;
};
}

#endif // FUNCTIONELEMENTS_H
