#ifndef BASECODEGENERATOR_H
#define BASECODEGENERATOR_H


#include <vector>
#include <list>
#include <map>
#include <list>
#include <QString>
#include <QFile>
#include <functional>
#include "Base/BaseGenerator.h"
#include "Functionelements.h"
#include "Attributeelements.h"
#include <memory>


using namespace NGenerator;

namespace Codegenerator
{

class BaseCodegenerator
{
public:
    BaseCodegenerator();
    virtual ~BaseCodegenerator();
    virtual void generate(const std::vector<QString> strVecScript, const std::map<QString,QString> strMapRules,const std::vector<QString> strVecKeys) = 0;
    virtual void generate();
    virtual void registerObservers(BaseGenerator*) {;}
    virtual std::list<QString> getHeaderListData() const final {return generatedCodeHeader;}
    virtual std::list<QString> getSourceListData() const final {return generatedCodeSource;}
protected:
    std::vector<QString> script;
    std::vector<QString> keys;
    std::map<QString,QString> rules;
    std::vector<BaseGenerator*> codegeratorObservers;
    std::unique_ptr<FunctionElements> functionElements;
    std::unique_ptr<AttributeElements> attributeElements;
    std::list<QString> generatedCodeHeader;
    std::list<QString> generatedCodeSource;
    QString classname;
    void openFiles();
    void clone(const BaseCodegenerator *toClone);
    void nextElement();
    void setFilenames();
    unsigned int index;
    QString sourcefilename;
    QString heaterfilename;
    bool hasElementModifier(QString elementModifier);
    std::list<QString>::iterator foundPositionToAppendToHeaderList(bool hasPublicModifier);
private:
    void getNextElement(BaseCodegenerator* &nextGenerator,QString sIndex);
    void generateHeader();
    void generateSource();
};

}

#endif // BASECODEGENERATOR_H
