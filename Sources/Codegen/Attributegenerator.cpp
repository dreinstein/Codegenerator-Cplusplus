#include <algorithm>
#include "Attributegenerator.h"
#include "QFile"
#include "QTextStream"
#include "Utilities.h"
#include "codegeneratorconstants.h"
#include "../Errorhandling/OpenfileException.h"
#include "../Errorhandling/Attributescriptexception.h"
#include "Functionelements.h"
#include "../Errorhandling/FileNotvalidexception.h"



namespace Codegenerator
{


Attribute::Attribute()
{

}

Attribute::~Attribute()
{
    delete functionElements;
}

void Attribute::generate()
{
    //AttributeElements *attributeElements = new AttributeElements();
 /*   FunctionElements *attributeElements = new FunctionElements();
    attributeElements->resetData();
    attributeElements->setElements(script[this->index]);
*/
    generateHeader();

    nextElement();
}

void Attribute::generate(const std::vector<QString>, const std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}

void Attribute::generateHeader(/*FunctionElements* attributElements*/)
{
  //  Q_ASSERT(functionElements);
    //AttributeElements *attributeElements = new AttributeElements();
    functionElements = new FunctionElements();
    functionElements->resetData();
    functionElements->setElements(script[this->index]);
    list<QString>::iterator iterator = foundPositionToAppendToHeaderList();
    generateHeaderList(iterator,hasElementModifier());


 /*   bool foundModifier = false;
    QString element;
    list<QString>::iterator iterator = generatedCodeHeader.begin();
    for(iterator=generatedCodeHeader.begin();iterator != generatedCodeHeader.end(); ++iterator)
    {
        element = *iterator;
        if(element.contains(attributElements->getModifier()))
        {
            foundModifier = true;
        }
        if(attributElements->getModifier() == CodegeneratorConstants::modifierPublic)
        {
            if((element.contains(CodegeneratorConstants::modifierPrivate)))
            {
                generateHeaderList(attributElements,iterator,foundModifier);
                break;
            }
        }
        else if ((element.contains(CodegeneratorConstants::bracketClose)))
        {
            generateHeaderList(attributElements,iterator,foundModifier);
            break;
        }
    }
    if(generatedCodeHeader.size() <= 0)
    {
        generateHeaderList(attributElements,iterator,false);
    }*/
}

void Attribute::generateHeaderList(list<QString>::iterator iterator, bool foundModifier)
{
    list<QString> templist;
    templist.splice(templist.begin(), generatedCodeHeader,iterator,generatedCodeHeader.end());



    Q_ASSERT(functionElements);


    if(!foundModifier)
    {
        // create modifier
        generatedCodeHeader.push_back(functionElements->getModifier());
        generatedCodeHeader.push_back(CodegeneratorConstants::colon);
        generatedCodeHeader.push_back(CodegeneratorConstants::newLine);
    }
    generatedCodeHeader.push_back(CodegeneratorConstants::tab);
    generatedCodeHeader.push_back(functionElements->getTyp());
    generatedCodeHeader.push_back(CodegeneratorConstants::tab);
    generatedCodeHeader.push_back(functionElements->getAttribute());
    generatedCodeHeader.push_back(CodegeneratorConstants::semiColon);
    generatedCodeHeader.push_back(CodegeneratorConstants::newLine);
    generatedCodeHeader.insert(generatedCodeHeader.end(), templist.begin(),templist.end());


}

}

