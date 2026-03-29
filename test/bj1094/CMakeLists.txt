include(GoogleTest)

file(GLOB ALL_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(bj1094_test
    ${ALL_SOURCES}
)

target_include_directories(bj1094_test PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(bj1094_test
    bj1094
    GTest::gtest_main
)

gtest_discover_tests(bj1094_test)