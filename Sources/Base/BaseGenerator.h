#ifndef GENERATOR
#define GENERATOR


#include <vector>
#include <map>
#include <functional>


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
    virtual void generate() =0;
    virtual void receiveData(const std::vector<QString> strv,const General::ParserId::Id parserId)=0;
    virtual void receiveData(const std::map<QString,QString> strv,const General::ParserId::Id parserId)=0;
    virtual void notify(const General::ParserId::Id id) const =0;
    virtual void notifyCodeGenerated() const =0;
    virtual std::vector<QString> getKeywords()=0;
    virtual std::map<QString,QString> getRules()=0;
    virtual std::vector<QString> getScripts()=0;
    virtual bool areAllDatasReceived()=0;


protected:
    virtual void allDatasReceived() const =0;
    std::vector<QString> keywords;
    std::map<QString,QString> rules;
    std::vector<QString> script;
    ParserFassade *pParserFassade=nullptr;
    CodegeneratorFassade *pCodegeneratorFassade = nullptr;
    BaseEvaluator *pEvaluator=nullptr;
    QString pathScript;
 //   virtual void receiveData() const;

};
}

#endif // GENERATOR

