#ifndef BASEEVALUATOR
#define BASEEVALUATOR

#include "vector"
#include <QString>

class BaseEvaluator
{
public:
    virtual ~BaseEvaluator(){;};
    virtual bool evaluate(std::vector<QString> vkeywords, std::vector<QString> vscript)=0;
};


#endif // BASEEVALUATOR

