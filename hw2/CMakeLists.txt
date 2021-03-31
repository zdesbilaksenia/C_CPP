cmake_minimum_required(VERSION 3.17)
project(hw2 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)


    include(CodeCoverage)
    append_coverage_compiler_flags()
    setup_target_for_coverage_gcovr_html(
            NAME coverage
            BASE_DIRECTORY "${PROJECT_SOURCE_DIR}"
            EXCLUDE "build/*" "gtests/*" "src/main.c")


find_package (Threads)

add_library(thread_lib SHARED dynamic_lib/threads.c)
target_include_directories(thread_lib PUBLIC dynamic_lib)

add_library(seq_lib STATIC static_lib/seq.c)
target_include_directories(seq_lib PUBLIC static_lib)

set(LIB_SOURCE_FILES src/matrix.c)
include_directories(include)

add_library(project_lib STATIC ${LIB_SOURCE_FILES})
add_executable(hw2 src/main.c)
target_link_libraries(hw2 PRIVATE thread_lib seq_lib project_lib ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
message(${GTEST_LIBRARIES})

add_executable(tests test/test.cpp test/main.cpp)

target_link_libraries(tests PRIVATE thread_lib seq_lib project_lib ${CMAKE_THREAD_LIBS_INIT} ${GTEST_LIBRARIES})

