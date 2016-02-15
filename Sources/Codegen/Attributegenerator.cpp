#include <algorithm>
#include "Attributegenerator.h"
#include "QFile"
#include "QTextStream"
#include "Utilities.h"
#include "../Errorhandling/OpenfileException.h"
#include "../Errorhandling/Attributescriptexception.h"
#include "../Errorhandling/FileNotvalidexception.h"



namespace Codegenerator
{


Attribute::Attribute()
{

}

Attribute::~Attribute()
{

}

void Attribute::generate()
{
    AttributeElements *attributeElements = new AttributeElements();
    attributeElements->setElements(script[this->index]);
    // we expect as first a modifier, if not throw Error
    if(attributeElements->getModifierKeyword()!= MODIFIER)
    {
        throw Errorhandling::AttributeScriptException();
    }
    generateHeaderList(attributeElements);
    delete attributeElements;
    nextElement();
}

void Attribute::generate(const std::vector<QString>, const std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}

void Attribute::generateHeaderList(AttributeElements* attributElements)
{
    bool foundClass = false;
    bool foundBracket = false;
    bool foundModifier = false;
    QString element;
    for(list<QString>::iterator iterator = generatedCodeHeader.begin();iterator != generatedCodeHeader.end(); ++iterator)
    {
        element = *iterator;
        if (element.contains("class"))
        {
            foundClass = true;
        }
        if(element.contains("{"))
        {
            foundBracket = true;
        }
        if(element.contains(attributElements->getModifierKeyword()) && foundBracket && foundClass)
        {
            foundModifier = true;
        }
        // suche public modifier, pos merken
        // suche private modifier, pos merken
        // such bracket }, pos merken
        // modifier ist public, public vorhanden, private vorhanden
        //    gehe vor position private und schreibe attribute
        // modifier ist public public nicht vorhanden, private vorhanden
        //    gehe vor position private, schreibe public
        //    schreibe attribute
        // modifier ist public public nicht vorhanden, private nicht vorhanden
        //    gehe eine position vor bracket } und schreibe public, schreibe attribute
        // modifier ist private, public vorhanden, private vorhanden
        //    gehe eine position vor bracket } und schreibe attribute
        // modifier ist private, public nicht vorhanden, private vorhanden
        //   gehe eine position vor bracket } und schreibe attribut
        // modifier ist private, public nicht vorhanden, private nicht vorhanden
        //   gehe eine position vor bracket } und schreibe attribute


        if((element.contains("}")) && foundBracket && foundClass)
        {
            list<QString> templist;
            templist.splice(templist.begin(), generatedCodeHeader,iterator,generatedCodeHeader.end());
            if(!foundModifier)
            {
                // create modifier
                generatedCodeHeader.push_back(attributElements->getModifier());
                generatedCodeHeader.push_back(":");
                generatedCodeHeader.push_back("\n");
            }
            generatedCodeHeader.push_back(tab);
            generatedCodeHeader.push_back(attributElements->getTyp());
            generatedCodeHeader.push_back(" ");
            generatedCodeHeader.push_back(attributElements->getAttribute());
            generatedCodeHeader.push_back(";");
            generatedCodeHeader.push_back("\n");
            generatedCodeHeader.insert(generatedCodeHeader.end(), templist.begin(),templist.end());
            break;
        }
    }
    // if Class not found, then throw exeption
    if((false == foundClass) || (false == foundBracket ))
    {
        throw Errorhandling::FileNotValidException();
    }
}

}

