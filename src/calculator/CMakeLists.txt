file(GLOB ALL_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(calculator
    ${ALL_SOURCES}
)

target_include_directories(calculator PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
)