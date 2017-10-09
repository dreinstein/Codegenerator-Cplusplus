

#include "../../gtest/gtest.h"
#include <QString>
#include "Gui/BaseLoadAndFormate.h"
#include "Gui/attributeload.h"
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
TEST(GuiTest, loadParameter)
{
   BaseLoadAndFormate *attributes = new AttributeLoad();
   QString scriptPath = "..\\Files\\Scripts\\XML\\GuiAttributes.xml";
   std::vector<std::unique_ptr<Codegenerator::AttributeElements>> datas = attributes->loadDataSet(scriptPath);
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

