#ifndef BASECODEGENERATOR_H
#define BASECODEGENERATOR_H


#include <vector>
#include <map>
#include <QString>
#include "Codegeneratorimpl.h"
#include "Base/BaseGenerator.h"



using namespace NGenerator;

namespace Codegenerator
{

class BaseCodegenerator
{
public:
  //  BaseCodegenerator();
    virtual ~BaseCodegenerator(){;};
    virtual void generate(std::vector<QString> strVecScript, std::map<QString,QString> strMapRules) = 0;
    virtual void generate(CodegeneratorImpl* _impl) = 0;
    virtual void registerObservers(BaseGenerator *){;};
protected:
    std::vector<BaseGenerator*> codegeratorObservers;
    CodegeneratorImpl* impl = nullptr;

    BaseCodegenerator *getClassForNextElement(QString index);
};

}

#endif // BASECODEGENERATOR_H
