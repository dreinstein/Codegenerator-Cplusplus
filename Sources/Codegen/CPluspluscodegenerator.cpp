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
    createFiles();
}


void CPlusPlusCodegenerator::createFiles()
{
    QFile hfile(heaterfilename);
   // QFile sfile(sourcefilename);

    hfile.open(QIODevice::WriteOnly | QIODevice::Text);
   // sfile.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream heaterFileStream (&hfile);
   // QTextStream sourceFileStream (&sfile);
    for (auto elementHeader: generatedCodeHeader)
    {
        heaterFileStream << elementHeader;
    }
/*    for (auto elementSource: generatedCodeHeader)
    {
        sourceFileStream << elementSource;
    }*/
    hfile.close();
  //  sfile.close();
}



}

