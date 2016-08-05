#ifndef CODEGENERATORFASSADE_H
#define CODEGENERATORFASSADE_H


#include <vector>

#include "Utilities.h"
#include "Base\BaseGenerator.h"
#include "Codegen/Basecodegenerator.h"
#include "memory"


using namespace General;
using namespace NGenerator;
using namespace Codegenerator;

class CodegeneratorFassade
{
public:
    CodegeneratorFassade(BaseGenerator* generator,Languages::Parserlanguage lang);
    ~CodegeneratorFassade();
    void generate(const std::vector<QString> strVecScript, const std::map<QString,QString> strMapRules,const std::vector<QString> strVecKeys);
private:
    void buildForCPlusPlus(BaseGenerator* generator);
    std::unique_ptr<BaseCodegenerator> pCodeGenerator;
};

#endif // CODEGENERATORFASSADE_H
