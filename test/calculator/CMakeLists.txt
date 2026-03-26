include(GoogleTest)

file(GLOB ALL_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(calculator_test
    ${ALL_SOURCES}
)

target_include_directories(calculator_test PUBLIC 
     ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(calculator_test
    calculator
    GTest::gtest_main
)

gtest_discover_tests(calculator_test)