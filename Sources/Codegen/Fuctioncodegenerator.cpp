#include "Fuctioncodegenerator.h"
#include "../Errorhandling/FunctionScriptException.h"
#include "Functionelements.h"







namespace Codegenerator
{


FuctionCodeGenerator::FuctionCodeGenerator(const BaseCodegenerator *r)
{
    BaseCodegenerator::clone(r);
    functionElements = new Codegenerator::FunctionElements();

}


FuctionCodeGenerator::~FuctionCodeGenerator()
{

}

void FuctionCodeGenerator::generate()
{
    Q_ASSERT(functionElements);
    functionElements->setElements(functionElements,script[this->index]);

    generateHeader();
    generateSource();
    delete functionElements;
    nextElement();
}

void FuctionCodeGenerator::generate(const std::vector<QString>, const std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}

void FuctionCodeGenerator::generateHeader()
{
    Q_ASSERT(functionElements);
    bool foundModifier = false;
    QString element;
    for(list<QString>::iterator iterator = generatedCodeHeader.begin();iterator != generatedCodeHeader.end(); ++iterator)
    {
        element = *iterator;
        if(element.contains(functionElements->getModifier()))
        {
            foundModifier = true;
        }
        if(functionElements->getModifier() == modifierPublic)
        {
            if((element.contains(modifierPrivate)))
            {
                generateHeaderList(iterator,foundModifier);
                break;
            }
        }
        if ((element.contains(bracketClose)))
        {
            generateHeaderList(iterator,foundModifier);
            break;
        }
    }
}


void FuctionCodeGenerator::generateSource()
{
    Q_ASSERT(functionElements);
}

void FuctionCodeGenerator::generateHeaderList(list<QString>::iterator iterator, bool foundModifier)
{
    Q_ASSERT(functionElements);
    list<QString> templist;
    templist.splice(templist.begin(), generatedCodeHeader,iterator,generatedCodeHeader.end());
    if(!foundModifier)
    {
        // create modifier
        generatedCodeHeader.push_back(functionElements->getModifier());
        generatedCodeHeader.push_back(colon);
        generatedCodeHeader.push_back(newLine);
    }
    generatedCodeHeader.push_back(tab);
    generatedCodeHeader.push_back(functionElements->getTyp());
    generatedCodeHeader.push_back(tab);
    generatedCodeHeader.push_back(classname);
    generatedCodeHeader.push_back(colon);
    generatedCodeHeader.push_back(colon);
    generatedCodeHeader.push_back(functionElements->getFunction());
    generatedCodeHeader.push_back(parameterBracketOpen);
    generatedCodeHeader.push_back(parameterBracketClose);
    generatedCodeHeader.push_back(newLine);
    generatedCodeHeader.push_back(bracketOpen);
    generatedCodeHeader.push_back(newLine);
    generatedCodeHeader.push_back(bracketClose);
    generatedCodeHeader.push_back(newLine);
    generatedCodeHeader.insert(generatedCodeHeader.end(), templist.begin(),templist.end());
}


}


