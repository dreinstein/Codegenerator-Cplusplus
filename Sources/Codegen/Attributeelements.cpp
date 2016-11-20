#include "QString"
#include "Attributeelements.h"
#include "Utilities.h"

namespace Codegenerator
{

AttributeElements::AttributeElements()
{
    attribute = "";
    typ = "";
    modifier = "";
    isRef = false;
}

void AttributeElements::resetData()
{

    modifier="";
    typ = "";
    attribute="";
    isRef = false;
    isPointer = false;
    isConstant = false;
    defaultValue = "";
}

void AttributeElements::setElements(QString element)
{
    QStringList stringList = General::ExtractString::extractStringList(element);
    // search @function
    QString listelement = "";
    QString elementLast = "";
    QStringList::const_iterator constIterator;
    for (constIterator = stringList.constBegin(); constIterator != stringList.constEnd();++constIterator)
    {
        listelement = *constIterator;
        elementLast = General::ExtractString::extractLast(listelement);
        if(listelement.contains("@attribute"))
        {
            attribute = elementLast;
        }
        if(listelement.contains("@typ"))
        {
            typ = elementLast;
        }
        if(listelement.contains("@modifier"))
        {
            modifier = elementLast;
        }
        if(listelement.contains("@isReference"))
        {
            QString s_isRef = elementLast;
            if(s_isRef == "true")
            {
                isRef = true;
            }
            else
            {
                isRef = false;
            }
        }
        if(listelement.contains("@isPointer"))
        {
            QString s_isPointer = elementLast;
            if(s_isPointer == "true")
            {
                isPointer = true;
            }
            else
            {
                isPointer = false;
            }
        }
        if(listelement.contains("@isConstant"))
        {
            QString s_isConstant = elementLast;
            if(s_isConstant == "true")
            {
                isConstant = true;
            }
            else
            {
                isConstant = false;
            }
        }
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
}
