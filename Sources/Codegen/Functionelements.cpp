#include "Functionelements.h"
#include "Utilities.h"

namespace Codegenerator
{

FunctionElements::FunctionElements()
{
    function = "";
    parameter = "";
    modifier = "";
    typ = "";
    isRef = false;
    isPointer = false;
    isConstant = false;

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

void FunctionElements::setElements(QString element)
{
    QStringList stringList = General::ExtractString::extractStringList(element);
    QString listelement = "";
    QString elementLast = "";
    QStringList::const_iterator constIterator;
    bool breakLoop = false;
    for (constIterator = stringList.constBegin(); constIterator != stringList.constEnd();++constIterator)
    {
        if(breakLoop)
        {
            break;
        }
        listelement = *constIterator;
        elementLast = General::ExtractString::extractLast(listelement);

        if(listelement.contains("@function"))
        {
           function = elementLast;
        }
        if(listelement.contains("@parameter"))
        {
           parameter = elementLast;
           listelement = listelement.remove(0,1);
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

        if(listelement.contains("@parameter"))
        {
            breakLoop = true;
            element = General::ExtractString::extractParameter(element);
            FunctionElements *attriElement = new FunctionElements();
            attriElement->setElements(element);
            functionParameters.push_back(attriElement);
        }
    }

}

}
