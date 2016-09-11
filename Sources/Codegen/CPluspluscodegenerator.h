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
    CPlusPlusCodegenerator(){;}
    CPlusPlusCodegenerator(const BaseCodegenerator *r){BaseCodegenerator::clone(r);}
    virtual ~CPlusPlusCodegenerator(){;}
    void generate() override final;
    void generate(const std::vector<QString> strVecScript, const std::map<QString,QString> strMapRules,const std::vector<QString> strVecKeys)override final;
    void registerObservers(BaseGenerator *observer);
private:
    void createHeaderFile();
    void createSourceFile();
};

}

#endif // CPLUSPLUSCODEGENERATOR_H
