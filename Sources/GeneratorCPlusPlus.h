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
    void notifyDatasGenerated(const General::ParserId::Id id)const override final;
    void notifyCodeGenerated()const override final;
    std::vector<QString> getKeywords()const override final  {return keywords;}
    std::map<QString,QString> getRules() const override final {return rules;}
    std::vector<QString> getScripts() const override final {return script;}
    bool areAllDatasReceived() override final;
    void receiveCode(const std::list<QString>, const std::list<QString>) override final;
protected:
     virtual void allDatasReceived() const override final;
private:
    GeneratorCPlusPlus();
    bool keywordsReceived = false;
    bool rulesReceived = false;
    bool scriptReceived = false;
    std::unique_ptr<ParserFassade> pParserFassade;
    std::unique_ptr<CodegeneratorFassade> pCodegeneratorFassade;
    std::unique_ptr<BaseEvaluator> pEvaluator;
};

}


#endif // GeneratorCPlusPlus



