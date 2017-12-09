#ifndef ATTRIBUTEELEMENTS_H
#define ATTRIBUTEELEMENTS_H

#include <QString>
#include "Utilities.h"
#include "baseelements.h"

namespace Codegenerator
{

struct AttributeModifiers
{
    QString modifier="";
    QString typ="";
    QString attribute="";
    bool isRef=false;
    bool isPointer=false;
    bool isConstant=false;
    bool isMemoryConstant=false;
    QString defaultValue="";
    bool isParameter=false;
};


class AttributeElements:public BaseElements
{
public:
    AttributeElements(){;}
    virtual ~AttributeElements(){;}
    void setElements(QString element) override final;
    // tpy e.g int, double
    QString getTyp(){return modifiers.typ;}
    void setTyp(QString typ){modifiers.typ = typ;}
    // name
    QString getAttribute(){return modifiers.attribute;}
     void setAttribute(QString attr){modifiers.attribute = attr;}
    // public, protected, private
    QString getModifier(){return modifiers.modifier;}
    void setModifier(QString modifier){modifiers.modifier = modifier;}
    // is Reference
    bool getIsRef(){return modifiers.isRef;}
    void setIsRef(bool ref){modifiers.isRef = ref;}
    // is Pointer
    bool getIsPointer() {return modifiers.isPointer;}
    void setIsPointer(bool isPointer){modifiers.isPointer = isPointer;}
    // is Constant, constant value
    bool getIsConstant() {return modifiers.isConstant;}
    void setIsConstant(bool isConstant){modifiers.isConstant = isConstant;}
    // consts memory,posible pointer or reference
    bool getIsMemoryConstant() {return modifiers.isMemoryConstant;}
    void setIsMemoryConstant(bool isMemoryConstant){modifiers.isMemoryConstant = isMemoryConstant;}
    // isParmeter, true or false, difference between attribute and parameter in function
    bool getIsParameter() {return modifiers.isParameter;}
    void setIsParameter(bool isParameter){modifiers.isParameter = isParameter;}
    // default value
    QString getDefaultValue() const {return modifiers.defaultValue;}
    void setDefaultValue(QString defaultValue){modifiers.defaultValue = defaultValue;}
    bool getIsDefaultValue() const;

    void defineElements(QString const listelement,QString const element) override final;
    void resetData() override final;
    QString getString(bool const  isParameter=false) override final;
private:
    AttributeModifiers modifiers;
};

}

#endif // ATTRIBUTEELEMENTS_H
