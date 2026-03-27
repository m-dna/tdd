include(GoogleTest)

file(GLOB ALL_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(queue_test
    ${ALL_SOURCES}
)

target_include_directories(queue_test PUBLIC 
     ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(queue_test
    GTest::gtest_main
)

gtest_discover_tests(queue_test)