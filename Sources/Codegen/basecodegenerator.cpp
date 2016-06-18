#include <list>
#include "Codegeneratorconstants.h"
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
                    if(classname != CodegeneratorConstants::emptyChar)
                    {
                        generatedCodeHeader.push_back(CodegeneratorConstants::tab);
                        generatedCodeHeader.push_back(classname);
                        generatedCodeHeader.push_back(CodegeneratorConstants::newLine);
                    }
                    else
                    {
                        generatedCodeHeader.push_back(CodegeneratorConstants::newLine);
                    }
                }
                else
                {
                    generatedCodeHeader.push_back(row);
                    generatedCodeHeader.push_back(CodegeneratorConstants::newLine);
                }
            }// while

        } //if
        else
        {
            throw Errorhandling::OpenFileException();
        }
   }
   generatedCodeHeader.push_back(CodegeneratorConstants::newLine);
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


/* deliver Codegenerator class out of string
 */
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
    else return nullptr;
}


/* provide element to generate code out of string
//  e.g umlList = @function::functionNoParameterReturnTestClassReference@modifier::public@typ::TestClass@isReference
// first element v = function, generate code for function */
void BaseCodegenerator::nextElement()
{
    index = index +1;
    if(index < script.size())
    {
        QString umlElement = script[index];
        QStringList umlList = General::ExtractString::extractStringList(umlElement);
        BaseCodegenerator *next = nullptr;
        foreach(QString v, umlList)
        {
             v = General::ExtractString::extractFirst(v);
             next = BaseCodegenerator::getNextElement(v);
             if(next != nullptr)
             {
                 next->generate();
                 generatedCodeHeader = next->getHeaderListData();
                 generatedCodeSource = next->getSourceListData();
             }
        }
        delete next;

    }
}


}
