file(GLOB ALL_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(bj1094
    ${ALL_SOURCES}
)

target_include_directories(bj1094 PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
)