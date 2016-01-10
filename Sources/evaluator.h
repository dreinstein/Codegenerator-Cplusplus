#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Base/BaseEvaluator.h"
#include <QString>

namespace NGenerator
{

class ScriptEvaluator:public BaseEvaluator
{
private:
    //QString extractString(QString ostring);
    bool findScriptentryInKeyword(QString entry,std::vector<QString> vkeywords);
   // const QString SEPERATOR = "::";
public:
    ScriptEvaluator();
    virtual ~ScriptEvaluator();
    bool evaluate(std::vector<QString> vkeywords, std::vector<QString> vscript);
    bool evaluate();
};

}


#endif // EVALUATOR_H
