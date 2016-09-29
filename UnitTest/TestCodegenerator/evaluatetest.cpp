#include "evaluatetest.h"


EvaluateTest::EvaluateTest()
{

}



void EvaluateTest::evaluateParserVector(std::vector<QString> values,std::vector<QString> refValues)
{
    ASSERT_EQ(values[1], refValues[1]);
    ASSERT_EQ(values[2], refValues[2]);
    ASSERT_EQ(values[3], refValues[3]);
    ASSERT_EQ(values[4], refValues[4]);
    ASSERT_EQ(values[5], refValues[5]);
    ASSERT_EQ(values[6], refValues[6]);
    ASSERT_EQ(values[7], refValues[7]);
    ASSERT_EQ(values[8], refValues[8]);
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

