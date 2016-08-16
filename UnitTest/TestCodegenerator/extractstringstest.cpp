#include <memory>
#include <QString>
#include "../../gtest/gtest.h"
#include "../../gmock/gmock.h"
#include "GeneratorCPlusPlus.h"
#include "Parsing/Parserimplementation.h"

using namespace NGenerator;
using namespace NParser;
using ::testing::Return;


TEST(BasicTest, extractStringFirst)
{
    QString testString = "@class::firstClass";
    testString = General::ExtractString::extractFirst(testString);
    ASSERT_EQ("class",testString);
}

TEST(BasicTest, extractStringLast)
{
    QString testString = "@class::firstClass";
    testString = General::ExtractString::extractLast(testString);
    ASSERT_EQ("firstClass",testString);
}


TEST(BasicTest, extractStringList)
{
    QString testString = "@modifier::private@typ::int@attribute::myfirstAttribute";
    QStringList stringList = General::ExtractString::extractStringList(testString);
    ASSERT_EQ("@modifier::private",stringList.at(0));
    ASSERT_EQ("@typ::int",stringList.at(1));
    ASSERT_EQ("@attribute::myfirstAttribute",stringList.at(2));
}

TEST(BasicTest, extractParameter)
{
    QString testString = "@modifier::public@typ::double@parameter::parameter1@typ::double";
    QString parameterString = General::ExtractString::extractParameter(testString);
    ASSERT_EQ("@typ::double",parameterString);
}

