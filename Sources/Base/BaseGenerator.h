#ifndef GENERATOR
#define GENERATOR


#include <vector>
#include <map>


#include "BaseEvaluator.h"
class CodegeneratorFassade;
//class CodegeneratorFassade;
#include <QString>
#include <Utilities.h>
class ParserFassade;

namespace NGenerator
{


class BaseGenerator
{
public:
    virtual ~BaseGenerator(){;}
    virtual void generate()=0;
    virtual void receiveData(std::vector<QString> strv,General::ParserId::Id parserId)=0;
    virtual void receiveData(std::map<QString,QString> strv,General::ParserId::Id parserId)=0;
    virtual void notify(General::ParserId::Id id)=0;
    virtual void notifyCodeGenerated()=0;
    virtual std::vector<QString> getKeywords()=0;
    virtual std::map<QString,QString> getRules()=0;
    virtual std::vector<QString> getScripts()=0;
    virtual bool areAllDatasReceived()=0;

protected:
    std::vector<QString> keywords;
    std::map<QString,QString> rules;
    std::vector<QString> script;
    ParserFassade *pParserFassade=nullptr;
    CodegeneratorFassade *pCodegeneratorFassade = nullptr;
    BaseEvaluator *pEvaluator=nullptr;
    QString pathScript;
    virtual void allDatasReceived()=0;

};
}

#endif // GENERATOR

