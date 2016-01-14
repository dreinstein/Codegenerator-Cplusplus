#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "Basecodegenerator.h"

namespace Codegenerator
{

class Attribute : public BaseCodegenerator
{
public:
    Attribute();
    ~Attribute();
    void generate(CodegeneratorImpl* _impl);
    void generate(std::vector<QString> strVecScript, std::map<QString,QString> strMapRules);
};

}

#endif // ATTRIBUTE_H
