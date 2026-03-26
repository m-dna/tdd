cmake_minimum_required(VERSION 3.14)
project(TDD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest 빌드
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(gtest)

option(COVERAGE "Enable coverage" ON)

if(COVERAGE)
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

# ======================
# Calculator 라이브러리(git/tdd/test/)
# ======================
add_library(stick
    src/stick/stick.cpp
)

target_include_directories(stick PUBLIC include)

# ======================
# 테스트 실행 파일
# ======================
add_executable(stick_test
    test/stick/stick_test.cpp
)

target_link_libraries(stick_test
    stick
    GTest::gtest_main
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(stick_test)