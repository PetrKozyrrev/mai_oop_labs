#include <gtest/gtest.h>

#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Array.h"
#include "Functions.h"

#define pii std::pair<int,int>
#define pdd std::pair<double,double>

// Trapezoid

TEST(trapezoid_test01, empty_constructor_int){
    Trapezoid<int> a;

    double sm = square<Trapezoid<int>,int>(a);

    EXPECT_EQ(sm,0);
}

TEST(trapezoid_test02, four_points_constructor_int){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));

    double sm = square<Trapezoid<int>,int>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(trapezoid_test03, copy_constructor_int){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Trapezoid<int> b(a);

    double sm = square<Trapezoid<int>,int>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(trapezoid_test04, move_constructor_int){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Trapezoid<int> b(std::move(a));

    double sm = square<Trapezoid<int>,int>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(trapezoid_test05, copy_int){
    Trapezoid<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4));
    Trapezoid<int> b;

    b = a;
    EXPECT_TRUE(a == b);
}

TEST(trapezoid_test06, move_copy_int){
    Trapezoid<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4));
    Trapezoid<int> b;

    b = std::move(a);
    EXPECT_TRUE(a == b);
}

TEST(trapezoid_test07, empty_constructor_double){
    Trapezoid<double> a;

    double sm = square<Trapezoid<double>,double>(a);

    EXPECT_EQ(sm,0);
}

TEST(trapezoid_test08, four_points_constructor_double){
    Trapezoid<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));

    double sm = square<Trapezoid<double>,double>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(trapezoid_test09, copy_constructor_double){
    Trapezoid<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));
    Trapezoid<double> b(a);

    double sm = square<Trapezoid<double>,double>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(trapezoid_test10, move_constructor_double){
    Trapezoid<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));
    Trapezoid<double> b(std::move(a));

    double sm = square<Trapezoid<double>,double>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(trapezoid_test11, copy_double){
    Trapezoid<double> a(pdd(1.0,1.0),pii(2.0,2.0),pii(3.0,3.0),pii(4.0,4.0));
    Trapezoid<double> b;

    b = a;
    EXPECT_TRUE(a == b);
}

TEST(trapezoid_test12, move_copy_double){
    Trapezoid<double> a(pdd(1.0,1.0),pdd(2.0,2.0),pdd(3.0,3.0),pdd(4.0,4.0));
    Trapezoid<double> b;

    b = std::move(a);
    EXPECT_TRUE(a == b);
}

// Rhombus

TEST(rhombus_test01, empty_constructor_int){
    Rhombus<int> a;

    double sm = square<Rhombus<int>,int>(a);

    EXPECT_EQ(sm,0);
}

TEST(Rhombus_test02, four_points_constructor_int){
    Rhombus<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));

    double sm = square<Rhombus<int>,int>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(Rhombus_test03, copy_constructor_int){
    Rhombus<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(a);

    double sm = square<Rhombus<int>,int>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Rhombus_test04, move_constructor_int){
    Rhombus<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(std::move(a));

    double sm = square<Rhombus<int>,int>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Rhombus_test05, copy_int){
    Rhombus<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4));
    Rhombus<int> b;

    b = a;
    EXPECT_TRUE(a == b);
}

TEST(Rhombus_test06, move_copy_int){
    Rhombus<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4));
    Rhombus<int> b;

    b = std::move(a);
    EXPECT_TRUE(a == b);
}

TEST(Rhombus_test07, empty_constructor_double){
    Rhombus<double> a;

    double sm = square<Rhombus<double>,double>(a);

    EXPECT_EQ(sm,0);
}

TEST(Rhombus_test08, four_points_constructor_double){
    Rhombus<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));

    double sm = square<Rhombus<double>,double>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(Rhombus_test09, copy_constructor_double){
    Rhombus<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));
    Rhombus<double> b(a);

    double sm = square<Rhombus<double>,double>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Rhombus_test10, move_constructor_double){
    Rhombus<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));
    Rhombus<double> b(std::move(a));

    double sm = square<Rhombus<double>,double>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Rhombus_test11, copy_double){
    Rhombus<double> a(pdd(1.0,1.0),pdd(2.0,2.0),pdd(3.0,3.0),pdd(4.0,4.0));
    Rhombus<double> b;

    b = a;
    EXPECT_TRUE(a == b);
}

TEST(Rhombus_test12, move_copy_double){
    Rhombus<double> a(pdd(1.0,1.0),pdd(2.0,2.0),pdd(3.0,3.0),pdd(4.0,4.0));
    Rhombus<double> b;

    b = std::move(a);
    EXPECT_TRUE(a == b);
}

// Pentagon

TEST(Pentagon_test01, empty_constructor_int){
    Pentagon<int> a;

    double sm = square<Pentagon<int>,int>(a);

    EXPECT_EQ(sm,0);
}

TEST(Pentagon_test02, four_points_constructor_int){
    Pentagon<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0),pii(0,0));

    double sm = square<Pentagon<int>,int>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(Pentagon_test03, copy_constructor_int){
    Pentagon<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0),pii(0,0));
    Pentagon<int> b(a);

    double sm = square<Pentagon<int>,int>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Pentagon_test04, move_constructor_int){
    Pentagon<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0),pii(0,0));
    Pentagon<int> b(std::move(a));

    double sm = square<Pentagon<int>,int>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Pentagon_test05, copy_int){
    Pentagon<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4),pii(0,0));
    Pentagon<int> b;

    b = a;
    EXPECT_TRUE(a == b);
}

TEST(Pentagon_test06, move_copy_int){
    Pentagon<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4),pii(0,0));
    Pentagon<int> b;

    b = std::move(a);
    EXPECT_TRUE(a == b);
}

TEST(Pentagon_test07, empty_constructor_double){
    Pentagon<double> a;

    double sm = square<Pentagon<double>,double>(a);

    EXPECT_EQ(sm,0);
}

TEST(Pentagon_test08, four_points_constructor_double){
    Pentagon<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0),pdd(0.0,0.0));

    double sm = square<Pentagon<double>,double>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(Pentagon_test09, copy_constructor_double){
    Pentagon<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0),pdd(0.0,0.0));
    Pentagon<double> b(a);

    double sm = square<Pentagon<double>,double>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Pentagon_test10, move_constructor_double){
    Pentagon<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0),pdd(0.0,0.0));
    Pentagon<double> b(std::move(a));

    double sm = square<Pentagon<double>,double>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Pentagon_test11, copy_double){
    Pentagon<double> a(pdd(1.0,1.0),pdd(2.0,2.0),pdd(3.0,3.0),pdd(4.0,4.0),pdd(0.0,0.0));
    Pentagon<double> b;

    b = a;
    EXPECT_TRUE(a == b);
}

TEST(Pentagon_test12, move_copy_double){
    Pentagon<double> a(pdd(1.0,1.0),pdd(2.0,2.0),pdd(3.0,3.0),pdd(4.0,4.0),pdd(0.0,0.0));
    Pentagon<double> b;

    b = std::move(a);
    EXPECT_TRUE(a == b);
}

// Array

TEST(array_test01, empty_constructor){
    Array<std::shared_ptr<Figure>> arr;

    EXPECT_EQ(arr.size(), 0);
}

TEST(array_test02, size_constructor){
    Array<std::shared_ptr<Figure>> arr(2);

    EXPECT_EQ(arr.size(), 0);

    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);

    arr.push_back(a_ptr);

    EXPECT_EQ(arr.size(), 1);
}

TEST(array_test03, list_constructor){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

    EXPECT_EQ(arr.size(), 3);
}

TEST(array_test04, copy_constructor){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

   Array<std::shared_ptr<Figure>> brr(arr);

    EXPECT_EQ(brr.size(), 3);
    EXPECT_TRUE(arr == brr);
}

TEST(array_test05, move_constructor){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

   Array<std::shared_ptr<Figure>> brr(std::move(arr));

    EXPECT_EQ(brr.size(), 3);
}

TEST(array_test06, sum_array){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

    EXPECT_TRUE(arr.sum() <= 28668 and arr.sum() >= 28667);
}

TEST(array_test07, empty_constructor){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

    EXPECT_EQ(arr.size(), 3);

    arr.delete_elem(0);

    EXPECT_EQ(arr.size(), 2);

    arr.delete_elem(0);

    EXPECT_EQ(arr.size(), 1);
}
