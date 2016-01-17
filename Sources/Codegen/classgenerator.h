#ifndef CLASSGENERATOR_H
#define CLASSGENERATOR_H

#include "Basecodegenerator.h"

namespace Codegenerator
{


class ClassGenerator : public BaseCodegenerator
{
public:
    ClassGenerator();
    ClassGenerator(const BaseCodegenerator *r){BaseCodegenerator::clone(r);}
    virtual ~ClassGenerator();
    void generate();
    void generate(std::vector<QString> strVecScript, std::map<QString,QString> strMapRules);
};


}

#endif // CLASSGENERATOR_H
