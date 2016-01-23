#include "Basecodegenerator.h"
#include "classgenerator.h"
#include "QTextStream"
#include "Utilities.h"
#include "../Errorhandling/OpenfileException.h"


namespace Codegenerator
{

void BaseCodegenerator::clone(const BaseCodegenerator *toClone)
{
  //  headerFile = toClone->headerFile;
  //  sourceFile = toClone->sourceFile;
    index = toClone->index;
    sourcefilename = toClone->sourcefilename;
    heaterfilename = toClone->heaterfilename;
    script = toClone->script;
    rules = toClone->rules;
    keys = toClone->keys;
    codegeratorObservers = toClone->codegeratorObservers;
}


void BaseCodegenerator::generateDefault()
{
    QString scriptelement=" ";
    QString scriptelementFirst= " ";
    QString scriptelementLast= " ";
    QString mapValue = " ";

    QFile hFile(heaterfilename);
    QFile sFile(sourcefilename);

    if(!hFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        throw Errorhandling::OpenFileException();
    }
    if(!sFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        throw Errorhandling::OpenFileException();
    }
    QTextStream outh(&hFile);
    QTextStream outs(&sFile);

    QString row;
    scriptelement = script[index];
    scriptelementFirst = General::ExtractString::extractFirst(scriptelement);
    scriptelementLast = General::ExtractString::extractLast(scriptelement);
    mapValue = rules[scriptelementFirst];


    // @todo refactor it
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
            throw Errorhandling::OpenFileException();
        }
   }
   outh << '\n';

   sFile.close();
   hFile.close();
}


void BaseCodegenerator::openFiles()
{
    QFile hFile(sourcefilename);
    QFile sFile(heaterfilename);
    if(!hFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        throw Errorhandling::OpenFileException();
    }
    if(!sFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        throw Errorhandling::OpenFileException();
    }
    hFile.close();
    sFile.close();
}




 void BaseCodegenerator::setFilenames()
 {
     QString filenamePath = script[0];
     filenamePath = General::ExtractString::extractLast(filenamePath);
     heaterfilename = filenamePath + ".h";
     sourcefilename = filenamePath + ".s";
 }


BaseCodegenerator* BaseCodegenerator::getClass(QString sindex)
{
    BaseCodegenerator *generator = nullptr;
    sindex = sindex.toLower();
    if("class" == sindex)
    {
        generator = new ClassGenerator(this);
        return generator;
    }
    Q_ASSERT(false);
}


void BaseCodegenerator::nextElement()
{
    if(index < script.size())
    {
        QString umlElement = script[index];
        QStringList umlList = General::ExtractString::extractStringList(umlElement);
        QString foundStr = " ";
        foreach(QString v, umlList)
        {
            for (QString s : keys)
            {
                if(v == s)
                {
                    foundStr = v;
                    break;
                }
            }
        }
        BaseCodegenerator *next = BaseCodegenerator::getClass(foundStr);
        next->generate();
        delete next;
    }
}

}
