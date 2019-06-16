
#include "Codegen/Attributeelements.h"
#include "Codegen/Functionelements.h"
#include "Gui/guidatamanager.h"
#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>



class GuiDatamanagerTest: public ::testing::Test
{
public:
    GuiDataManager *guiManager;

    const QString fstring1 = "public int myFunction ()";
    const QString fstring2 = "public double secondFunction ()";
    const QString astring1 = "public double * myAttribute";
    const QString astring2 = "public long secondAttribute";

    virtual void SetUp()
    {
        guiManager = new GuiDataManager();
        func1 = std::make_shared<Codegenerator::FunctionElements>();
        att1 = std::make_shared<Codegenerator::AttributeElements>();
        func2 = std::make_shared<Codegenerator::FunctionElements>();
        att2 = std::make_shared<Codegenerator::AttributeElements>();
        funcString = "myFunction";
        funcTyp = "int";
        funcModifier = "public";
        attTyp = "double";
        attElement = "myAttribute";
        attIsPointer = true;

        funcString2 = "secondFunction";
        funcTyp2 = "double";

        attTyp2 = "long";
        attElement2 = "secondAttribute";


       func1->setFunction(funcString);
       func1->setTyp(funcTyp);
       func1->setModifier(funcModifier);
       att1->setAttribute(attElement);
       att1->setTyp(attTyp);
       att1->setIsPointer(attIsPointer);

       func2->setFunction(funcString2);
       func2->setTyp(funcTyp2);
       func2->setModifier(funcModifier);
       att2->setAttribute(attElement2);
       att2->setTyp(attTyp2);

    }

    virtual void TearDown()
    {
        delete guiManager;
    }

    std::shared_ptr<Codegenerator::FunctionElements> func1;
    std::shared_ptr<Codegenerator::AttributeElements> att1;
    std::shared_ptr<Codegenerator::FunctionElements> func2;
    std::shared_ptr<Codegenerator::AttributeElements> att2;

    QString funcString;
    QString funcTyp;
    QString funcModifier;
    QString attTyp;
    QString attElement;
    bool attIsPointer;

    QString funcString2;
    QString funcTyp2;
    QString attTyp2;
    QString attElement2;
};



TEST_F(GuiDatamanagerTest,noElement)
{

    std::vector<Codegenerator::BaseElements*> base = guiManager->getElements();
    Codegenerator::AttributeElements* attElements = guiManager->getAttributeElement(0);
    Codegenerator::FunctionElements* funcElement = guiManager->getFunctionElement(0);

    ASSERT_EQ(guiManager->getAttributeElement(0), nullptr);
    ASSERT_EQ(attElements,nullptr);
    ASSERT_EQ(funcElement, nullptr);
}


TEST_F(GuiDatamanagerTest,dynamicCast)
{
    guiManager->push(func1);
    guiManager->push(att1);
    ASSERT_EQ(guiManager->getWidgetTyp(0),GuiDataManager::WidgetTypes::FUNCTIONTYPE);
    ASSERT_EQ(guiManager->getWidgetTyp(1),GuiDataManager::WidgetTypes::ATTRIBUTTETYPE);
}


TEST_F(GuiDatamanagerTest,push)
{
    guiManager->push(func1);
    guiManager->push(att1);
    guiManager->push(func2);
    guiManager->push(att2);

    std::vector<Codegenerator::BaseElements*> base = guiManager->getElements();

    QString string0 = base[0]->getString();
    QString string1 = base[1]->getString();
    QString string2 = base[2]->getString();
    QString string3 = base[3]->getString();

    ASSERT_EQ(string0,fstring1);
    ASSERT_EQ(string1,astring1);
    ASSERT_EQ(string2,fstring2);
    ASSERT_EQ(string3,astring2);
}





TEST_F(GuiDatamanagerTest, Up)
{
    guiManager->push(func1);
    guiManager->push(att1);
    guiManager->push(func2);
    guiManager->push(att2);

    guiManager->up(2);
    guiManager->up(3);

    std::vector<Codegenerator::BaseElements*> base = guiManager->getElements();

    QString string0 = base[0]->getString();
    QString string1 = base[1]->getString();
    QString string2 = base[2]->getString();
    QString string3 = base[3]->getString();

    ASSERT_EQ(string0,fstring1);
    ASSERT_EQ(string1,fstring2);
    ASSERT_EQ(string2,astring2);
    ASSERT_EQ(string3,astring1);

    guiManager->up(0);
    ASSERT_EQ(string0,fstring1);
    ASSERT_EQ(string1,fstring2);
    ASSERT_EQ(string2,astring2);
    ASSERT_EQ(string3,astring1);

    guiManager->up(5);
    ASSERT_EQ(string0,fstring1);
    ASSERT_EQ(string1,fstring2);
    ASSERT_EQ(string2,astring2);
    ASSERT_EQ(string3,astring1);
}


TEST_F(GuiDatamanagerTest, Down)
{
    guiManager->push(func1);
    guiManager->push(att1);
    guiManager->push(func2);
    guiManager->push(att2);

    guiManager->down(0);
    guiManager->down(2);

    std::vector<Codegenerator::BaseElements*> base = guiManager->getElements();

    QString string0 = base[0]->getString();
    QString string1 = base[1]->getString();
    QString string2 = base[2]->getString();
    QString string3 = base[3]->getString();

    ASSERT_EQ(string0,astring1);
    ASSERT_EQ(string1,fstring1);
    ASSERT_EQ(string2,astring2);
    ASSERT_EQ(string3,fstring2);

    guiManager->down(3);
    ASSERT_EQ(string0,astring1);
    ASSERT_EQ(string1,fstring1);
    ASSERT_EQ(string2,astring2);
    ASSERT_EQ(string3,fstring2);

    guiManager->down(4);
    ASSERT_EQ(string0,astring1);
    ASSERT_EQ(string1,fstring1);
    ASSERT_EQ(string2,astring2);
    ASSERT_EQ(string3,fstring2);
}




TEST_F(GuiDatamanagerTest, Delete)
{
    guiManager->push(func1);
    guiManager->push(att1);
    guiManager->push(func2);
    guiManager->push(att2);

    guiManager->deleteItem(2);

    std::vector<Codegenerator::BaseElements*> base = guiManager->getElements();

    QString string0 = base[0]->getString();
    QString string1 = base[1]->getString();
    QString string2 = base[2]->getString();

    ASSERT_EQ(base.size(),(unsigned)3);
    ASSERT_EQ(string0,fstring1);
    ASSERT_EQ(string1,astring1);
    ASSERT_EQ(string2,astring2);

    guiManager->deleteItem(3);
    base = guiManager->getElements();
    string0 = base[0]->getString();
    string1 = base[1]->getString();
    string2 = base[2]->getString();
    ASSERT_EQ(base.size(),(unsigned)3);
    ASSERT_EQ(string0,fstring1);
    ASSERT_EQ(string1,astring1);
    ASSERT_EQ(string2,astring2);

    guiManager->deleteItem(0);
    base = guiManager->getElements();
    string0 = base[0]->getString();
    string1 = base[1]->getString();
    ASSERT_EQ(base.size(),(unsigned)2);
    ASSERT_EQ(string0,astring1);
    ASSERT_EQ(string1,astring2);
}



TEST_F(GuiDatamanagerTest, change)
{
    guiManager->push(func1);
    guiManager->push(att1);

    QString funcElement = "myNewFunction";
    QString attElement = "myNewAttribute";

    std::shared_ptr<Codegenerator::AttributeElements> att(new Codegenerator::AttributeElements);
    std::shared_ptr<Codegenerator::FunctionElements> func(new Codegenerator::FunctionElements);

    func.get()->setFunction(funcElement);
    att.get()->setAttribute(attElement);

    guiManager->change(att,0);
    guiManager->change(func,1);

    std::vector<Codegenerator::BaseElements*> base = guiManager->getElements();
    ASSERT_EQ(base.size(),(unsigned)2);

    Codegenerator::FunctionElements* fElement = guiManager->getFunctionElement(1);
    Codegenerator::AttributeElements* aElement = guiManager->getAttributeElement(0);
    ASSERT_EQ(fElement->getFunction(),funcElement);
    ASSERT_EQ(aElement->getAttribute(),attElement);

    guiManager->change(att,2);
    base = guiManager->getElements();
    ASSERT_EQ(base.size(),(unsigned)2);
    fElement = guiManager->getFunctionElement(1);
    aElement = guiManager->getAttributeElement(0);
    ASSERT_EQ(fElement->getFunction(),funcElement);
    ASSERT_EQ(aElement->getAttribute(),attElement);

    guiManager->change(func,2);
    base = guiManager->getElements();
    ASSERT_EQ(base.size(),(unsigned)2);
    fElement = guiManager->getFunctionElement(1);
    aElement = guiManager->getAttributeElement(0);
    ASSERT_EQ(fElement->getFunction(),funcElement);
    ASSERT_EQ(aElement->getAttribute(),attElement);

}


TEST_F(GuiDatamanagerTest, getFunctionElement)
{
    guiManager->push(func1);
    guiManager->push(func2);

    Codegenerator::BaseElements* element = guiManager->getAttributeElement(0);
    ASSERT_EQ(element,nullptr);

    Codegenerator::FunctionElements* fElement = guiManager->getFunctionElement(0);
    ASSERT_EQ(fElement->getFunction(),funcString);

    fElement = guiManager->getFunctionElement(1);
    ASSERT_EQ(fElement->getFunction(),funcString2);

    fElement = guiManager->getFunctionElement(2);
    ASSERT_EQ(fElement,nullptr);
}

TEST_F(GuiDatamanagerTest, getAttributeElement)
{
    guiManager->push(att1);
    guiManager->push(att2);

    Codegenerator::BaseElements* element = guiManager->getFunctionElement(0);
    ASSERT_EQ(element,nullptr);

    Codegenerator::AttributeElements* aElement = guiManager->getAttributeElement(0);
    ASSERT_EQ(aElement->getAttribute(),attElement);

    aElement = guiManager->getAttributeElement(1);
    ASSERT_EQ(aElement->getAttribute(),attElement2);

    aElement = guiManager->getAttributeElement(2);
    ASSERT_EQ(aElement,nullptr);
}


TEST_F(GuiDatamanagerTest, getWidgetTyp)
{
    guiManager->push(att1);
    guiManager->push(func1);
    ASSERT_EQ(guiManager->getWidgetTyp(0),GuiDataManager::WidgetTypes::ATTRIBUTTETYPE);
    ASSERT_EQ(guiManager->getWidgetTyp(1),GuiDataManager::WidgetTypes::FUNCTIONTYPE);
    ASSERT_EQ(guiManager->getWidgetTyp(3),GuiDataManager::WidgetTypes::ERRORTYP);
}

