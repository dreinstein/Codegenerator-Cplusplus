#ifndef KEYWORDCHECKER_H
#define KEYWORDCHECKER_H

#include "Base/baseKeywordChecker.h"

namespace NGenerator
{

class KeywordChecker : public BaseKeywordChecker
{
public:
    KeywordChecker();
    bool checkKeywords(std::string &additionaInfo);
};

}

#endif // KEYWORDCHECKER_H
