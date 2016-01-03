#ifndef GENERATOR
#define GENERATOR


#include <vector>


#include "BaseEvaluator.h"
class CodegeneratorFassade;
//class CodegeneratorFassade;
#include <QString>
class ParserFassade;

namespace NGenerator
{


class BaseGenerator
{
public:
    virtual ~BaseGenerator(){;};
    virtual void generate()=0;
    virtual void receiveData(std::vector<QString> strv,int parserId)=0;
    virtual void notify(int id)=0;
    virtual void notifyCodeGenerated()=0;
    virtual std::vector<QString> getKeywords()=0;
    virtual std::vector<QString> getRules()=0;
    virtual std::vector<QString> getScripts()=0;

protected:
    std::vector<QString> keywords;
    std::vector<QString> rules;
    std::vector<QString> script;
    ParserFassade *pParserFassade=nullptr;
    CodegeneratorFassade *pCodegeneratorFassade = nullptr;
    BaseEvaluator *pEvaluator=nullptr;
    QString pathScript;

    virtual bool areAllDatasReceived()=0;
    virtual void allDatasReceived()=0;

};
}

#endif // GENERATOR

