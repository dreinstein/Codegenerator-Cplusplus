#ifndef CPLUSPLUSCODEGENERATOR_H
#define CPLUSPLUSCODEGENERATOR_H

#include "Codegen/Basecodegenerator.h"
#include "Base/BaseGenerator.h"


namespace Codegenerator
{

class CPlusPlusCodegenerator : public BaseCodegenerator
{
public:
    CPlusPlusCodegenerator();
    virtual ~CPlusPlusCodegenerator();
    void generate(std::vector<QString> strVecScript);
    void registerObservers(BaseGenerator *observer);

};

}

#endif // CPLUSPLUSCODEGENERATOR_H
