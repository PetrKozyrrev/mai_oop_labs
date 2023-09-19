#include <gtest/gtest.h>
#include "solution.cpp"

TEST(test01, basic_test_set)
{
    ASSERT_TRUE(box_capacity(32,16,64)==13824);
}

TEST(test02, basic_test_set)
{
    ASSERT_TRUE(box_capacity(1,1,64)==0);
}

TEST(test03, basic_test_set)
{
    ASSERT_TRUE(box_capacity(100,3,2048)==230400);
}

TEST(test04, basic_test_set)
{
    ASSERT_TRUE(box_capacity(1,1,1)==0);
}

TEST(test05, basic_test_set)
{
    ASSERT_TRUE(box_capacity(16,16,16)==1728);
}

TEST(test06, basic_test_set)
{
    ASSERT_TRUE(box_capacity(32000,2,2)==24000);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}