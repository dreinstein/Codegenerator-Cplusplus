

#include "../../gtest/gtest.h"
#include <QString>
#include "Gui/attributeload.h"
#include "Gui/functionload.h"
#include "testutilities.h"
#include "Codegen/Attributeelements.h"
#include <vector>
#include <memory>
#include "Codegen/Codegeneratorconstants.h"



class GuiTest
{
protected:
    GuiTest();
};

// Testcases 1
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
TEST(GuiTest, loadAttributes)
{
   AttributeLoad *attributes = new AttributeLoad();
   QString scriptPath = "..\\Files\\Scripts\\XML\\GuiAttributes.xml";
   std::vector<std::unique_ptr<Codegenerator::AttributeElements>> datas = attributes->loadDatasFromFile(scriptPath);
   ASSERT_EQ(datas.size(),3);
   ASSERT_EQ(datas[0].get()->getAttribute(),"attributeint");
   ASSERT_EQ(datas[1].get()->getAttribute(),"attributedouble");
   ASSERT_EQ(datas[2].get()->getAttribute(),"attributeClassTest");

   ASSERT_EQ(datas[0].get()->getModifier(),Codegenerator::CodegeneratorConstants::modifierProtected);
   ASSERT_EQ(datas[1].get()->getModifier(),Codegenerator::CodegeneratorConstants::modifierPublic);
   ASSERT_EQ(datas[2].get()->getModifier(),Codegenerator::CodegeneratorConstants::modifierPrivate);

   ASSERT_EQ(datas[0].get()->getTyp(),"int");
   ASSERT_EQ(datas[1].get()->getTyp(),"double");
   ASSERT_EQ(datas[2].get()->getTyp(),"class Test");

   ASSERT_EQ(datas[0].get()->getIsConstant(),true);
   ASSERT_EQ(datas[1].get()->getIsConstant(),true);
   ASSERT_EQ(datas[2].get()->getIsConstant(),true);

   ASSERT_EQ(datas[0].get()->getIsMemoryConstant(),false);
   ASSERT_EQ(datas[1].get()->getIsMemoryConstant(),true);
   ASSERT_EQ(datas[2].get()->getIsMemoryConstant(),false);

   ASSERT_EQ(datas[0].get()->getIsParameter(),false);
   ASSERT_EQ(datas[1].get()->getIsParameter(),false);
   ASSERT_EQ(datas[2].get()->getIsParameter(),false);

   ASSERT_EQ(datas[0].get()->getIsPointer(),true);
   ASSERT_EQ(datas[1].get()->getIsPointer(),true);
   ASSERT_EQ(datas[2].get()->getIsPointer(),false);

   ASSERT_EQ(datas[0].get()->getIsRef(),false);
   ASSERT_EQ(datas[1].get()->getIsRef(),false);
   ASSERT_EQ(datas[2].get()->getIsRef(),true);
   delete attributes;
}

TEST(GuiTest, loadFunctions)
{
    FunctionLoad* functions = new FunctionLoad();
    QString scriptPath = "..\\Files\\Scripts\\XML\\GuiFunction.xml";
    std::vector<std::unique_ptr<Codegenerator::FunctionElements>> datas = functions->loadDatasFromFile(scriptPath);
    ASSERT_EQ(datas.size(),2);
    ASSERT_EQ(datas[0].get()->getFunction(),"functionint");
    ASSERT_EQ(datas[0].get()->getModifier(),Codegenerator::CodegeneratorConstants::modifierPrivate);
    ASSERT_EQ(datas[0].get()->getTyp(),"int");
    ASSERT_EQ(datas[0]->getFunctionParameters()[0]->getAttribute(),"myParameter");
    ASSERT_EQ(datas[0]->getFunctionParameters()[0]->getTyp(),"double");
    ASSERT_EQ(datas[0]->getFunctionParameters()[1]->getAttribute(),"doublePointerParameter");
    ASSERT_EQ(datas[0]->getFunctionParameters()[1]->getTyp(),"double");
    ASSERT_EQ(datas[0]->getFunctionParameters()[1]->getIsPointer(),true);
    ASSERT_EQ(datas[1].get()->getFunction(),"functiondouble");
    ASSERT_EQ(datas[1].get()->getModifier(),Codegenerator::CodegeneratorConstants::modifierPublic);
    ASSERT_EQ(datas[1].get()->getTyp(),"double");
    ASSERT_EQ(datas[1].get()->getIsConstant(),true);
    delete functions;
}

