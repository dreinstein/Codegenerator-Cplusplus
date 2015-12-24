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

bool ScriptEvaluator::evaluate(std::vector<std::string> vkeywords, std::vector<std::string> vscript)
{
    string scriptentry = "noVal";
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

bool ScriptEvaluator::findScriptentryInKeyword(std::string entry,std::vector<std::string> vkeywords)
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


std::string ScriptEvaluator::extractString(std::string ostring)
{
    // get rid of @
    ostring.erase (0,1);
    std::size_t foundSeperator =  UINT_MAX;
    // find seperator
    foundSeperator = ostring.find(SEPERATOR);
    // earse after seperator
    if (foundSeperator  < UINT_MAX)
    {
        ostring.erase(foundSeperator,ostring.length());
    }
    return ostring;
}

}


