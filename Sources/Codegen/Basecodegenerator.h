#ifndef BASECODEGENERATOR_H
#define BASECODEGENERATOR_H


#include <vector>
#include <map>
#include <QString>
#include <QFile>
#include "Base/BaseGenerator.h"



using namespace NGenerator;

namespace Codegenerator
{

class BaseCodegenerator
{
public:
    BaseCodegenerator();
    virtual ~BaseCodegenerator(){;}
    virtual void generate(std::vector<QString> strVecScript, std::map<QString,QString> strMapRules,std::vector<QString> strVecKeys) = 0;
    virtual void generate()=0;
    virtual void registerObservers(BaseGenerator *){;}
protected:
    std::vector<QString> script;
    std::vector<QString> keys;
    std::map<QString,QString> rules;
    std::vector<BaseGenerator*> codegeratorObservers;
    void openFiles();
    void generateDefault();
    void clone(const BaseCodegenerator *toClone);
    void nextElement();
    void setFilenames();
    unsigned int index;
    QString sourcefilename;
    QString heaterfilename;
private:
    BaseCodegenerator *getClass(QString index);
};

}

#endif // BASECODEGENERATOR_H
