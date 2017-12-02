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
    void setElements(FunctionElements* funcElements,QString element);
    void resetData();
    QString getFunction() const {return function;}
    void setFunction(QString _function){function = _function;}
    QString getModifier() const {return modifier;}
    void setModifier(QString _modifier){modifier = _modifier;}
    QString getTyp()const {return typ;}
    void setTyp(QString _typ){typ = _typ;}
    bool getIsRef()const {return isRef;}
    void setIsRef(bool _isRef){isRef = _isRef;}
    bool getIsPointer() const {return isPointer;}
    void setIsPointer(bool _isPointer){isPointer = _isPointer;}
    bool getIsConstant() const {return isConstant;}
    void setIsConstant(bool _isConstant){isConstant = _isConstant;}
    bool getIsReturnConstant() const {return isReturnConstant;}
    void setIsReturnConstant(bool _isReturnConstant){isReturnConstant = _isReturnConstant;}
    bool getIsMemoryConstant() const {return isMemoryConstant;}
    void setIsMemoryConstant(bool _isMemoryConstant){isMemoryConstant = _isMemoryConstant;}
    QString getDefaultValue() const {return defaultValue;}
    void setDefaultValue(QString _defaultValue){defaultValue = _defaultValue;}
    bool getIsDefaultValue() const;
    std::vector<AttributeElements*> getFunctionParameters(){return functionParameters;}
    void pushFunctionParameter(AttributeElements* param){functionParameters.push_back(param);}
    void emptyFunctionParameters(){functionParameters.clear();}
    QString getString();
private:
    QString function;
    bool isReturnConstant;
    QString defaultValue;
    QString modifier;
    QString typ;
    bool isRef;
    bool isPointer;
    bool isConstant;
    bool isMemoryConstant;
    std::vector<AttributeElements*> functionParameters;

    void defineElements(QString listelement, QString elementLast);
    void deleteParameters();
};
}

#endif // FUNCTIONELEMENTS_H
