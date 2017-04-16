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
    QString getTyp(){return modifiers.typ;}
    QString getAttribute(){return modifiers.attribute;}
    QString getModifier(){return modifiers.modifier;}
    bool getIsRef(){return modifiers.isRef;}
    bool getIsPointer() {return modifiers.isPointer;}
    bool getIsConstant() {return modifiers.isConstant;}
    bool getIsMemoryConstant() {return modifiers.isMemoryConstant;}
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
