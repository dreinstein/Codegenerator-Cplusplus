#ifndef MOCKCPLUSPLUSCODEGENERATOR_H
#define MOCKCPLUSPLUSCODEGENERATOR_H


#include "Base/BaseGenerator.h"
#include "Utilities.h"
using namespace NGenerator;

class MockCPlusPlusCodegenerator:public BaseGenerator
{
public:
    MockCPlusPlusCodegenerator();
    virtual ~MockCPlusPlusCodegenerator();
    void generate();
    void receiveData(const std::vector<QString> strv,const General::ParserId::Id parserId);
    void receiveData(const std::map<QString,QString> strv,const General::ParserId::Id parserId);
    void notifyDatasGenerated(const General::ParserId::Id id)const;
   // void notifyCodeGenerated();
    std::vector<QString> getKeywords() const {return keywords;}
    std::map<QString,QString> getRules() const  {return rules;}
    std::vector<QString> getScripts() const {return script;}
     bool areAllDatasReceived();
     void notifyCodeGenerated() const {;}
     void receiveCode(const std::list<QString> strHeader,const std::list<QString> strSources) override final;
protected:
    void allDatasReceived()const;
private:
    std::unique_ptr<ParserFassade> pParserFassade;
    std::unique_ptr<CodegeneratorFassade> pCodegeneratorFassade;
    std::unique_ptr<BaseEvaluator> pEvaluator;

    bool keywordsReceived = false;
    bool rulesReceived = false;
    bool scriptReceived = false;

};

#endif // MOCKCPLUSPLUSCODEGENERATOR_H
