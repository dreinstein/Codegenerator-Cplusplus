#ifndef GENERATORCPLUSPLUS
#define GENERATORCPLUSPLUS


#include <vector>
#include <string>

#include "Generator.h"

class ParserFassade;


class GeneratorCPlusPlus:public BaseGenerator
{
public:
    GeneratorCPlusPlus();
    virtual ~GeneratorCPlusPlus();
    void generate();
    void receiveData(std::vector<std::string> strv,int parserId);
    void notify(int id);
private:
    ParserFassade *pFassade=nullptr;
    bool isNotificated=false;
};

#endif // GeneratorCPlusPlus



