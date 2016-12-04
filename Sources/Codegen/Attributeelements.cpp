#include "Attributeelements.h"

namespace Codegenerator
{

AttributeElements::AttributeElements()
{

}

void AttributeElements::resetData()
{
    modifier = "";
    typ = "";
    attribute = "";
    isRef = false;
    isPointer = false;
    isConstant = false;
    isMemoryConstant = false;
    defaultValue = General::ElementStrings::NO_VALUE;
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
    if(defaultValue != General::ElementStrings::NO_VALUE)
    {
        return true;
    }
    return false;
}

void AttributeElements::defineElements(QString listelement,QString elementLast)
{
    if(listelement.contains(General::ElementStrings::ATTRIBUEELEMENT))
    {
       attribute = elementLast;
    }

    if(listelement.contains(General::ElementStrings::PARAMETERELEMENT))
    {
       attribute = elementLast;
    }


    if(listelement.contains(General::ElementStrings::TYPELEMENT))
    {
       typ = elementLast;
    }
    if(listelement.contains(General::ElementStrings::MODIFIERELEMENT))
    {
       modifier = elementLast;
    }
    if(listelement.contains(General::ElementStrings::ISREFERENCEELEMENT))
    {
       isRef = true;
    }
    if(listelement.contains(General::ElementStrings::ISPOINTERELEMENT))
    {
       isPointer = true;
    }
    else if(listelement.contains(General::ElementStrings::ISCONSTANTELEMENT))
    {
       isConstant = true;
    }
    else if(listelement.contains(General::ElementStrings::ISMEMORYCONSTANTELEMENT))
    {
       isMemoryConstant = true;
    }
    else if(listelement.contains(General::ElementStrings::DEFAULTVALUEELEMENT))
    {
       defaultValue = elementLast;
    }
}

}
