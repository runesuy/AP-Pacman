file(GLOB_RECURSE LOGIC_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.h
)

add_library(Logic ${LOGIC_SOURCES})

target_include_directories(Logic
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)