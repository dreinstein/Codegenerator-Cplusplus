#ifndef TESTUTILITIES_H
#define TESTUTILITIES_H

#include <QString>
#include <list>

class TestUtilities
{
public:
    static std::list<QString> FunctionTest(QString codescript);
private:
    TestUtilities();
    ~TestUtilities();
};

#endif // TESTUTILITIES_H
