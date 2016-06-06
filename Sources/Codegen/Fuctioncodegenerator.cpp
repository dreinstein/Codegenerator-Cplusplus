#include "Fuctioncodegenerator.h"
#include "../Errorhandling/FunctionScriptException.h"
#include "Functionelements.h"







namespace Codegenerator
{

FuctionCodeGenerator::FuctionCodeGenerator()
{

}


FuctionCodeGenerator::~FuctionCodeGenerator()
{

}

void FuctionCodeGenerator::generate()
{
    Codegenerator::FunctionElements *functionElements = new Codegenerator::FunctionElements();
    functionElements->setElements(script[this->index]);

    generateHeader(functionElements);
    generateSource(functionElements);
    delete functionElements;
    nextElement();
}

void FuctionCodeGenerator::generate(const std::vector<QString>, const std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}

void FuctionCodeGenerator::generateHeader(FunctionElements* functionElements)
{
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
                generateHeaderList(functionElements,iterator,foundModifier);
                break;
            }
        }
        if ((element.contains(bracketClose)))
        {
            generateHeaderList(functionElements,iterator,foundModifier);
            break;
        }
    }
}


void FuctionCodeGenerator::generateSource(FunctionElements* )
{

}

void FuctionCodeGenerator::generateHeaderList(FunctionElements* functionElements, list<QString>::iterator iterator, bool foundModifier)
{
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


