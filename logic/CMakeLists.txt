set(LOGIC_SOURCES
        src/world/World.cpp
        include/world/World.h
        src/utils/Stopwatch.cpp
        include/utils/Stopwatch.h
        src/Score.cpp
        include/Score.h
        src/utils/Random.cpp
        include/utils/Random.h
        src/observer/IObserver.cpp
        include/observer/IObserver.h
        include/entity/IEntityModel.h
        src/world/Position.cpp
        include/world/Position.h
        src/observer/IObservable.cpp
        include/observer/IObservable.h
        include/world/ICoordinate.h
        src/world/Size.cpp
        include/world/Size.h
        include/world/IWorldObject.h
        include/world/TileMap.cpp
        include/world/TileMap.h
)

add_library(Logic ${LOGIC_SOURCES})

target_include_directories(Logic
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)