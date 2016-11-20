#include <memory>
#include "Functionelements.h"
#include "Utilities.h"

namespace Codegenerator
{

FunctionElements::FunctionElements()
{
}

FunctionElements::~FunctionElements()
{
    AttributeElements* elements;
    for (auto iterator = begin(functionParameters) ; iterator != functionParameters.end();++iterator)
    {
       elements = *iterator;
       delete elements;
    }
}


void FunctionElements::resetData()
{
    function = "";
    modifier = "";
    typ = "";
    isRef = false;
    isPointer = false;
    isConstant = false;
    isReturnConstant = false;
    isMemoryConstant = false;
    defaultValue = General::ElementStrings::NO_VALUE;
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
        if(listelement.contains(General::ElementStrings::PARAMETERELEMENT))
        {
            // iterativ over all parameters
           // breakLoop = true;
            std::unique_ptr<AttributeElements> attriElement = std::unique_ptr<AttributeElements>(new Codegenerator::AttributeElements());
            attriElement->resetData();
          //  attriElement->setParameter(elementLast);
            element = General::ExtractString::extractParameter(element);
            attriElement->setElements(element);
            funcElements->getFunctionParameters().push_back(attriElement.get());
            break;
        }
        else
        {
             defineElements(listelement,elementLast);
        }
    }
}


void FunctionElements::defineElements(QString listelement, QString elementLast)
{
    if(listelement.contains(General::ElementStrings::FUNCTIONELEMENT))
    {
       function = elementLast;
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
    if(listelement.contains(General::ElementStrings::ISRETURNCONSTANTELEMENT))
    {
          isReturnConstant = true;
    }
    else if(listelement.contains(General::ElementStrings::ISMEMORYCONSTANTELEMENT))
    {
          isMemoryConstant = true;
    }
    else if(listelement.contains(General::ElementStrings::ISCONSTANTELEMENT))
    {
          isConstant = true;
    }
    else if(listelement.contains(General::ElementStrings::DEFAULTVALUEELEMENT))
    {
          defaultValue = elementLast;
    }
}



bool FunctionElements::getIsDefaultValue() const
{
    if(defaultValue != General::ElementStrings::NO_VALUE)
    {
        return true;
    }
    return false;
}


}
