cmake_minimum_required(VERSION 3.14)
project(TDD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest 자동 다운로드
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)



# ======================
# Calculator 라이브러리
# ======================
add_library(calculator
    src/calculator/calculator.cpp
)

target_include_directories(calculator PUBLIC include)

# ======================
# 테스트 실행 파일
# ======================
add_executable(calculator_test
    test/calculator/calculator_test.cpp
)

target_link_libraries(calculator_test
    calculator
    GTest::gtest_main
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(calculator_test)