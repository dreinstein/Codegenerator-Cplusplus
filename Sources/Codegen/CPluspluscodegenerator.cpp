#include <QFile>
#include <QTextStream>
#include <iostream>
#include "CPluspluscodegenerator.h"
#include "Utilities.h"
#include "../Errorhandling/OpenfileException.h"
#include "../Errorhandling/Exceptionhandling.h"

using namespace Errorhandling;


namespace Codegenerator
{

CPlusPlusCodegenerator::CPlusPlusCodegenerator()
{
    scriptindex=0;
}


CPlusPlusCodegenerator::~CPlusPlusCodegenerator()
{

}

void CPlusPlusCodegenerator::registerObservers(BaseGenerator *observer)
{
    codegeratorObservers.push_back(&*observer);
}


void CPlusPlusCodegenerator::generate(std::vector<QString> strVecScript,std::map<QString,QString> strMapRules)
{
    QString scriptelement=" ";
    QString scriptelementFirst= " ";
    QString scriptelementLast= " ";
    QString mapValue = " ";

    // first element of vecSript is the complete filename;
    QString filenamePath = strVecScript[scriptindex];
    filenamePath = General::ExtractString::extractLast(filenamePath);

    QFile heatherFile(filenamePath);
    QFile sourceFile(filenamePath);

    try
    {
        generateCodeFiles(heatherFile,sourceFile);
        QTextStream outh(&heatherFile);
        QTextStream outs(&sourceFile);


        QString row;
        for(scriptindex=1;scriptindex<strVecScript.size();++scriptindex)
        {
            scriptelement = strVecScript[scriptindex];
            scriptelementFirst = General::ExtractString::extractFirst(scriptelement);
            scriptelementLast = General::ExtractString::extractLast(scriptelement);

            mapValue = strMapRules[scriptelementFirst];
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
                            continue;
                        }
                        else
                        {
                            outh << row << "\n";
                        }
                    }
                }// if
            } //if
        } // for
        outh << '\n';
     } // try
     catch(Excetionhandling& e)
     {
       std::cout << e.whatCode();
       std::cout << e.whatDescription();
     }

     heatherFile.close();
     sourceFile.close();

    for(unsigned int i=0; i < codegeratorObservers.size(); i++)
    {
        codegeratorObservers[i]->notifyCodeGenerated();
    }
}

void CPlusPlusCodegenerator::generateCodeFiles(QFile& hfile,QFile &cppFile)
{
    throw OpenFileException();
    if(!hfile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        throw OpenFileException();
    }
    if(!cppFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        OpenFileException();
    }
}

}

