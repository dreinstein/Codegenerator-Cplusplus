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

    generateHeader(attributeElements);
    delete attributeElements;
    nextElement();
}

void Attribute::generate(const std::vector<QString>, const std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}

void Attribute::generateHeader(AttributeElements* attributElements)
{
    bool foundModifier = false;
    QString element;
    for(list<QString>::iterator iterator = generatedCodeHeader.begin();iterator != generatedCodeHeader.end(); ++iterator)
    {
        element = *iterator;
        if(element.contains(attributElements->getModifier()))
        {
            foundModifier = true;
        }
        if(attributElements->getModifier() == modifierPublic)
        {
            if((element.contains(modifierPrivate)))
            {
                generateHeaderList(attributElements,iterator,foundModifier);
                break;
            }
        }
        else if ((element.contains(bracketClose)))
        {
            generateHeaderList(attributElements,iterator,foundModifier);
            break;
        }
    }
}

void Attribute::generateHeaderList(AttributeElements* attributElements, list<QString>::iterator iterator, bool foundModifier)
{
    list<QString> templist;
    templist.splice(templist.begin(), generatedCodeHeader,iterator,generatedCodeHeader.end());
    if(!foundModifier)
    {
        // create modifier
        generatedCodeHeader.push_back(attributElements->getModifier());
        generatedCodeHeader.push_back(colon);
        generatedCodeHeader.push_back(newLine);
    }
    generatedCodeHeader.push_back(tab);
    generatedCodeHeader.push_back(attributElements->getTyp());
    generatedCodeHeader.push_back(tab);
    generatedCodeHeader.push_back(attributElements->getAttribute());
    generatedCodeHeader.push_back(semiColon);
    generatedCodeHeader.push_back(newLine);
    generatedCodeHeader.insert(generatedCodeHeader.end(), templist.begin(),templist.end());

}

}

