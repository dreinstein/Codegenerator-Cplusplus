#include "guiattribute.h"

#include "gmock/gmock.h"
#include<QString>

class MockGuiAttribute
{
public:

    MOCK_METHOD0(getFormatedString, QString());
    MOCK_METHOD0(loadDataSet, void());
};


// Testcases 1
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
TEST(MockGuiAttribute, loadParameter)
{
   bool result = false;
   ASSERT_EQ(result, true);

}
