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
  //  QString getParameter() const {return parameter;}
    QString getModifier() const {return modifier;}
    QString getTyp()const {return typ;}
    bool getIsRef()const {return isRef;}
    bool getIsPointer() const {return isPointer;}
    bool getIsConstant() const {return isConstant;}
    bool getIsReturnConstant() const {return isReturnConstant;}
    bool getIsMemoryConstant() const {return isMemoryConstant;}
    QString getDefaultValue() const {return defaultValue;}
    bool getIsDefaultValue() const;
 //   void setParameter(const QString param) {parameter = param;}
    std::vector<AttributeElements*> getFunctionParameters(){return functionParameters;}
private:

    QString function;
   // QString parameter;
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
};
}

#endif // FUNCTIONELEMENTS_H
