#ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>
#include <QStringList>

namespace General
{

class Languages
{
public:
    enum class Parserlanguage
    {
        CPLUSPLUS,
        Java,
        others
    };
};

class Types
{
public:
    enum class DataTypes
    {
        Map,
        Vector
    };
};

class ParserId
{
public:
    enum class Id
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
    static QString SourceFileName;
    static QString HeaderFileName;
};



// Todo create seperate File for Class Extract String, perhaps give it other name
class ExtractString
{
private:
    static QString STRINGSEPERATOR;
    static QString SUBSTRINGSEPERATOR;
    static QString PARAMETERSEPERATOR;
public:
    static QString extractFirst(QString ostring);
    static QString extractLast(QString ostring);
    static QStringList extractStringList(QString ostring);
    static QString extractParameter(QString ostring);
};





}
#endif // UTILITIES_H
