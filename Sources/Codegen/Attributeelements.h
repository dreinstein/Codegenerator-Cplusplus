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
 //   QString getModifierKeyword(){return modifierKeyword;}
    QString getTyp(){return typ;}
    QString getAttribute(){return attribute;}
    QString getModifier(){return modifier;}
    bool getIsRef(){return isRef;}

private:
  //  QString modifierKeyword;
    QString modifier;
    QString typ;
    QString attribute;
    bool isRef;
};

}

#endif // ATTRIBUTEELEMENTS_H
