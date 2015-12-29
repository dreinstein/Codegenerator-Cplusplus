#include <QtGlobal>
#include "Codegeneratorfassade.h"
#include "Base/BaseGenerator.h"
#include "Codegen/Basecodegenerator.h"
#include "Codegen/CPluspluscodegenerator.h"
#include "Utilities.h"
#include "Codegen/Cpluspluscodegenerator.h"


using namespace General;
using namespace Codegenerator;
using namespace NGenerator;
using namespace Codegenerator;


CodegeneratorFassade::CodegeneratorFassade(BaseGenerator* generator,Languages::Parserlanguage lang)
{
    switch (lang)
    {
        case Languages::CPLUSPLUS:
            buildForCPlusPlus(generator);
        break;
        default:
            Q_ASSERT(true);
    }
}

CodegeneratorFassade::~CodegeneratorFassade()
{
    delete pCodeGenerator;
}


void CodegeneratorFassade::generate()
{
    Q_ASSERT(pCodeGenerator);
    pCodeGenerator->generate();
}

void CodegeneratorFassade::buildForCPlusPlus(BaseGenerator* generator)
{
   pCodeGenerator = new CPlusPlusCodegenerator();
   pCodeGenerator->registerObservers(generator);
}
