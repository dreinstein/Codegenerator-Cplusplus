#ifndef KEYWORDCHECKER_H
#define KEYWORDCHECKER_H

#include "Base/baseKeywordChecker.h"

namespace NGenerator
{

class KeywordChecker : public BaseKeywordChecker
{
public:
    KeywordChecker();
    bool checkKeywords(QString &additionaInfo);
};

}

#endif // KEYWORDCHECKER_H
