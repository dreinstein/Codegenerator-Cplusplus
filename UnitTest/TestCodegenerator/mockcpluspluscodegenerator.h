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
    void notify(const General::ParserId::Id id)const;
   // void notifyCodeGenerated();
    std::vector<QString> getKeywords(){return keywords;}
    std::map<QString,QString> getRules() {return rules;}
    std::vector<QString> getScripts() {return script;}
     bool areAllDatasReceived();
     void notifyCodeGenerated() const {;}
protected:
    void allDatasReceived()const;
private:
    bool keywordsReceived = false;
    bool rulesReceived = false;
    bool scriptReceived = false;
};

#endif // MOCKCPLUSPLUSCODEGENERATOR_H
