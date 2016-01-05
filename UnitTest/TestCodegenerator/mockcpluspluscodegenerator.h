#ifndef MOCKCPLUSPLUSCODEGENERATOR_H
#define MOCKCPLUSPLUSCODEGENERATOR_H


#include "Base/BaseGenerator.h"
using namespace NGenerator;

class MockCPlusPlusCodegenerator:public BaseGenerator
{
public:
    MockCPlusPlusCodegenerator();
    virtual ~MockCPlusPlusCodegenerator();
    void generate();
    void receiveData(std::vector<QString> strv,int parserId);
    void receiveData(std::map<QString,QString> strv,int parserId);
    void notify(int id);
   // void notifyCodeGenerated();
    std::vector<QString> getKeywords(){return keywords;}
    std::map<QString,QString> getRules() {return rules;}
    std::vector<QString> getScripts() {return script;}
     bool areAllDatasReceived();
     void notifyCodeGenerated(){;};
protected:
    void allDatasReceived();
private:
    bool keywordsReceived = false;
    bool rulesReceived = false;
    bool scriptReceived = false;
};

#endif // MOCKCPLUSPLUSCODEGENERATOR_H
