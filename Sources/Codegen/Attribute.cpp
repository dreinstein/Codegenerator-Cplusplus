#include "Attribute.h"
#include "QFile"
#include <QTextStream>
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
    QFile hFile(heaterfilename);
    //QFile sFile(heaterfilename);

    // open Heaterfile
    if(!hFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        throw Errorhandling::OpenFileException();
    }

    QTextStream outh(&hFile);

    // 1. read modifier
    QString scriptelement = script[index];
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
    QString row;
    while (!outh.atEnd())
    {
        row = outh.readLine();
        if (row.contains("class"))
        {
            foundClass = true;
        }
        if(row.contains("{"))
        {
            foundBracket = true;
        }
        if(row.contains(modifier) && foundBracket && foundClass)
        {
            foundModifier = true;
            row = outh.readLine();
        }
        if((row.contains("}")) && foundBracket && foundClass)
        {
            if(!foundModifier)
            {
                outh << modifier;
                outh << ":";
                outh << "\n";
            }
            outh << typ;
            outh << " ";
            outh << attribute;
            outh << ";";
            outh << "\n";
            outh << "};";
        }
    }
    // if Class not found, then throw exeption
    if((false == foundClass) || (false == foundBracket ))
    {
        throw Errorhandling::FileNotValidException();
    }
    hFile.close();
  //  sFile.close();
}

void Attribute::generate(std::vector<QString>, std::map<QString,QString>,std::vector<QString>)
{
    Q_ASSERT(false);
}


}

