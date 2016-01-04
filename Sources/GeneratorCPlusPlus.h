#ifndef GENERATORCPLUSPLUS
#define GENERATORCPLUSPLUS


#include <vector>
#include <map>
#include <QString>
#include "Base/BaseGenerator.h"



#include <QObject>

namespace NGenerator
{


class GeneratorCPlusPlus:public BaseGenerator
{

public:
    GeneratorCPlusPlus(QString str);
    virtual ~GeneratorCPlusPlus();
    void generate();
    void receiveData(std::vector<QString> strv,int parserId);
    void receiveData(std::map<QString,QString> strv,int parserId);
    void notify(int id);
    void notifyCodeGenerated();
    std::vector<QString> getKeywords(){return keywords;}
    std::vector<QString> getRules() {return rules;}
    std::vector<QString> getScripts() {return script;}
protected:
    void allDatasReceived();
    bool areAllDatasReceived();
private:
    GeneratorCPlusPlus();
    bool keywordsReceived = false;
    bool rulesReceived = false;
    bool scriptReceived = false;
};

}


#endif // GeneratorCPlusPlus



