#ifndef BASEEVALUATOR
#define BASEEVALUATOR

#include "vector"
#include "string"

class BaseEvaluator
{
public:
    virtual ~BaseEvaluator(){;};
    virtual bool evaluate(std::vector<std::string> vkeywords, std::vector<std::string> vscript)=0;
};


#endif // BASEEVALUATOR

