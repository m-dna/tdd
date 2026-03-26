cmake_minimum_required(VERSION 3.14)
project(TDD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/calculator)
add_subdirectory(src/bj1094)



# GoogleTest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(gtest)
add_subdirectory(test/calculator)
add_subdirectory(test/bj1094)

option(COVERAGE "Enable coverage" ON)

if(COVERAGE)
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

enable_testing()
include(GoogleTest)