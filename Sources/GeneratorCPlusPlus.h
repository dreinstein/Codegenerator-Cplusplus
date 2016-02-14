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
    void generate() override final;
    void receiveData(const std::vector<QString> strv,const General::ParserId::Id parserId) override final;
    void receiveData(const std::map<QString,QString> strv,const General::ParserId::Id parserId) override final;
    void notify(const General::ParserId::Id id)const override final;
    void notifyCodeGenerated()const override final;
    std::vector<QString> getKeywords()override final  {return keywords;}
    std::map<QString,QString> getRules() override final {return rules;}
    std::vector<QString> getScripts() override final {return script;}
     bool areAllDatasReceived() override final;
protected:
     virtual void allDatasReceived() const override final;
private:
    GeneratorCPlusPlus();
    bool keywordsReceived = false;
    bool rulesReceived = false;
    bool scriptReceived = false;
};

}


#endif // GeneratorCPlusPlus



