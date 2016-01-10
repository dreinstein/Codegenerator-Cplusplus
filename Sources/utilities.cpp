
#include "Utilities.h"

using namespace General;

QString General::FilePath::RulesCPlusPlus = "c:\\Codegenerator\\Rules";
QString General::FilePath::KeywordsCPlusPlus = "c:\\Codegenerator\\Keywords\\myFirstKeywords.txt";
QString General::ExtractString::SEPERATOR = "::";


QString ExtractString::extractFirst(QString ostring)
{
    // get rid of @
    ostring.remove(0,1);
    std::size_t foundSeperator =  UINT_MAX;
    // find seperator
    foundSeperator = ostring.indexOf(SEPERATOR);
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
    foundSeperator = ostring.indexOf(SEPERATOR);
    // earse after seperator
    if (foundSeperator  < UINT_MAX)
    {
        ostring.remove(0,foundSeperator+2);
    }
    return ostring;
}
