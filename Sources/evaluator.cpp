#include "Evaluator.h"
#include <vector>

using namespace std;

namespace NGenerator
{

ScriptEvaluator::ScriptEvaluator()
{

}

ScriptEvaluator::~ScriptEvaluator()
{

}

bool ScriptEvaluator::evaluate(std::vector<QString> vkeywords, std::vector<QString> vscript)
{
    QString scriptentry = "noVal";
    bool found = false;
    for (auto itscript = vscript.begin(); itscript != vscript.end(); ++itscript)
    {
        scriptentry = extractString(*itscript);
        found = findScriptentryInKeyword(scriptentry,vkeywords);
        if (found == false)
        {
            return false;
        }
    }
    return true;
}

bool ScriptEvaluator::findScriptentryInKeyword(QString entry,std::vector<QString> vkeywords)
{

    bool found = false;
    for (auto itkeywords = vkeywords.begin(); itkeywords != vkeywords.end(); ++itkeywords)
    {
        if(*itkeywords == entry)
        {
            found = true;
            break;
        }
    }
    if (found == false)
    {
        return false;
    }
    return true;
}


QString ScriptEvaluator::extractString(QString ostring)
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

}


