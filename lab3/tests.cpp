#include <gtest/gtest.h>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"

// Trapezoid
TEST(trapezoid_test01, default_constructor)
{
    Trapezoid a;
    Trapezoid b(0,0,0,0,0,0,0,0);

    EXPECT_TRUE(a == b);
    EXPECT_EQ(0,a.square());
    EXPECT_EQ(0,b.square());
}

TEST(trapezoid_test02, default_constructor)
{
    Trapezoid a(0,0,0,10,10,10,10,0);
    Trapezoid b(a);

    EXPECT_TRUE(a == b);
    EXPECT_EQ(100,a.square());
    EXPECT_EQ(100,b.square());
}

// Rhombus
TEST(rhombus_test01, default_constructor)
{
    Rhombus a;
    Rhombus b(0,0,0,0,0,0,0,0);

    EXPECT_TRUE(a == b);
    EXPECT_EQ(0,a.square());
    EXPECT_EQ(0,b.square());
}

// Pentagon
TEST(pentagon_test01, default_constructor)
{
    Pentagon a;
    Pentagon b(0,0,0,0,0,0,0,0,0,0);

    EXPECT_TRUE(a == b);
    EXPECT_EQ(0,a.square());
    EXPECT_EQ(0,b.square());
}
