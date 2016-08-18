#ifndef CLASSGENERATOR_H
#define CLASSGENERATOR_H

#include "Basecodegenerator.h"

namespace Codegenerator
{


class ClassGenerator : public BaseCodegenerator
{
public:
    ClassGenerator(const BaseCodegenerator *r){BaseCodegenerator::clone(r);}
    virtual ~ClassGenerator();
    void generate() override final;
    void generate(const std::vector<QString> strVecScript, const std::map<QString,QString> strMapRules,const std::vector<QString> strVecKeys) override final;
private:
    ClassGenerator();
};

}

#endif // CLASSGENERATOR_H
