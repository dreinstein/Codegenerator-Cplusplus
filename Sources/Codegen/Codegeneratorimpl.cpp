#include <QTextStream>
#include "Codegeneratorimpl.h"
#include "../Sources/Utilities.h"
#include "../Sources/Codegen/CPluspluscodegenerator.h"
#include "../Errorhandling/OpenfileException.h"



using namespace Errorhandling;

namespace Codegenerator
{


CodegeneratorImpl::CodegeneratorImpl(std::vector<QString>vecScript,std::map<QString,QString> mapRules,QString fPath)
{
    script = vecScript;
    rules = mapRules;
    // @Todo h und cpp should be configurable
    QString hFilename = fPath + ".h";
    QString cFilename = fPath + ".cpp";
    heatherFile.setFileName(hFilename);
    sourceFile.setFileName(cFilename);
    index = 1;
}

CodegeneratorImpl::~CodegeneratorImpl()
{
    heatherFile.close();
    sourceFile.close();
}

void CodegeneratorImpl::generateCodeFiles()
{
    if(!heatherFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        throw OpenFileException();
    }
    if(!sourceFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        throw OpenFileException();
    }
}


void CodegeneratorImpl::write()
{
    QString scriptelement=" ";
    QString scriptelementFirst= " ";
    QString scriptelementLast= " ";
    QString mapValue = " ";

    QTextStream outh(&heatherFile);
    QTextStream outs(&sourceFile);

    QString row;
    scriptelement = script[index];
    scriptelementFirst = General::ExtractString::extractFirst(scriptelement);
    scriptelementLast = General::ExtractString::extractLast(scriptelement);
    mapValue = rules[scriptelementFirst];

    if(mapValue!= "")
    {
        QFile ruleFile(mapValue);
        if(ruleFile.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QTextStream in(&ruleFile);
            while (!in.atEnd())
            {
                row = in.readLine();
                if (row.contains(scriptelementFirst))
                {
                    outh << scriptelementFirst;
                    if(scriptelementLast != "")
                    {
                        outh << " ";
                        outh << scriptelementLast;
                    }
                    else
                    {
                        outh << row << "\n";
                    }
                }
                else
                {
                    outh << row << "\n";
                }
            }// while

        } //if
        else
        {
            throw OpenFileException();
        }
   }
   outh << '\n';
}

}
