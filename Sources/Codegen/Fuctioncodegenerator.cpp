#include "Fuctioncodegenerator.h"


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
    Codegenerator::FunctionElements *elements = new Codegenerator::FunctionElements();
    elements->setElements(script[this->index]);

   /*
    // we expect as first a modifier, if not throw Error
    if(attributeElements->getModifierKeyword()!= MODIFIER)
    {
        throw Errorhandling::AttributeScriptException();
    }*/

    generateHeaderList(elements);
    generateSourceList(elements);
    delete elements;
    nextElement();
}

void FuctionCodeGenerator::generate(const std::vector<QString>, const std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}

void FuctionCodeGenerator::generateHeaderList(FunctionElements* elements)
{

}

void FuctionCodeGenerator::generateSourceList(FunctionElements* elements)
{

}

}


