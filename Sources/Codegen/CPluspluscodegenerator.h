#ifndef CPLUSPLUSCODEGENERATOR_H
#define CPLUSPLUSCODEGENERATOR_H

#include <QFile>
#include "Codegen/Basecodegenerator.h"
#include "Base/BaseGenerator.h"


namespace Codegenerator
{

class CPlusPlusCodegenerator : public BaseCodegenerator
{
public:
    CPlusPlusCodegenerator();
    CPlusPlusCodegenerator(const BaseCodegenerator *r){BaseCodegenerator::clone(r);}
    virtual ~CPlusPlusCodegenerator();
    void generate();
    void generate(std::vector<QString> strVecScript, std::map<QString,QString> strMapRules,std::vector<QString> strVecKeys);
    void registerObservers(BaseGenerator *observer);
};

}

#endif // CPLUSPLUSCODEGENERATOR_H
