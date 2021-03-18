cmake_minimum_required(VERSION 3.17)
project(hw1 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -ggdb3")

set(LIB_SOURCE_FILES src/date.c src/list.c src/project.c)
include_directories(include)

add_library(project_lib STATIC ${LIB_SOURCE_FILES})
add_executable(hw1 src/main.c)
target_link_libraries(hw1 project_lib)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
message(${GTEST_LIBRARIES})

add_executable(tests tests/tests.cpp)

target_link_libraries(tests ${GTEST_LIBRARIES} -lpthread)
target_link_libraries(tests project_lib)