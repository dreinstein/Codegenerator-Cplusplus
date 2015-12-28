#ifndef GENERATORCPLUSPLUS
#define GENERATORCPLUSPLUS


#include <vector>
#include <string>
#include "BaseGenerator.h"



#include <QObject>

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
    std::vector<std::string> getKeywords(){return keywords;}
    std::vector<std::string> getRules() {return rules;}
    std::vector<std::string> getScripts() {return script;}
protected:
    void allDatasReceived();
    bool areAllDatasReceived();
private:

    bool keywordsReceived = false;
    bool rulesReceived = false;
    bool scriptReceived = false;
};

}


#endif // GeneratorCPlusPlus



