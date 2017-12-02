#include <memory>
#include "Functionelements.h"
#include "Utilities.h"
#include "Codegen/Codegeneratorconstants.h"

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
            attriElement = new AttributeElements;
          //  foundParameters = true;
            element = General::ExtractString::extractParameter(element);
            attriElement->resetData();
            attriElement->defineElements(listelement,elementLast);
        }
        // modifier already found, define the elements
        else if(attriElement != nullptr)
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

QString FunctionElements::getString()
{
    QString s = getModifier();
    s += Codegenerator::CodegeneratorConstants::emptyChar;
    if(getIsReturnConstant())
    {
        s += Codegenerator::CodegeneratorConstants::constant;
        s += Codegenerator::CodegeneratorConstants::emptyChar;
    }

    s += getTyp();
    s += Codegenerator::CodegeneratorConstants::emptyChar;

    if(getIsPointer())
    {
        s += Codegenerator::CodegeneratorConstants::pointer;
        s += Codegenerator::CodegeneratorConstants::emptyChar;
    }
    if(getIsRef())
    {
        s += Codegenerator::CodegeneratorConstants::reference;
        s += Codegenerator::CodegeneratorConstants::emptyChar;
    }

    if(getIsMemoryConstant())
    {
        s += Codegenerator::CodegeneratorConstants::constant;
        s += Codegenerator::CodegeneratorConstants::emptyChar;
    }

    s += getFunction();
    s += Codegenerator::CodegeneratorConstants::emptyChar;
    s+= Codegenerator::CodegeneratorConstants::parameterBracketOpen;
    bool firstParameterElement = true;

    for(auto param:functionParameters)
    {
        if(!firstParameterElement)
        {
            s += Codegenerator::CodegeneratorConstants::comma;
            s+= Codegenerator::CodegeneratorConstants::emptyChar;
        }
        else
        {
            firstParameterElement = false;
        }

        if(param->getIsConstant())
        {
            s += Codegenerator::CodegeneratorConstants::constant;
            s += Codegenerator::CodegeneratorConstants::emptyChar;
        }
        s +=  param->getTyp();
        s += Codegenerator::CodegeneratorConstants::emptyChar;

        if(param->getIsPointer())
        {
            s += Codegenerator::CodegeneratorConstants::pointer;
            s += Codegenerator::CodegeneratorConstants::emptyChar;
        }
        if (param->getIsRef())
        {
            s += Codegenerator::CodegeneratorConstants::reference;
            s += Codegenerator::CodegeneratorConstants::emptyChar;
        }
        if(param->getIsMemoryConstant())
        {
            s += Codegenerator::CodegeneratorConstants::constant;
            s += Codegenerator::CodegeneratorConstants::emptyChar;
        }
        s += param->getAttribute();
        s+= Codegenerator::CodegeneratorConstants::emptyChar;
        if(param->getIsDefaultValue())
        {
            s += Codegenerator::CodegeneratorConstants::equal;
            s+= Codegenerator::CodegeneratorConstants::emptyChar;
            s+= param->getDefaultValue();
            s+= Codegenerator::CodegeneratorConstants::emptyChar;
        }
    }
     s+= Codegenerator::CodegeneratorConstants::parameterBracketClose;
    if(getIsConstant())
    {
        s+= Codegenerator::CodegeneratorConstants::emptyChar;
        s+= Codegenerator::CodegeneratorConstants::constant;
    }
    return s;
}

}
