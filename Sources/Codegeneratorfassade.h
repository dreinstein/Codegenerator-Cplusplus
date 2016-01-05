#ifndef CODEGENERATORFASSADE_H
#define CODEGENERATORFASSADE_H


#include <vector>

#include "Utilities.h"
#include "Base\BaseGenerator.h"
#include "Codegen/Basecodegenerator.h"


using namespace General;
using namespace NGenerator;
using namespace Codegenerator;

class CodegeneratorFassade
{
public:
    CodegeneratorFassade(BaseGenerator* generator,Languages::Parserlanguage lang);
    ~CodegeneratorFassade();
    void generate(std::vector<QString> strVecScript, std::vector<QString> strVecKeyWords, std::map<QString,QString> strMapRules);
private:
    void buildForCPlusPlus(BaseGenerator* generator);
    BaseCodegenerator* pCodeGenerator = nullptr;
};

#endif // CODEGENERATORFASSADE_H
