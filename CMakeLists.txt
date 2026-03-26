cmake_minimum_required(VERSION 3.14)
project(TDD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest 빌드
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(gtest)

enable_testing()
include(GoogleTest)

option(COVERAGE "Enable coverage" ON)
if(COVERAGE)
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

# ======================
# Calculator 라이브러리
# ======================
add_library(calculator 
    src/calculator/calculator.cpp
)

target_include_directories(calculator PUBLIC include)

add_executable(calculator_test
    test/calculator/calculator_test.cpp
)

target_link_libraries(calculator_test
    calculator
    GTest::gtest_main
)

gtest_discover_tests(calculator_test)


# ======================
# Stick 라이브러리
# ======================
add_library(stick
    src/stick_cheoljun99/stick_cheoljun99.cpp
)
target_include_directories(stick PUBLIC include)

add_executable(stick_test
    test/stick_cheoljun99/stick_cheoljun99_test.cpp
)
target_link_libraries(stick_test
    stick
    GTest::gtest_main
)
gtest_discover_tests(stick_test)