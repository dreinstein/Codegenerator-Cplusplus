#include <QFile>
#include <iostream>
#include <qglobal.h>
#include "Utilities.h"
#include "Codegeneratorimpl.h"
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

void CPlusPlusCodegenerator::generate(CodegeneratorImpl* _impl)
{
    impl = _impl;
}


void CPlusPlusCodegenerator::generate(std::vector<QString> strVecScript,std::map<QString,QString> strMapRules)
{
    QString scriptelement=" ";
    QString scriptelementFirst= " ";
    QString scriptelementLast= " ";
    QString mapValue = " ";

    QString filenamePath = strVecScript[0];
    filenamePath = General::ExtractString::extractLast(filenamePath);

    if(impl == nullptr)
    {
        impl = new CodegeneratorImpl(strVecScript,strMapRules,filenamePath);
    }
    Q_ASSERT(impl);

    try
    {
        impl->generateCodeFiles();
     //   impl->write();
     } // try
     catch(Excetionhandling& e)
     {
       std::cout << e.whatCode();
       std::cout << e.whatDescription();
     }

    int index = impl->getIndex();
    QString sClass = strVecScript[index];
    sClass = General::ExtractString::extractFirst(sClass);

    BaseCodegenerator *base = BaseCodegenerator::getClassForNextElement(sClass);
    base->generate(impl);

    delete impl;
}

}

