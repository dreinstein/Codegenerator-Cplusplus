#ifndef CLASSGENERATOR_H
#define CLASSGENERATOR_H

#include "Basecodegenerator.h"

namespace Codegenerator
{


class ClassGenerator : public BaseCodegenerator
{
public:
    ClassGenerator();
    void generate(CodegeneratorImpl* _impl);
    void generate(std::vector<QString> strVecScript, std::map<QString,QString> strMapRules);
};


}

#endif // CLASSGENERATOR_H
