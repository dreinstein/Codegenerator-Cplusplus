#include "Basecodegenerator.h"
#include "classgenerator.h"
#include "Attribute.h"
#include "QTextStream"
#include "Utilities.h"
#include "../Errorhandling/OpenfileException.h"


namespace Codegenerator
{


BaseCodegenerator::BaseCodegenerator()
{
    index = 0;
    sourcefilename = " ";
    heaterfilename = " ";
}

void BaseCodegenerator::clone(const BaseCodegenerator *toClone)
{
    index = toClone->index;
    sourcefilename = toClone->sourcefilename;
    heaterfilename = toClone->heaterfilename;
    generatedCodeHeader = toClone->generatedCodeHeader;
    generatedCodeSource = toClone->generatedCodeSource;
    script = toClone->script;
    rules = toClone->rules;
    keys = toClone->keys;
    codegeratorObservers = toClone->codegeratorObservers;
}


void BaseCodegenerator::generateDefault()
{
    QString row;
    QString scriptelement = script[index];
    QString scriptelementFirst = General::ExtractString::extractFirst(scriptelement);
    QString scriptelementLast = General::ExtractString::extractLast(scriptelement);
    QString mapValue = rules[scriptelementFirst];

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
                    generatedCodeHeader.push_back(scriptelementFirst);
                    if(scriptelementLast != "")
                    {
                        generatedCodeHeader.push_back(" ");
                        generatedCodeHeader.push_back(scriptelementLast);
                        generatedCodeHeader.push_back("\n");
                    }
                    else
                    {
                        generatedCodeHeader.push_back("\n");
                    }
                }
                else
                {
                    generatedCodeHeader.push_back(row);
                }
            }// while

        } //if
        else
        {
            throw Errorhandling::OpenFileException();
        }
   }
   generatedCodeHeader.push_back("\n");
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
     sourcefilename = filenamePath + ".cpp";
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
    if("attribute" == sindex)
    {
        generator = new Attribute(this);
        return generator;
    }
    Q_ASSERT(false);
}


void BaseCodegenerator::nextElement()
{
    index = index +1;
    if(index < script.size())
    {
        QString umlElement = script[index];
        QStringList umlList = General::ExtractString::extractStringList(umlElement);
        QString foundStr = " ";
        foreach(QString v, umlList)
        {
            v = General::ExtractString::extractFirst(v);
            for (QString s : keys)
            {
                if(v == s)
                {
                    foundStr = v;
                    break;
                }
            }
        }
        if(foundStr != "")
        {
            BaseCodegenerator *next = BaseCodegenerator::getClass(foundStr);
            next->generate();
            delete next;
        }
    }
}

}
