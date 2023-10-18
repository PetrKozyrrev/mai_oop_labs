#include <gtest/gtest.h>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"

// Trapezoid
TEST(trapezoid_test01, based_test)
{
    Trapezoid a;
    Trapezoid b(0,0,0,0,0,0,0,0);

    EXPECT_TRUE(a == b);
    EXPECT_EQ(0,a.square());
    EXPECT_EQ(0,b.square());
}

TEST(trapezoid_test02, based_test)
{
    Trapezoid a(0,0,0,10,10,10,10,0);
    Trapezoid b(a);

    EXPECT_TRUE(a == b);
    EXPECT_EQ(100,a.square());
    EXPECT_EQ(100,b.square());
}

TEST(trapezoid_test03, based_test)
{
    Trapezoid a(0,0,3,8,10,8,17,0);

    EXPECT_EQ(96,a.square());
}

TEST(trapezoid_test04, based_test)
{
    Trapezoid a(1,1,2,2,5,2,7,0);
    Trapezoid b;

    b = a;

    EXPECT_TRUE(a == b);
}

// Rhombus
TEST(rhombus_test01, based_test)
{
    Rhombus a;
    Rhombus b(0,0,0,0,0,0,0,0);

    EXPECT_TRUE(a == b);
    EXPECT_EQ(0,a.square());
    EXPECT_EQ(0,b.square());
}

TEST(rhombus_test02, based_test)
{
    Rhombus a(0,0,-5,10,0,20,5,10);

    EXPECT_EQ(100,a.square());
}

// Pentagon
TEST(pentagon_test01, based_test)
{
    Pentagon a;
    Pentagon b(0,0,0,0,0,0,0,0,0,0);

    EXPECT_TRUE(a == b);
    EXPECT_EQ(0,a.square());
    EXPECT_EQ(0,b.square());
}

TEST(pentagon_test02, based_test)
{
    Pentagon a(0,0,-2.16,6.66,3.5,10.77,9.16,6.66,7,0);

    EXPECT_TRUE(a.square() >= 84 and a.square()<85);
}
