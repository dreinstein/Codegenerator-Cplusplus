#ifndef BASEKEYWORKCHECKER_H
#define BASEKEYWORKCHECKER_H

#include <QString>

namespace NGenerator
{

class BaseKeywordChecker
{
public:
    virtual ~BaseKeywordChecker(){;};
    virtual bool checkKeywords(QString &additionaInfo)=0;
};

}

#endif // BASEKEYWORKCHECKER_H
