#include "Functionelements.h"
#include "Utilities.h"

namespace Codegenerator
{

FunctionElements::FunctionElements(): NO_VALUE("NoValue"),FUNCTIONELEMENT("@function"),TYPELEMENT("@typ"),
    MODIFIERELEMENT("@modifier"),ISREFERENCEELEMENT("@isReference"),ISPOINTERELEMENT("@isPointer"),
    ISRETURNCONSTANTELEMENT("@isReturnConstant"),ISMEMORYCONSTANTELEMENT("@isMemoryConstant"),
    ISCONSTANTELEMENT("@isConstant"), DEFAULTVALUEELEMENT("@defaultValue"),
    PARAMETERELEMENT("@parameter")
{
    function = "";
    parameter = "";
    modifier = "";
    typ = "";
    isRef = false;
    isPointer = false;
    isConstant = false;
    isReturnConstant = false;
    isMemoryConstant = false;
    defaultValue = NO_VALUE;
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



void FunctionElements::setElements(FunctionElements* funcElements,QString element)
{
    QStringList stringList = General::ExtractString::extractStringList(element);
    QString listelement = "";
    QString elementLast = "";
    QStringList::const_iterator constIterator;
    for (constIterator = stringList.constBegin(); constIterator != stringList.constEnd();++constIterator)
    {
        listelement = *constIterator;
        elementLast = General::ExtractString::extractLast(listelement);

        if(listelement.contains(FUNCTIONELEMENT))
        {
           function = elementLast;
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


        if(listelement.contains(PARAMETERELEMENT))
        {
            // iterativ over all parameters
           // breakLoop = true;
            FunctionElements *attriElement = new FunctionElements();
            attriElement->setParameter(elementLast);
            element = General::ExtractString::extractParameter(element);
            attriElement->setElements(funcElements,element);
            funcElements->functionParameters.push_back(attriElement);
            break;
        }
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
