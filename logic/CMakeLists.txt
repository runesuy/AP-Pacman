set(LOGIC_SOURCES
        src/World.cpp
        include/World.h
        src/Stopwatch.cpp
        include/Stopwatch.h
        src/Score.cpp
        include/Score.h
        src/Random.cpp
        include/Random.h
        src/IObserver.cpp
        include/IObserver.h
        src/EntityModel.cpp
        include/EntityModel.h
)

add_library(Logic ${LOGIC_SOURCES})

target_include_directories(Logic
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)