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
    QString getParameter() const {return parameter;}
    QString getAttribute() const {return attribute;}
    QString getModifier() const {return modifier;}
    QString getTyp()const {return typ;}
    bool getIsRef()const {return isRef;}
    bool getIsPointer() const {return isPointer;}
    bool getIsConstant() const {return isConstant;}
    bool getIsReturnConstant() const {return isReturnConstant;}
    bool getIsMemoryConstant() const {return isMemoryConstant;}
    QString getDefaultValue() const {return defaultValue;}
    bool getIsDefaultValue() const;
    void setParameter(const QString param) {parameter = param;}
    std::vector<FunctionElements*> getFunctionParameters(){return functionParameters;}
private:

    //@TODO as union
    //@TODO some missmatch with Attributeelements, merge
    QString function;
    QString parameter;
    QString attribute;

    bool isReturnConstant;
    QString defaultValue;
    QString modifier;
    QString typ;
    bool isRef;
    bool isPointer;
    bool isConstant;
    bool isMemoryConstant;

    std::vector<FunctionElements*> functionParameters;

    const QString NO_VALUE;
    const QString FUNCTIONELEMENT = "@function";
    const QString ATTRIBUEELEMENT = "@attribute";
    const QString TYPELEMENT = "@typ";
    const QString MODIFIERELEMENT = "@modifier";
    const QString ISREFERENCEELEMENT = "@isReference";
    const QString ISPOINTERELEMENT = "@isPointer";
    const QString ISRETURNCONSTANTELEMENT = "@isReturnConstant";
    const QString ISMEMORYCONSTANTELEMENT = "@isMemoryConstant";
    const QString ISCONSTANTELEMENT = "@isConstant";
    const QString DEFAULTVALUEELEMENT = "@defaultValue";
    const QString PARAMETERELEMENT = "@parameter";

    void defineElements(QString listelement, QString elementLast);
};
}

#endif // FUNCTIONELEMENTS_H
