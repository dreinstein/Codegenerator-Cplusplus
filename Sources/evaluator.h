#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "BaseEvaluator.h"



class ScriptEvaluator:public BaseEvaluator
{
public:
    ScriptEvaluator();
    virtual ~ScriptEvaluator();
    bool evaluate(std::vector<std::string> vkeywords, std::vector<std::string> vscript);
    bool evaluate();
};


#endif // EVALUATOR_H
