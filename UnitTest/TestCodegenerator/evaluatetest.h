#ifndef EVALUATETEST_H
#define EVALUATETEST_H

#include <list>
#include <QString>

class EvaluateTest
{
public:
    EvaluateTest();
    static bool evaluate(std::list<QString> testdata, std::list<QString> evaluationData);
};

#endif // EVALUATETEST_H
