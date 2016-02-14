#include <algorithm>
#include "Attributegenerator.h"
#include "QFile"
#include "QTextStream"
#include "Utilities.h"
#include "../Errorhandling/OpenfileException.h"
#include "../Errorhandling/Attributescriptexception.h"
#include "../Errorhandling/FileNotvalidexception.h"


namespace Codegenerator
{


Attribute::Attribute()
{

}

Attribute::~Attribute()
{

}

void Attribute::generate()
{
    // 1. read modifier
    QString scriptelement = script[this->index];
    QStringList qlist = General::ExtractString::extractStringList(scriptelement);
    QString modifierKeyword = General::ExtractString::extractFirst(qlist[0]);
    QString modifier = General::ExtractString::extractLast(qlist[0]);
    QString typ = General::ExtractString::extractLast(qlist[1]);
    QString attribute = General::ExtractString::extractLast(qlist[2]);
    // we expect as first a modifier, if not throw Error
    if(modifierKeyword != MODIFIER)
    {
        throw Errorhandling::AttributeScriptException();
    }

    // find position in file
    // find class, row it the position
    bool foundClass = false;
    bool foundBracket = false;
    bool foundModifier = false;
    QString element;
    for(list<QString>::iterator iterator = generatedCodeHeader.begin();iterator != generatedCodeHeader.end(); ++iterator)
    {
        element = *iterator;
        if (element.contains("class"))
        {
            foundClass = true;
        }
        if(element.contains("{"))
        {
            foundBracket = true;
        }
        if(element.contains(modifier) && foundBracket && foundClass)
        {
            foundModifier = true;
        }
        if((element.contains("}")) && foundBracket && foundClass)
        {
            list<QString> templist;
            templist.splice(templist.begin(), generatedCodeHeader,iterator,generatedCodeHeader.end());
            if(!foundModifier)
            {
                // create modifier
                generatedCodeHeader.push_back(modifier);
                generatedCodeHeader.push_back(":");
                generatedCodeHeader.push_back("\n");
            }
            generatedCodeHeader.push_back(tab);
            generatedCodeHeader.push_back(typ);
            generatedCodeHeader.push_back(" ");
            generatedCodeHeader.push_back(attribute);
            generatedCodeHeader.push_back(";");
            generatedCodeHeader.push_back("\n");
            generatedCodeHeader.insert(generatedCodeHeader.end(), templist.begin(),templist.end());
            break;
        }
    }
    // if Class not found, then throw exeption
    if((false == foundClass) || (false == foundBracket ))
    {
        throw Errorhandling::FileNotValidException();
    }
    nextElement();
}

void Attribute::generate(const std::vector<QString>, const std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}


}

