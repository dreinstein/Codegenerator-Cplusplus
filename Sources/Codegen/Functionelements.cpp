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
    deleteParameters();
}



void FunctionElements::setElements(QString element)
{   QStringList stringList = General::ExtractString::extractStringList(element);
    QString listelement = "";
    QString elementLast = "";
    QStringList::const_iterator constIterator;
    AttributeElements *attriElement = nullptr;
    bool foundParameters= false;
    for (constIterator = stringList.constBegin(); constIterator != stringList.constEnd();++constIterator)
    {
        listelement = *constIterator;
        elementLast = General::ExtractString::extractLast(listelement);
        if(listelement.contains(General::ElementStrings::PARAMETERELEMENT))
        {
            // new parameterElement, save previous one
            if(attriElement != nullptr)
            {

                pushFunctionParameter(attriElement);
            }
            //Todo wird hier wohl nicht gelöscht
            attriElement = new AttributeElements;
            foundParameters = true;
            element = General::ExtractString::extractParameter(element);
            attriElement->resetData();
            attriElement->defineElements(listelement,elementLast);
        }
        // modifier already found, define the elements
        else if(foundParameters)
        {
            attriElement->defineElements(listelement,elementLast);
        }
        else
        {
           defineElements(listelement,elementLast);
        }
    }
    if(attriElement != nullptr)
    {
        pushFunctionParameter(attriElement);
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
