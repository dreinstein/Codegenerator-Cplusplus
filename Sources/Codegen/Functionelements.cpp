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

        if(listelement.contains("@function"))
        {
           function = elementLast;
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

/*void FunctionElements::isFunction(QString listelement,QString lastElement)
{

}

void FunctionElements::isTyp(QString listelement,QString lastElement)
{

}

void FunctionElements::isModifier(QString listelement,QString lastElement)
{

}

void FunctionElements::isReference(QString listelement,QString lastElement)
{

}

void FunctionElements::isPointer(QString listelement,QString lastElement)
{

}

void FunctionElements::isConstant(QString listelement,QString lastElement)
{

}*/

}