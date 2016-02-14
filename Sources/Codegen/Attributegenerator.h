#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "Basecodegenerator.h"
#include "QString"

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
    const QString MODIFIER = "modifier";
private:
    const QString tab = "   ";
};

}

#endif // ATTRIBUTE_H
