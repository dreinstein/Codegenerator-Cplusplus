#ifndef ATTRIBUTEELEMENTS_H
#define ATTRIBUTEELEMENTS_H

#include <QString>
#include "Utilities.h"

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


class AttributeElements
{
public:
    AttributeElements();
    void setElements(QString element);
    // tpy e.g int, double
    QString getTyp(){return modifiers.typ;}
    // name
    QString getAttribute(){return modifiers.attribute;}
    // public, protected, private
    QString getModifier(){return modifiers.modifier;}
    // is Reference
    bool getIsRef(){return modifiers.isRef;}
    // is Pointer
    bool getIsPointer() {return modifiers.isPointer;}
    // is Constant, constant value
    bool getIsConstant() {return modifiers.isConstant;}
    // consts memory,posible pointer or reference
    bool getIsMemoryConstant() {return modifiers.isMemoryConstant;}
    // isParmeter, true or false, difference between attribute and parameter in function
    bool getIsParameter() {return modifiers.isParameter;}
    // default value
    QString getDefaultValue() const {return modifiers.defaultValue;}
    bool getIsDefaultValue() const;
    void setAttribute(QString attr){modifiers.attribute = attr;}
    void defineElements(QString listelement,QString element);
    void resetData();

private:
    AttributeModifiers modifiers;
};

}

#endif // ATTRIBUTEELEMENTS_H
