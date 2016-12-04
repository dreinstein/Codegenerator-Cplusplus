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
    deleteParameters();
}


void FunctionElements::deleteParameters()
{
    // @todo element to uniqueptr
  /*  AttributeElements* elements;
    for (auto iterator = begin(functionParameters) ; iterator != functionParameters.end();++iterator)
    {
       elements = *iterator;
       delete elements;
    }*/
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
    deleteParameters();
}


/*void FunctionElements::setElements(QString element)
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
}*/


void FunctionElements::setElements(QString element)
{   QStringList stringList = General::ExtractString::extractStringList(element);
    QString listelement = "";
    QString elementLast = "";
    QStringList::const_iterator constIterator;
    bool foundParameters= false;
    for (constIterator = stringList.constBegin(); constIterator != stringList.constEnd();++constIterator)
    {
        listelement = *constIterator;
        elementLast = General::ExtractString::extractLast(listelement);
        if(listelement.contains(General::ElementStrings::PARAMETERELEMENT))
        {
            setAttributes(listelement);
            break;
        }
        else
        {
            if(!foundParameters)
            {
                defineElements(listelement,elementLast);
            }
        }
    }
}

void FunctionElements::setAttributes(QString element)
{
    QString elementLast = General::ExtractString::extractLast(element);

    if(elementLast.contains(General::ElementStrings::PARAMETERELEMENT))
    {
        // iterativ over all parameters
       // breakLoop = true;
        AttributeElements attriElement;
        attriElement.resetData();
        attriElement.setAttribute(elementLast);
        element = General::ExtractString::extractParameter(element);
        attriElement.setElements(element);
        pushFunctionParameter(attriElement);
        attriElement.setAttribute(elementLast);
    }
}


void FunctionElements::defineElements(QString listelement, QString element)
{
    if(listelement.contains(General::ElementStrings::FUNCTIONELEMENT))
    {
       function = element;
    }

    if(listelement.contains(General::ElementStrings::TYPELEMENT))
    {
       typ = element;
    }
    if(listelement.contains(General::ElementStrings::MODIFIERELEMENT))
    {
       modifier = element;
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
          defaultValue = element;
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
