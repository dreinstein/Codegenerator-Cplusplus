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

void CPlusPlusCodegenerator::registerObservers(BaseGenerator *observer)
{
    codegeratorObservers.push_back(&*observer);
}

void CPlusPlusCodegenerator::generate()
{
    Q_ASSERT(true);
}


void CPlusPlusCodegenerator::generate(const std::vector<QString> strVecScript,const std::map<QString,QString> strMapRules,std::vector<QString> strVecKeys)
{
    script = strVecScript;
    rules = strMapRules;
    keys = strVecKeys;
    index = 0;
    nextElement();
    for(unsigned int i=0; i < codegeratorObservers.size(); i++){
        codegeratorObservers[i]->notifyCodeGenerated();
    }
    createHeaderFile();
    createSourceFile();
}


void CPlusPlusCodegenerator::createHeaderFile()
{
    QFile hfile(heaterfilename);
    hfile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream heaterFileStream (&hfile);
    for (auto elementHeader: generatedCodeHeader)
    {
        heaterFileStream << elementHeader;
    }
    hfile.close();
}

void CPlusPlusCodegenerator::createSourceFile()
{
    QFile sfile(sourcefilename);
    sfile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream sourceFileStream (&sfile);
    for (auto elementSource: generatedCodeSource)
    {
        sourceFileStream << elementSource;
    }
    sfile.close();
}


}

