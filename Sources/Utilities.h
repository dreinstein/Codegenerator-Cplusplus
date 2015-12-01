#ifndef UTILITIES_H
#define UTILITIES_H

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





}
#endif // UTILITIES_H
