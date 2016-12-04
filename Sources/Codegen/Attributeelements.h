#ifndef ATTRIBUTEELEMENTS_H
#define ATTRIBUTEELEMENTS_H

#include <QString>
#include "Utilities.h"

namespace Codegenerator
{

class AttributeElements
{
public:
    AttributeElements();
    void setElements(QString element);
    QString getTyp(){return typ;}
    QString getAttribute(){return attribute;}
    QString getModifier(){return modifier;}
    bool getIsRef(){return isRef;}
    bool getIsPointer() {return isPointer;}
    bool getIsConstant() {return isConstant;}
    bool getIsMemoryConstant() {return isMemoryConstant;}
    QString getDefaultValue() const {return defaultValue;}
    bool getIsDefaultValue() const;
    void setAttribute(QString attr){attribute = attr;}
    void resetData();

private:
    QString modifier;
    QString typ;
    QString attribute;
    bool isRef;
    bool isPointer;
    bool isConstant;
    bool isMemoryConstant;
    QString defaultValue;
    void defineElements(QString listelement,QString element);
};

}

#endif // ATTRIBUTEELEMENTS_H
