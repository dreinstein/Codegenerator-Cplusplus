#include <QFile>
#include <iostream>
#include <qglobal.h>
#include <QFile>
#include <QTextStream>
#include <string>
#include "Utilities.h"
#include "CPluspluscodegenerator.h"
#include "Basecodegenerator.h"
#include "../Errorhandling/Exceptionhandling.h"


using namespace Errorhandling;


namespace Codegenerator
{

CPlusPlusCodegenerator::CPlusPlusCodegenerator()
{

}


CPlusPlusCodegenerator::~CPlusPlusCodegenerator()
{

}

void CPlusPlusCodegenerator::registerObservers(BaseGenerator *observer)
{
    codegeratorObservers.push_back(&*observer);
}

void CPlusPlusCodegenerator::generate()
{
}


void CPlusPlusCodegenerator::generate(std::vector<QString> strVecScript,std::map<QString,QString> strMapRules,std::vector<QString> strVecKeys)
{
    script = strVecScript;
    rules = strMapRules;
    keys = strVecKeys;
    index = 0;
    nextElement();
    createFiles();
}


void CPlusPlusCodegenerator::createFiles()
{
    QFile hfile(heaterfilename);
    QFile sfile(sourcefilename);

    hfile.open(QIODevice::WriteOnly | QIODevice::Text);
    sfile.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream heaterFileStream (&hfile);
    QTextStream sourceFileStream (&sfile);

    for(list<QString>::iterator hiterator = generatedCodeHeader.begin();hiterator != generatedCodeHeader.end(); ++hiterator)
    {
        heaterFileStream << *hiterator;
    }
    for(list<QString>::iterator siterator = generatedCodeSource.begin();siterator != generatedCodeSource.end(); ++siterator)
    {
        sourceFileStream << *siterator;
    }
    hfile.close();
    sfile.close();
}



}

