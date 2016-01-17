#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "Basecodegenerator.h"

namespace Codegenerator
{

class Attribute : public BaseCodegenerator
{
public:
    Attribute();
    Attribute(const BaseCodegenerator *r){BaseCodegenerator::clone(r);}
    ~Attribute();
    void generate();
    void generate(std::vector<QString> strVecScript, std::map<QString,QString> strMapRules);
};

}

#endif // ATTRIBUTE_H
