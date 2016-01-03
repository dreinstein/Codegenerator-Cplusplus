#ifndef BASECODEGENERATOR_H
#define BASECODEGENERATOR_H


#include <vector>
#include <QString>
#include "Base/BaseGenerator.h"

using namespace NGenerator;

namespace Codegenerator
{

class BaseCodegenerator
{
public:
  //  BaseCodegenerator();
    virtual ~BaseCodegenerator(){;};
    virtual void generate(std::vector<QString> strVecScript) = 0;
    virtual void registerObservers(BaseGenerator *observer)=0;
protected:
    std::vector<BaseGenerator*> codegeratorObservers;
};

}

#endif // BASECODEGENERATOR_H
