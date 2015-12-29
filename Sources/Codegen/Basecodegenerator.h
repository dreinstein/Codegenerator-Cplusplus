#ifndef BASECODEGENERATOR_H
#define BASECODEGENERATOR_H


#include <vector>
#include "Base/BaseGenerator.h"

using namespace NGenerator;

namespace Codegenerator
{

class BaseCodegenerator
{
public:
  //  BaseCodegenerator();
    virtual ~BaseCodegenerator(){;};
    virtual void generate() = 0;
    virtual void registerObservers(BaseGenerator *observer)=0;
protected:
    std::vector<BaseGenerator*> codegeratorObservers;
};

}

#endif // BASECODEGENERATOR_H
