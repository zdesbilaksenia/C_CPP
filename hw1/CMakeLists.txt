cmake_minimum_required(VERSION 3.17)
project(hw1 C)

set(CMAKE_C_STANDARD 99)

add_executable(hw1 src/main.c include/project.h include/date.h src/project.c src/date.c include/list.h src/list.c)

add_subdirectory(tests)