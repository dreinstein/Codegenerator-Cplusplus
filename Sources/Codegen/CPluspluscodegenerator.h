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
    virtual ~CPlusPlusCodegenerator();
    void generate(CodegeneratorImpl* _impl);
    void generate(std::vector<QString> strVecScript, std::map<QString,QString> strMapRules);
    void registerObservers(BaseGenerator *observer);
};

}

#endif // CPLUSPLUSCODEGENERATOR_H
