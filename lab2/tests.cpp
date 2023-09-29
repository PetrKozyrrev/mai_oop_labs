#include <gtest/gtest.h>
#include "money.cpp"

TEST(test01, basic_test_set)
{
    Money a {"001"};
    Money b {'1'};
    Money c {"101"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(test02, basic_test_set)
{
    Money a {"00005"};
    Money b {"00005"};
    Money c {"000001"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(test03, basic_test_set)
{
    Money a {"1111"};
    Money b {"19"};
    Money c {"2021"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(test04, basic_test_set)
{
    Money a {'0'};
    Money b {"12345"};
    Money c {"12345"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(test05, basic_test_set)
{
    Money a {"990001"};
    Money b {'1'};
    Money c {"001001"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(test06, basic_test_set)
{
    Money a {"1"};
    Money b {"005"};
    try{
        a.remove(b);
    }catch(std::exception &ex){
        EXPECT_STREQ(ex.what(),"negative balance");
    }
}

TEST(test07, basic_test_set)
{
    Money a {"00511"};
    Money b {"0051"};
    Money c {"00001"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(test08, basic_test_set)
{
    Money a {"001"};
    Money b {'1'};
    Money c {"99"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(test09, basic_test_set)
{
    Money a {"123456"};
    Money b {"123456"};
    Money c {'0'};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(test10, basic_test_set)
{
    Money a {"000000001"};
    Money b {'1'};
    Money c {"99999999"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}