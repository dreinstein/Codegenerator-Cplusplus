#include "systemtest.h"
#include "mockcpluspluscodegenerator.h"
#include "Base/BaseGenerator.h"
#include "../../gtest/gtest.h"



using namespace NGenerator;

SystemTest::SystemTest()
{

}

// check if all data's from rules, script and keywordfile are read and transfered to generator
TEST(SystemTest,GeneratorhasallFiles){
    BaseGenerator* myGenerator = new MockCPlusPlusCodegenerator();
    myGenerator->generate();
    bool received = myGenerator->areAllDatasReceived();
    EXPECT_EQ(true, received);
}
