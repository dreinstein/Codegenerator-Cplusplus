#include "Fuctioncodegenerator.h"
#include "../Errorhandling/FunctionScriptException.h"
#include "Functionelements.h"
#include "Codegeneratorconstants.h"



namespace Codegenerator
{


FuctionCodeGenerator::FuctionCodeGenerator(const BaseCodegenerator *r)
{
    BaseCodegenerator::clone(r);
    functionElements = std::unique_ptr<FunctionElements>(new Codegenerator::FunctionElements());
}


FuctionCodeGenerator::~FuctionCodeGenerator()
{
  //  delete functionElements;

}

void FuctionCodeGenerator::generate()
{
    Q_ASSERT(functionElements);
    functionElements->resetData();
    functionElements->setElements(functionElements.get(),script[this->index]);
    generateHeader();
    generateSource();
    nextElement();
}

void FuctionCodeGenerator::generate(const std::vector<QString>, const std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}

void FuctionCodeGenerator::generateHeader()
{
    Q_ASSERT(functionElements);
    bool hasPublicModifier = (functionElements->getModifier() == CodegeneratorConstants::modifierPublic);
    list<QString>::iterator iterator = foundPositionToAppendToHeaderList(hasPublicModifier);
    generateHeaderList(iterator,hasElementModifier(functionElements->getModifier()));
}



void FuctionCodeGenerator::generateSource()
{
    Q_ASSERT(functionElements);
    vector<AttributeElements*> parameterelements = functionElements->getFunctionParameters();
    generatedCodeSource.push_back(CodegeneratorConstants::newLine);
 //   generatedCodeSource.push_back(functionElements->getTyp());
    setTypForFunctionElements(generatedCodeSource,functionElements.get());
    generatedCodeSource.push_back(CodegeneratorConstants::tab);
    if(classname != "")
    {
        generatedCodeSource.push_back(classname);
        generatedCodeSource.push_back(CodegeneratorConstants::colon);
        generatedCodeSource.push_back(CodegeneratorConstants::colon);
    }
    generatedCodeSource.push_back(functionElements->getFunction());
    generatedCodeSource.push_back(CodegeneratorConstants::parameterBracketOpen);

    if(parameterelements.size() > 0)
    {
        // from back to front, it is rekursiv parameterelements begin with last funktionparameter
        for(auto iterator = parameterelements.rbegin();iterator != parameterelements.rend(); ++iterator)
        {
            // need a colon between parameters
            if(iterator != parameterelements.rbegin())
            {
                generatedCodeSource.push_back(Codegenerator::CodegeneratorConstants::comma);
            }

            setHeaderParameterElements(generatedCodeSource,*iterator, false);
        }
    }
    generatedCodeSource.push_back(CodegeneratorConstants::parameterBracketClose);
    generatedCodeSource.push_back(CodegeneratorConstants::newLine);
    generatedCodeSource.push_back(CodegeneratorConstants::bracketOpen);
    generatedCodeSource.push_back(CodegeneratorConstants::newLine);
    generatedCodeSource.push_back(CodegeneratorConstants::bracketClose);
}




void FuctionCodeGenerator::generateHeaderList(bool foundModifier)
{
    Q_ASSERT(functionElements);
    setHeaderFunctionElements(foundModifier);
    vector<AttributeElements*> parameterelements = functionElements->getFunctionParameters();
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
            setHeaderParameterElements(generatedCodeHeader,*iterator);
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
    setTypForFunctionElements(generatedCodeHeader,functionElements.get());
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





void FuctionCodeGenerator::setHeaderParameterElements(std::list<QString>& codeList, AttributeElements* parameterElements, bool generateHeaderFile)
{

    setTypForParameterElements(codeList,parameterElements);
    codeList.push_back(CodegeneratorConstants::tab);
    codeList.push_back(parameterElements->getAttribute());

    if(parameterElements->getIsDefaultValue()&& generateHeaderFile)
    {
        codeList.push_back(CodegeneratorConstants::tab);
        codeList.push_back(CodegeneratorConstants::equal);
        codeList.push_back(CodegeneratorConstants::tab);
        codeList.push_back(parameterElements->getDefaultValue());
    }
}

void FuctionCodeGenerator::setTypForFunctionElements(std::list<QString>& codeList,FunctionElements* element)
{
    if(element->getIsReturnConstant())
    {
        codeList.push_back(CodegeneratorConstants::constant);
        codeList.push_back(CodegeneratorConstants::tab);
    }
    setTyp(codeList,element);
}


void FuctionCodeGenerator::setTypForParameterElements(std::list<QString>& codeList,AttributeElements* element)
{
    if(element->getIsConstant())
    {
        codeList.push_back(CodegeneratorConstants::constant);
        codeList.push_back(CodegeneratorConstants::tab);
    }
    setTyp(codeList,element);
}


void FuctionCodeGenerator::setTyp(std::list<QString>& codeList,FunctionElements* element)
{

    if(element->getTyp() != "")
    {
        codeList.push_back(element->getTyp());
    }
    else
    {
        Q_ASSERT(false);
    }

    if(element->getIsRef())
    {
        codeList.push_back(CodegeneratorConstants::reference);
    }

    if(element->getIsPointer())
    {
        codeList.push_back(CodegeneratorConstants::pointer);
    }
    if(element->getIsMemoryConstant())
    {
       codeList.push_back(CodegeneratorConstants::tab);
       codeList.push_back(CodegeneratorConstants::constant);
    }
}


void FuctionCodeGenerator::setTyp(std::list<QString>& codeList,AttributeElements* element)
{

        if(element->getTyp() != "")
        {
            codeList.push_back(element->getTyp());
        }
        else
        {
            Q_ASSERT(false);
        }

        if(element->getIsRef())
        {
            codeList.push_back(CodegeneratorConstants::reference);
        }

        if(element->getIsPointer())
        {
            codeList.push_back(CodegeneratorConstants::pointer);
        }
}


}

