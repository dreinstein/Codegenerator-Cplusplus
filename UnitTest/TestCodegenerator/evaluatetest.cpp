#include "evaluatetest.h"

EvaluateTest::EvaluateTest()
{

}

bool EvaluateTest::evaluate(std::list<QString> testdata, std::list<QString> evaluationData)
{
    if(testdata.size() != evaluationData.size())
    {
        return false;
    }
    QString testDataString ="";
    QString evaluationDataString = "";
    auto evaluationDataIterator = evaluationData.begin();
    for(auto testDataIterator = testdata.begin();testDataIterator != testdata.end(); ++testDataIterator,++evaluationDataIterator)
    {
        testDataString = *testDataIterator;
        evaluationDataString = *evaluationDataIterator;
        if(testDataString != evaluationDataString)
        {

            return false;
        }
    }
    return true;
}

