#include "Attributeelements.h"
#include "Codegen/Codegeneratorconstants.h"

namespace Codegenerator
{

AttributeElements::AttributeElements()
{

}

void AttributeElements::resetData()
{
    modifiers.modifier = "";
    modifiers.typ = "";
    modifiers.attribute = "";
    modifiers.isRef = false;
    modifiers.isPointer = false;
    modifiers.isConstant = false;
    modifiers.isMemoryConstant = false;
    modifiers.defaultValue = General::ElementStrings::NO_VALUE;
}

void AttributeElements::setElements(QString element)
{
    QStringList stringList = General::ExtractString::extractStringList(element);
    std::for_each(stringList.begin(),stringList.end(), [&](QString i){defineElements(i,General::ExtractString::extractLast(i));});
}

bool AttributeElements::getIsDefaultValue() const
{
    if(modifiers.defaultValue != General::ElementStrings::NO_VALUE)
    {
        return true;
    }
    return false;
}

void AttributeElements::defineElements(QString const listelement,QString const elementLast)
{
    if(listelement.contains(General::ElementStrings::ATTRIBUEELEMENT))
    {
       modifiers.attribute = elementLast;
    }

    if(listelement.contains(General::ElementStrings::PARAMETERELEMENT))
    {
      modifiers. attribute = elementLast;
    }

    if(listelement.contains(General::ElementStrings::TYPELEMENT))
    {
       modifiers.typ = elementLast;
    }
    if(listelement.contains(General::ElementStrings::MODIFIERELEMENT))
    {
       modifiers.modifier = elementLast;
    }
    if(listelement.contains(General::ElementStrings::ISREFERENCEELEMENT))
    {
       modifiers.isRef = true;
    }
    if(listelement.contains(General::ElementStrings::ISPOINTERELEMENT))
    {
       modifiers.isPointer = true;
    }
    else if(listelement.contains(General::ElementStrings::ISCONSTANTELEMENT))
    {
       modifiers.isConstant = true;
    }
    else if(listelement.contains(General::ElementStrings::ISMEMORYCONSTANTELEMENT))
    {
       modifiers.isMemoryConstant = true;
    }
    else if(listelement.contains(General::ElementStrings::DEFAULTVALUEELEMENT))
    {
       modifiers.defaultValue = elementLast;
    }
}


QString AttributeElements::getString(bool const isParameter)
{
    QString string = "";
    if(!isParameter)
    {
        if(modifiers.modifier == Codegenerator::CodegeneratorConstants::modifierPrivate)
        {
            string += Codegenerator::CodegeneratorConstants::modifierPrivate;
        }
        else if(modifiers.modifier == Codegenerator::CodegeneratorConstants::modifierProtected)
        {
            string += Codegenerator::CodegeneratorConstants::modifierProtected;
        }
        else
        {
            string += Codegenerator::CodegeneratorConstants::modifierPublic;
        }
    }
    string += Codegenerator::CodegeneratorConstants::emptyChar;

    if(modifiers.isConstant)
    {
        string += Codegenerator::CodegeneratorConstants::constant;
    }
    string += Codegenerator::CodegeneratorConstants::emptyChar;

    string += modifiers.typ;
    string += Codegenerator::CodegeneratorConstants::emptyChar;

    if(modifiers.isPointer)
    {
        string += Codegenerator::CodegeneratorConstants::pointer;
        if(modifiers.isMemoryConstant)
        {
            string += Codegenerator::CodegeneratorConstants::emptyChar;
            string += Codegenerator::CodegeneratorConstants::constant;
            string += Codegenerator::CodegeneratorConstants::emptyChar;
        }
    }
    if(modifiers.isRef)
    {
        string += Codegenerator::CodegeneratorConstants::reference;
    }
    string += Codegenerator::CodegeneratorConstants::emptyChar;
    string += modifiers.attribute;

    if(modifiers.defaultValue != "")
    {
        string += " ";
        string += "=";
        string += " ";
        string += modifiers.defaultValue;
    }
    return string;
}


}




