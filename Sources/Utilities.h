#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

namespace General
{

class Languages
{
public:
    enum Parserlanguage
    {
        CPLUSPLUS,
        Java,
        others
    };

};

class Types
{
public:
    enum DataTypes
    {
        Map,
        Vector
    };
};

class ParserId
{
public:
    enum Id
    {
        Keyword = 1,
        Rules   = 2,
        Script  = 3
    };
};


class FilePath
{
public:
    static std::string RulesCPlusPlus;
    static std::string KeywordsCPlusPlus;
};




}
#endif // UTILITIES_H
