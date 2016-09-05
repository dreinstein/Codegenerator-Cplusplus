#include "Functionelements.h"
#include "Utilities.h"

namespace Codegenerator
{

FunctionElements::FunctionElements()
{
}

FunctionElements::~FunctionElements()
{
    FunctionElements* elements;
    for (auto iterator = begin(functionParameters) ; iterator != functionParameters.end();++iterator)
    {
       elements = *iterator;
       delete elements;
    }
}


void FunctionElements::resetData()
{
    function = "";
    parameter = "";
    modifier = "";
    attribute = "";
    typ = "";
    isRef = false;
    isPointer = false;
    isConstant = false;
    isReturnConstant = false;
    isMemoryConstant = false;
    defaultValue = NO_VALUE;
}


void FunctionElements::setElements(QString element)
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


void FunctionElements::setElements(FunctionElements* funcElements,QString element)
{   QStringList stringList = General::ExtractString::extractStringList(element);
    QString listelement = "";
    QString elementLast = "";
    QStringList::const_iterator constIterator;
    for (constIterator = stringList.constBegin(); constIterator != stringList.constEnd();++constIterator)
    {
        listelement = *constIterator;
        elementLast = General::ExtractString::extractLast(listelement);
        defineElements(listelement,elementLast);
        if(listelement.contains(PARAMETERELEMENT))
        {
            // iterativ over all parameters
           // breakLoop = true;
            FunctionElements *attriElement = new FunctionElements();
            attriElement->resetData();
            attriElement->setParameter(elementLast);
            element = General::ExtractString::extractParameter(element);
            attriElement->setElements(funcElements,element);
            funcElements->functionParameters.push_back(attriElement);
            break;
        }
    }
}


void FunctionElements::defineElements(QString listelement, QString elementLast)
{
    if(listelement.contains(FUNCTIONELEMENT))
    {
       function = elementLast;
    }

    if(listelement.contains(ATTRIBUEELEMENT))
    {
       attribute = elementLast;
    }

    if(listelement.contains(TYPELEMENT))
    {
       typ = elementLast;
    }
    if(listelement.contains(MODIFIERELEMENT))
    {
       modifier = elementLast;
    }
    if(listelement.contains(ISREFERENCEELEMENT))
    {
          isRef = true;
    }
    if(listelement.contains(ISPOINTERELEMENT))
    {
          isPointer = true;
    }
    if(listelement.contains(ISRETURNCONSTANTELEMENT))
    {
          isReturnConstant = true;
    }
    else if(listelement.contains(ISMEMORYCONSTANTELEMENT))
    {
          isMemoryConstant = true;
    }
    else if(listelement.contains(ISCONSTANTELEMENT))
    {
          isConstant = true;
    }
    else if(listelement.contains(DEFAULTVALUEELEMENT))
    {
          defaultValue = elementLast;
    }
}





bool FunctionElements::getIsDefaultValue() const
{
    if(defaultValue != NO_VALUE)
    {
        return true;
    }
    return false;
}


}
