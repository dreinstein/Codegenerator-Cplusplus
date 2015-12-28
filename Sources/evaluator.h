#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "BaseEvaluator.h"
#include <string>

namespace NGenerator
{

class ScriptEvaluator:public BaseEvaluator
{
private:
    std::string extractString(std::string ostring);
    bool findScriptentryInKeyword(std::string entry,std::vector<std::string> vkeywords);
    const std::string SEPERATOR = "::";
public:
    ScriptEvaluator();
    virtual ~ScriptEvaluator();
    bool evaluate(std::vector<std::string> vkeywords, std::vector<std::string> vscript);
    bool evaluate();
};

}


#endif // EVALUATOR_H
