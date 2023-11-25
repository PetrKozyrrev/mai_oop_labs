#include <iostream>
#include <memory>
#include <chrono>
#include <list>
#include <map>
#include <vector>
#include <utility>
#include <list>
#include "allocator.h"
#include "stack.h"

int main(int argc, char **argv){

    std::map<int, int, std::less<int>,mai::Allocator<std::pair<const int,int>,11>> my_map;

    my_map[0] = 1;

    for(int i{1}; i <= 10; ++i){
        my_map[i] = my_map[i-1] * i;
    }

    for(const auto& [k,v]: my_map)
        std::cout << k << "->" << v << std::endl;

    std::cout << "--------------------------\n";

    my_stl::Stack<int,mai::Allocator<int>> my_stack;

    for(int i{100}; i < 110; ++i){
        my_stack.Push(i);
    }

    for(auto it = my_stack.begin(); it != my_stack.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Stack Size = " << my_stack.Size() << std::endl;
    
    my_stack.Pop();

    std::cout << "Stack after Pop" << std::endl;

    my_stack.Show();

    int x = 45;
    my_stack.Push(x);

    my_stack.Show();

    my_stl::Stack<int,mai::Allocator<int>> st(my_stack);

    st.Show();

    return 0;
}