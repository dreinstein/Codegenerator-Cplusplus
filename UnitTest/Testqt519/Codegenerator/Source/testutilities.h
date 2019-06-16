#ifndef TESTUTILITIES_H
#define TESTUTILITIES_H

#include <QString>
#include <list>
#include "Codegen/CPluspluscodegenerator.h"

class TestUtilities
{
public:
    static std::list<QString> FunctionTestSourceList(QString codescript);
    static std::list<QString> FunctionTestHeaderList(QString codescript);
    static void generate(Codegenerator::BaseCodegenerator* generator,QString codescript);
private:
    TestUtilities();
    ~TestUtilities();
};

#endif // TESTUTILITIES_H
