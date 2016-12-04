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
#include "Attributeelements.h"
#include "Basecodegenerator.h"



namespace Codegenerator
{


Attribute::Attribute(const BaseCodegenerator *r)
{
    BaseCodegenerator::clone(r);
    attributeElements = std::unique_ptr<Codegenerator::AttributeElements>(new Codegenerator::AttributeElements());
}

Attribute::~Attribute()
{
  //  delete functionElements;
}

void Attribute::generate()
{
    generateHeader();
    nextElement();
}

void Attribute::generate(const std::vector<QString>, const std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}

void Attribute::generateHeader(/*FunctionElements* attributElements*/)
{
    attributeElements.get()->resetData();
    attributeElements->setElements(script[this->index]);
    bool hasPublicModifier = (attributeElements->getModifier() == CodegeneratorConstants::modifierPublic);
    list<QString>::iterator iterator = foundPositionToAppendToHeaderList(hasPublicModifier);
    generateHeaderList(iterator,hasElementModifier(attributeElements->getModifier()));
}

void Attribute::generateSource()
{
    Q_ASSERT(true);
}



void Attribute::generateHeaderList(list<QString>::iterator iterator, bool foundModifier)
{
    list<QString> templist;
    templist.splice(templist.begin(), generatedCodeHeader,iterator,generatedCodeHeader.end());

   Q_ASSERT(attributeElements);

    if(!foundModifier)
    {
        // create modifier
        generatedCodeHeader.push_back(attributeElements->getModifier());
        generatedCodeHeader.push_back(CodegeneratorConstants::colon);
        generatedCodeHeader.push_back(CodegeneratorConstants::newLine);
    }
    generatedCodeHeader.push_back(CodegeneratorConstants::tab);
    generatedCodeHeader.push_back(attributeElements->getTyp());
    generatedCodeHeader.push_back(CodegeneratorConstants::tab);
    generatedCodeHeader.push_back(attributeElements.get()->getAttribute());
    generatedCodeHeader.push_back(CodegeneratorConstants::semiColon);
    generatedCodeHeader.push_back(CodegeneratorConstants::newLine);
    generatedCodeHeader.insert(generatedCodeHeader.end(), templist.begin(),templist.end());
}

}

