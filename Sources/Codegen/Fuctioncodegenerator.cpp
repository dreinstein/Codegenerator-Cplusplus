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
    if(generatedCodeHeader.size() > 0)
    {
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
    // no class definition only function
    else
    {
        generateHeaderList(false);
    }


}

void FuctionCodeGenerator::generateSource()
{
    Q_ASSERT(functionElements);
}

void FuctionCodeGenerator::generateHeaderList(bool foundModifier)
{
    Q_ASSERT(functionElements);
    setHeaderFunctionElements(foundModifier);
    vector<FunctionElements*> parameterelements = functionElements->getFunctionParameters();
    if(parameterelements.size() > 0)
    {
        // from back to front, it is rekursiv parameterelements begin with last funktionparameter
        for(auto iterator = parameterelements.rbegin();iterator != parameterelements.rend(); ++iterator)
        {
            // need a colon between parameters
            if(iterator != parameterelements.rbegin())
            {
                generatedCodeHeader.push_back(Codegenerator::CodegeneratorConstants::comma);
            }

           // FunctionElements *paraelements = *iterator;
            setHeaderParameterElements(*iterator);
        }

    }

    if(functionElements->getIsConstant())
    {
       setHeaderClassFinalForConstant();
    }
    else
    {
        setHeaderClassFinal();
    }


}

void FuctionCodeGenerator::generateHeaderList(list<QString>::iterator iterator, bool foundModifier)
{
    Q_ASSERT(functionElements);
    list<QString> templist;
    templist.splice(templist.begin(), generatedCodeHeader,iterator,generatedCodeHeader.end());
    generateHeaderList(foundModifier);
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
    setHeaderTypForFunctionElements(functionElements);
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

void FuctionCodeGenerator::setHeaderClassFinalForConstant()
{
    generatedCodeHeader.push_back(CodegeneratorConstants::parameterBracketClose);
    generatedCodeHeader.push_back(CodegeneratorConstants::tab);
    generatedCodeHeader.push_back(CodegeneratorConstants::constant);
    generatedCodeHeader.push_back(CodegeneratorConstants::semiColon);
    generatedCodeHeader.push_back(CodegeneratorConstants::newLine);
}





void FuctionCodeGenerator::setHeaderParameterElements(FunctionElements* parameterElements)
{

    setHeaderTypForParameterElements(parameterElements);
    if(parameterElements->getParameter() != "")
    {
        generatedCodeHeader.push_back(CodegeneratorConstants::tab);
        generatedCodeHeader.push_back(parameterElements->getParameter());
    }
    else
    {
        Q_ASSERT(false);
    }
}

void FuctionCodeGenerator::setHeaderTypForFunctionElements(FunctionElements* element)
{
    if(element->getIsReturnConstant())
    {
        generatedCodeHeader.push_back(CodegeneratorConstants::constant);
        generatedCodeHeader.push_back(CodegeneratorConstants::tab);
    }
    setHeaderTyp(element);
}


void FuctionCodeGenerator::setHeaderTypForParameterElements(FunctionElements* element)
{
    if(element->getIsConstant())
    {
        generatedCodeHeader.push_back(CodegeneratorConstants::constant);
        generatedCodeHeader.push_back(CodegeneratorConstants::tab);
    }
    setHeaderTyp(element);
}


void FuctionCodeGenerator::setHeaderTyp(FunctionElements* element)
{

    if(element->getTyp() != "")
    {
        generatedCodeHeader.push_back(element->getTyp());
    }
    else
    {
        Q_ASSERT(false);
    }

    if(element->getIsRef())
    {
        generatedCodeHeader.push_back(CodegeneratorConstants::reference);
    }

    if(element->getIsPointer())
    {
        generatedCodeHeader.push_back(CodegeneratorConstants::pointer);
    }


}

}

