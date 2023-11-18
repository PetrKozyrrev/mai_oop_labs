#include <gtest/gtest.h>
#include <map>
#include <vector>
#include "allocator.h"
#include "stack.h"

TEST(allocator_01, map_alloc_test)
{
    std::map<int, int, std::less<int>,mai::Allocator<std::pair<const int,int>,11>> my_map;

    my_map[0] = 1;

    for(int i{1}; i <= 10; ++i){
        my_map[i] = my_map[i-1] * i;
    }

    EXPECT_EQ(24,my_map[4]);
}

TEST(allocator_02, vector_alloc_test)
{
    std::vector<int, mai::Allocator<int>> vec;

    vec.push_back(1);

    EXPECT_EQ(1, vec[0]);
}

TEST(stack_01, stack_basis_constructor01)
{
    my_stl::Stack<int> st;

    EXPECT_EQ(0,st.Size());
}

TEST(stack_02, stack_basis_constructor02)
{
    my_stl::Stack<int> st;

    EXPECT_EQ(true, st.IsEmpty());
}

TEST(stack_03, stack_basis_constructor03)
{
    my_stl::Stack<int> st;

    for(int i{0}; i < 10; ++i){
        st.Push(i);
    }

    EXPECT_EQ(10, st.Size());
}

TEST(stack_04, stack_basis_constructor04)
{
    my_stl::Stack<int> st;

    for(int i{0}; i < 10; ++i){
        st.Push(i);
    }

    EXPECT_EQ(9, st.Top());
}

TEST(stack_05, stack_basis_constructor05)
{
    my_stl::Stack<int> st;

    for(int i{0}; i < 10; ++i){
        st.Push(i);
    }

    st.Pop();

    EXPECT_EQ(9, st.Size());
    EXPECT_EQ(false, st.IsEmpty());
}

TEST(stack_06, stack_copy_constructor01)
{
    my_stl::Stack<int> st1;

    for(int i{0}; i < 10; ++i){
        st1.Push(i);
    }

    my_stl::Stack<int> st2(st1);

    EXPECT_EQ(10, st2.Size());
}

TEST(stack_07, stack_copy_constructor02)
{
    my_stl::Stack<int> st1;

    for(int i{0}; i < 10; ++i){
        st1.Push(i);
    }

    my_stl::Stack<int> st2(st1);

    std::cout << st2.Top() << std::endl;

    EXPECT_EQ(9, st2.Top());
}

TEST(stack_08, stack_copy_constructor03)
{
    my_stl::Stack<int> st1;

    for(int i{0}; i < 10; ++i){
        st1.Push(i);
    }

    my_stl::Stack<int> st2(st1);

    st2.Push(5);

    EXPECT_EQ(10, st1.Size());
    EXPECT_EQ(11, st2.Size());
}

TEST(stack_09, stack_move_constructor01)
{
    my_stl::Stack<int> st1;

    for(int i{0}; i < 10; ++i){
        st1.Push(i);
    }

    my_stl::Stack<int> st2(std::move(st1));

    EXPECT_EQ(10, st2.Size());
}

TEST(stack_10, stack_move_constructor02)
{
    my_stl::Stack<int> st1;

    for(int i{0}; i < 10; ++i){
        st1.Push(i);
    }

    my_stl::Stack<int> st2(std::move(st1));

    st2.Pop();

    EXPECT_EQ(9, st2.Size());
}

TEST(stack_11, stack_copy_operation)
{
    my_stl::Stack<int> st1;

    for(int i{0}; i < 10; ++i){
        st1.Push(i);
    }

    my_stl::Stack<int> st2 = st1;

    st2.Pop();

    EXPECT_EQ(9, st2.Size());
}

TEST(stack_12, Iterator_01)
{
    my_stl::Stack<int> st1;

    for(int i{0}; i < 10; ++i){
        st1.Push(i);
    }

    auto it = st1.begin();

    EXPECT_EQ(9, *it);
}

TEST(stack_13, Iterator_02)
{
    my_stl::Stack<int> st1;

    for(int i{0}; i < 10; ++i){
        st1.Push(i);
    }

    auto it = st1.begin();
    EXPECT_EQ(9, *it);

    it++;
    EXPECT_EQ(8, *it);

    it++;
    EXPECT_EQ(7, *it);
}

TEST(stack_14, CosntIterator_01)
{
    my_stl::Stack<int> st1;

    for(int i{0}; i < 10; ++i){
        st1.Push(i);
    }

    auto it = st1.cbegin();

    EXPECT_EQ(9, *it);
}

TEST(stack_15, ConstIterator_02)
{
    my_stl::Stack<int> st1;

    for(int i{0}; i < 10; ++i){
        st1.Push(i);
    }

    auto it = st1.cbegin();
    EXPECT_EQ(9, *it);

    it++;
    EXPECT_EQ(8, *it);

    it++;
    EXPECT_EQ(7, *it);
}