#ifndef GENERATORCPLUSPLUS
#define GENERATORCPLUSPLUS


#include <vector>
#include <map>
#include <QString>
#include "Base/BaseGenerator.h"
#include "Utilities.h"



#include <QObject>

namespace NGenerator
{


class GeneratorCPlusPlus:public BaseGenerator
{

public:
    GeneratorCPlusPlus(QString str);
    virtual ~GeneratorCPlusPlus();
    void generate();
    void receiveData(std::vector<QString> strv,General::ParserId::Id parserId);
    void receiveData(std::map<QString,QString> strv,General::ParserId::Id parserId);
    void notify(General::ParserId::Id id);
    void notifyCodeGenerated();
    std::vector<QString> getKeywords(){return keywords;}
    std::map<QString,QString> getRules() {return rules;}
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



