#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <list>
#include "Basecodegenerator.h"
#include "QString"
#include "Attributeelements.h"


namespace Codegenerator
{

class Attribute : public BaseCodegenerator
{
public:
    Attribute(); 
    Attribute(const BaseCodegenerator *r){BaseCodegenerator::clone(r);}
    virtual ~Attribute();
    void generate() override final;
    void generate(const std::vector<QString> strVecScript, const std::map<QString,QString> strMapRules,const std::vector<QString> strVecKeys) override final;
private:
    void generateHeaderList(AttributeElements* element, std::list<QString>::iterator iterator, bool foundModifier);
    void generateHeader(AttributeElements* element);
};

}

#endif // ATTRIBUTE_H
