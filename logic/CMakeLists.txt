file (GLOB LOGIC_SOURCES
        "src/*.cpp"
        "include/*.h"
)

add_library(Logic ${LOGIC_SOURCES})

target_include_directories(Logic
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)