#ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>
#include <QStringList>

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
    static QString RulesCPlusPlus;
    static QString KeywordsCPlusPlus;
};


class ExtractString
{
private:
    static QString STRINGSEPERATOR;
    static QString SUBSTRINGSEPERATOR;
public:
    static QString extractFirst(QString ostring);
    static QString extractLast(QString ostring);
    static QStringList extractStringList(QString ostring);
};




}
#endif // UTILITIES_H
