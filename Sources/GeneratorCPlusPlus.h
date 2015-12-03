#ifndef GENERATORCPLUSPLUS
#define GENERATORCPLUSPLUS


#include <vector>
#include <string>

#include "BaseGenerator.h"



namespace NGenerator
{

class GeneratorCPlusPlus:public BaseGenerator
{
public:
    GeneratorCPlusPlus();
    virtual ~GeneratorCPlusPlus();
    void generate();
    void receiveData(std::vector<std::string> strv,int parserId);
    void notify(int id);
};

}


#endif // GeneratorCPlusPlus



