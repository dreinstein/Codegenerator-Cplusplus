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
    void generate(std::vector<std::string> strVecScript);
private:
    void buildForCPlusPlus(BaseGenerator* generator);
    BaseCodegenerator* pCodeGenerator = nullptr;
};

#endif // CODEGENERATORFASSADE_H
