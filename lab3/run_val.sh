#!/bin/bash

# Создание файла сборки
mkdir -p build
cd build
cmake ..

# Сборка проекта
make

# Запуск Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./tests
#valgrind ./app

# Очистка
make clean
cd ..