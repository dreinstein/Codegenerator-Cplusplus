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

private:
    QString modifier;
    QString typ;
    QString attribute;
    bool isRef;
    bool isPointer;
    bool isConstant;
};

}

#endif // ATTRIBUTEELEMENTS_H
