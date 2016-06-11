#include "Fuctioncodegenerator.h"
#include "../Errorhandling/FunctionScriptException.h"
#include "Functionelements.h"
#include "Codegeneratorconstants.h"







namespace Codegenerator
{


FuctionCodeGenerator::FuctionCodeGenerator(const BaseCodegenerator *r)
{
    BaseCodegenerator::clone(r);
    functionElements = new Codegenerator::FunctionElements();

}


FuctionCodeGenerator::~FuctionCodeGenerator()
{
    delete functionElements;

}

void FuctionCodeGenerator::generate()
{
    Q_ASSERT(functionElements);
    functionElements->setElements(functionElements,script[this->index]);

    generateHeader();
    generateSource();
  //  delete functionElements;
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
        if(functionElements->getModifier() == CodegeneratorConstants::modifierPublic)
        {
            if((element.contains(CodegeneratorConstants::modifierPrivate)))
            {
                generateHeaderList(iterator,foundModifier);
                break;
            }
        }
        if ((element.contains(CodegeneratorConstants::bracketClose)))
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
    setHeaderFunctionElements(foundModifier);
    vector<FunctionElements*> parameterelements = functionElements->getFunctionParameters();
    if(parameterelements.size() > 0)
    {

        for(auto iterator = parameterelements.begin();iterator != parameterelements.end(); ++iterator)
        {
           // FunctionElements *paraelements = *iterator;
            setHeaderParameterElements(*iterator);
        }

    }
    setHeaderClassFinal();
    generatedCodeHeader.insert(generatedCodeHeader.end(), templist.begin(),templist.end());
}


void FuctionCodeGenerator::setHeaderFunctionElements(bool modifier)
{
    if(!modifier)
    {
        // create modifier
        generatedCodeHeader.push_back(functionElements->getModifier());
        generatedCodeHeader.push_back(CodegeneratorConstants::colon);
        generatedCodeHeader.push_back(CodegeneratorConstants::newLine);
    }
    generatedCodeHeader.push_back(CodegeneratorConstants::tab);
    generatedCodeHeader.push_back(functionElements->getTyp());
    generatedCodeHeader.push_back(CodegeneratorConstants::tab);
    generatedCodeHeader.push_back(functionElements->getFunction());
    generatedCodeHeader.push_back(CodegeneratorConstants::parameterBracketOpen);
}

void FuctionCodeGenerator::setHeaderClassFinal()
{
    generatedCodeHeader.push_back(CodegeneratorConstants::parameterBracketClose);
    generatedCodeHeader.push_back(CodegeneratorConstants::semiColon);
    generatedCodeHeader.push_back(CodegeneratorConstants::newLine);
}


void FuctionCodeGenerator::setHeaderParameterElements(FunctionElements* parameterElements)
{
    if(parameterElements->getIsConstant())
    {
        generatedCodeHeader.push_back(CodegeneratorConstants::constant);
        generatedCodeHeader.push_back(CodegeneratorConstants::emptyChar);
    }
    if(parameterElements->getTyp() != "")
    {
        generatedCodeHeader.push_back(parameterElements->getTyp());
        generatedCodeHeader.push_back(CodegeneratorConstants::emptyChar);
    }
    else
    {
        // must have a typ
        // TODO Errorhandling
    }

    if(parameterElements->getIsRef())
    {
        generatedCodeHeader.push_back(CodegeneratorConstants::reference);
        generatedCodeHeader.push_back(CodegeneratorConstants::emptyChar);
    }

    if(parameterElements->getIsPointer())
    {
        generatedCodeHeader.push_back(CodegeneratorConstants::pointer);
        generatedCodeHeader.push_back(CodegeneratorConstants::emptyChar);
    }


    if(parameterElements->getParameter() != "")
    {
        generatedCodeHeader.push_back(parameterElements->getParameter());
    //    generatedCodeHeader.push_back(CodegeneratorConstants::emptyChar);
    }
    else
    {
        // must have a parameter name
        // TODO Errorhandling
    }



    }
}




