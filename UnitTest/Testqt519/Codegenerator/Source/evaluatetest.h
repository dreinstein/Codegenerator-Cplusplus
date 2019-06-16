#ifndef EVALUATETEST_H
#define EVALUATETEST_H

#include <list>
#include <QString>
#include <vector>


class EvaluateTest
{
public:
    EvaluateTest();
    static bool evaluate(std::list<QString> testdata, std::list<QString> evaluationData);
    static void evaluateParserVector(std::vector<QString> values,std::vector<QString> refValues);
};

#endif // EVALUATETEST_H
