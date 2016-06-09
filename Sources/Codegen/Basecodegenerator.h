#ifndef BASECODEGENERATOR_H
#define BASECODEGENERATOR_H


#include <vector>
#include <list>
#include <map>
#include <QString>
#include <QFile>
#include <functional>
#include "Base/BaseGenerator.h"
#include "Functionelements.h"


using namespace NGenerator;

namespace Codegenerator
{

class BaseCodegenerator
{
public:
    BaseCodegenerator();
    virtual ~BaseCodegenerator(){;}
    virtual void generate(const std::vector<QString> strVecScript, const std::map<QString,QString> strMapRules,const std::vector<QString> strVecKeys) = 0;
    virtual void generate() =0;
    virtual void registerObservers(BaseGenerator*) {;}
    virtual std::list<QString> getHeaderListData() const final {return generatedCodeHeader;}
    virtual std::list<QString> getSourceListData() const final {return generatedCodeSource;}
    virtual FunctionElements getFunctionElements() const final {return *functionElements;}
protected:
    std::vector<QString> script;
    std::vector<QString> keys;
    std::map<QString,QString> rules;
    std::vector<BaseGenerator*> codegeratorObservers;
    FunctionElements *functionElements = nullptr;
    std::list<QString> generatedCodeHeader;
    std::list<QString> generatedCodeSource;
    QString classname;
    void openFiles();
    void generateDefault();
    void clone(const BaseCodegenerator *toClone);
    void nextElement();
    void setFilenames();
    unsigned int index;
    QString sourcefilename;
    QString heaterfilename;


private:
    BaseCodegenerator *getNextElement(QString index);
};

}

#endif // BASECODEGENERATOR_H
