
#include "Utilities.h"

using namespace General;

QString General::FilePath::RulesCPlusPlus = "c:\\Codegenerator\\Rules";
QString General::FilePath::KeywordsCPlusPlus = "c:\\Codegenerator\\Keywords\\myFirstKeywords.txt";
QString General::FilePath::SourceFileName = "c:\\Codegenerator\\UnitTest\\Files\\Generated\\SourceFile.cpp";
QString General::FilePath::HeaderFileName = "c:\\Codegenerator\\UnitTest\\Files\\Generated\\HeaderFile.cpp";
QString General::ExtractString::STRINGSEPERATOR = "@";
QString General::ExtractString::SUBSTRINGSEPERATOR = "::";
QString General::ExtractString::PARAMETERSEPERATOR = "@parameter";



QString ExtractString::extractFirst(QString ostring)
{
    // get rid of @
    ostring.remove(0,1);
    std::size_t foundSeperator =  UINT_MAX;
    // find seperator
    foundSeperator = ostring.indexOf(SUBSTRINGSEPERATOR);
    // earse after seperator
    if (foundSeperator  < UINT_MAX)
    {
        ostring.remove(foundSeperator,ostring.length());
    }
    return ostring;
}



QString ExtractString::extractLast(QString ostring)
{
    std::size_t foundSeperator =  UINT_MAX;
    // find seperator
    foundSeperator = ostring.indexOf(SUBSTRINGSEPERATOR);
    // earse after seperator
    if (foundSeperator  < UINT_MAX)
    {
        ostring.remove(0,foundSeperator+2);
    }
    return ostring;
}

QString ExtractString::extractParameter(QString ostring)
{
    std::size_t foundSeperator =  UINT_MAX;
    // find seperator
    foundSeperator = ostring.indexOf(PARAMETERSEPERATOR);
    if (foundSeperator  < UINT_MAX)
    {
        ostring.remove(0,foundSeperator+2);
    }
    return ostring;
}


QStringList ExtractString::extractStringList(QString ostring)
{
    QStringList outStringList;
    std::size_t foundSeperator =  UINT_MAX;
    QString iString = ostring;
    foundSeperator = ostring.indexOf(STRINGSEPERATOR,1);
    while(foundSeperator < UINT_MAX)
    {
        iString = ostring;
        iString.remove(foundSeperator,ostring.length());
        outStringList << iString;
        ostring.remove(0,foundSeperator);
        foundSeperator =  UINT_MAX;
        foundSeperator = ostring.indexOf(STRINGSEPERATOR,1);
    };
    outStringList << ostring;
    return outStringList;
}

