g++ main.cpp

valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./a.out