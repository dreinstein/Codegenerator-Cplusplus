
#include "Utilities.h"

using namespace General;

QString General::FilePath::RulesCPlusPlus = "..\\Files\\Rules";
QString General::FilePath::KeywordsCPlusPlus = "..\\Files\\Keywords\\myFirstKeywords.txt";
QString General::FilePath::SourceFileName = "..\\Files\\Generated\\SourceFile.cpp";
QString General::FilePath::HeaderFileName = "..\\Files\\Generated\\HeaderFile.cpp";
QString General::ExtractString::STRINGSEPERATOR = "@";
QString General::ExtractString::SUBSTRINGSEPERATOR = "::";
QString General::ExtractString::PARAMETERSEPERATOR = "@parameter";



// extract from String first before spearator
// eg. @Name::myFunctionName   seperator is "::"
// return Name
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
        ostring.remove(static_cast<int>(foundSeperator),static_cast<int>(ostring.length()));
    }
    return ostring;
}


// extract from String last before spearator
// eg. @Name::myFunctionName   seperator is "::"
// return myFunctionName
QString ExtractString::extractLast(QString ostring)
{
    std::size_t foundSeperator =  UINT_MAX;
    // find seperator
    foundSeperator = ostring.indexOf(SUBSTRINGSEPERATOR);
    // earse after seperator
    if (foundSeperator  < UINT_MAX)
    {
        ostring.remove(0,static_cast<int>(foundSeperator+2));
    }
    return ostring;
}

// extract Parameters
// e.g @function::functionwithOneParameter@modifier::public@typ::double@parameter::parameter1@typ::double
// to @typ::double
QString ExtractString::extractParameter(QString ostring)
{
    std::size_t foundSeperator =  UINT_MAX;
    // find seperator "parameter" and remove
    foundSeperator = ostring.indexOf(PARAMETERSEPERATOR);
    if (foundSeperator  < UINT_MAX)
    {
        ostring.remove(0,static_cast<int>(foundSeperator));
    }
    // remove first @
    ostring.remove(0,1);
    foundSeperator = ostring.indexOf(STRINGSEPERATOR);
    // goto next @
    if (foundSeperator  < UINT_MAX)
    {
        ostring.remove(0,static_cast<int>(foundSeperator));
    }
    return ostring;
}



// extract List of Strings out
// return QStringList
// eg.@modifier::privat@typ::int@attribute::myfirstAttribute
// returnValue StringList
// ListString with 3 elements:
// [1] @modifier::private
// [2] @typ::int
// [3] @attribute::myfirstAttribute
QStringList ExtractString::extractStringList(QString ostring)
{
    QStringList outStringList;
    std::size_t foundSeperator =  UINT_MAX;
    QString iString = ostring;
    foundSeperator = ostring.indexOf(STRINGSEPERATOR,1);
    while(foundSeperator < UINT_MAX)
    {
        iString = ostring;
        iString.remove(static_cast<int>(foundSeperator),ostring.length());
        outStringList << iString;
        ostring.remove(0,static_cast<int>(foundSeperator));
        foundSeperator =  UINT_MAX;
        foundSeperator = ostring.indexOf(STRINGSEPERATOR,1);
    };
    outStringList << ostring;
    return outStringList;
}

