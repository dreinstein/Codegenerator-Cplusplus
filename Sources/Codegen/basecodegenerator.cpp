#include <list>
#include "Basecodegenerator.h"
#include "classgenerator.h"
#include "Attributegenerator.h"
#include "Fuctioncodegenerator.h"
#include "QTextStream"
#include "Utilities.h"
#include "../Errorhandling/OpenfileException.h"


namespace Codegenerator
{


BaseCodegenerator::BaseCodegenerator()
{
    index = 0;
    sourcefilename = General::FilePath::SourceFileName;
    heaterfilename = General::FilePath::HeaderFileName;
    classname = " ";
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
    classname = toClone->classname;
}


void BaseCodegenerator::generateDefault()
{
    QString row;
    QString scriptelement = script[index];
    QString scriptelementFirst = General::ExtractString::extractFirst(scriptelement);
    classname = General::ExtractString::extractLast(scriptelement);
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
                    if(classname != emptyChar)
                    {
                        generatedCodeHeader.push_back(tab);
                        generatedCodeHeader.push_back(classname);
                        generatedCodeHeader.push_back(newLine);
                    }
                    else
                    {
                        generatedCodeHeader.push_back(newLine);
                    }
                }
                else
                {
                    generatedCodeHeader.push_back(row);
                    generatedCodeHeader.push_back(newLine);
                }
            }// while

        } //if
        else
        {
            throw Errorhandling::OpenFileException();
        }
   }
   generatedCodeHeader.push_back(newLine);
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


BaseCodegenerator* BaseCodegenerator::getNextElement(QString sindex)
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
    if("function" == sindex)
    {
        generator = new FuctionCodeGenerator(this);
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
        QString foundStr = tab;
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
        if(foundStr != tab)
        {
            BaseCodegenerator *next = BaseCodegenerator::getNextElement(foundStr);
            next->generate();
            generatedCodeHeader = next->getHeaderListData();
            generatedCodeSource = next->getSourceListData();
            delete next;
        }
    }
}


}
