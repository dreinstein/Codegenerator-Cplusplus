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
    void generate();
    void generate(std::vector<QString> strVecScript, std::map<QString,QString> strMapRules,std::vector<QString> strVecKeys);
    const QString MODIFIER = "modifier";
private:
    const QString tab = "   ";
};

}

#endif // ATTRIBUTE_H
