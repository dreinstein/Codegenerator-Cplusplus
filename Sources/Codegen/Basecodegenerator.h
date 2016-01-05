#ifndef BASECODEGENERATOR_H
#define BASECODEGENERATOR_H


#include <vector>
#include <map>
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
    virtual void generate(std::vector<QString> strVecScript, std::vector<QString> strVecKeywords, std::map<QString,QString> strMapRules) = 0;
    virtual void registerObservers(BaseGenerator *observer)=0;
protected:
    std::vector<BaseGenerator*> codegeratorObservers;
};

}

#endif // BASECODEGENERATOR_H
