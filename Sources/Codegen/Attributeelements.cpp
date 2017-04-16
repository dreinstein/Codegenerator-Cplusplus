#include "Attributeelements.h"

namespace Codegenerator
{

AttributeElements::AttributeElements()
{

}

void AttributeElements::resetData()
{
    modifiers.modifier = "";
    modifiers.typ = "";
    modifiers.attribute = "";
    modifiers.isRef = false;
    modifiers.isPointer = false;
    modifiers.isConstant = false;
    modifiers.isMemoryConstant = false;
    modifiers.defaultValue = General::ElementStrings::NO_VALUE;
}

void AttributeElements::setElements(QString element)
{
    QStringList stringList = General::ExtractString::extractStringList(element);
    QString listelement = "";
    QString elementLast = "";
    QStringList::const_iterator constIterator;

    for (constIterator = stringList.constBegin(); constIterator != stringList.constEnd();++constIterator)
    {
        listelement = *constIterator;
        elementLast = General::ExtractString::extractLast(listelement);
        defineElements(listelement,elementLast);
    }
}

bool AttributeElements::getIsDefaultValue() const
{
    if(modifiers.defaultValue != General::ElementStrings::NO_VALUE)
    {
        return true;
    }
    return false;
}

void AttributeElements::defineElements(QString listelement,QString elementLast)
{
    if(listelement.contains(General::ElementStrings::ATTRIBUEELEMENT))
    {
       modifiers.attribute = elementLast;
    }

    if(listelement.contains(General::ElementStrings::PARAMETERELEMENT))
    {
      modifiers. attribute = elementLast;
    }

    if(listelement.contains(General::ElementStrings::TYPELEMENT))
    {
       modifiers.typ = elementLast;
    }
    if(listelement.contains(General::ElementStrings::MODIFIERELEMENT))
    {
       modifiers.modifier = elementLast;
    }
    if(listelement.contains(General::ElementStrings::ISREFERENCEELEMENT))
    {
       modifiers.isRef = true;
    }
    if(listelement.contains(General::ElementStrings::ISPOINTERELEMENT))
    {
       modifiers.isPointer = true;
    }
    else if(listelement.contains(General::ElementStrings::ISCONSTANTELEMENT))
    {
       modifiers.isConstant = true;
    }
    else if(listelement.contains(General::ElementStrings::ISMEMORYCONSTANTELEMENT))
    {
       modifiers.isMemoryConstant = true;
    }
    else if(listelement.contains(General::ElementStrings::DEFAULTVALUEELEMENT))
    {
       modifiers.defaultValue = elementLast;
    }
}



}
