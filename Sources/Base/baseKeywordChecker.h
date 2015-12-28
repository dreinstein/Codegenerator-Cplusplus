#ifndef BASEKEYWORKCHECKER_H
#define BASEKEYWORKCHECKER_H

#include <string>

namespace NGenerator
{

class BaseKeywordChecker
{
public:
    virtual ~BaseKeywordChecker(){;};
    virtual bool checkKeywords(std::string &additionaInfo)=0;
};

}

#endif // BASEKEYWORKCHECKER_H
