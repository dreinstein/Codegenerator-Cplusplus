#ifndef TST_TESTCODEGENERATOR_H
#define TST_TESTCODEGENERATOR_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(TestCodegenerator, TestCodegenerator)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_TESTCODEGENERATOR_H
