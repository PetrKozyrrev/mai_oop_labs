#include <gtest/gtest.h>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Array.h"

TEST(trapezoid_test01, based_test)
{
    Trapezoid<int> a(std::pair(1,1),std::pair(2,2),std::pair(3,3),std::pair(4,4));
    Trapezoid<int> b;

    b = a;
    EXPECT_TRUE(a == b);
}
