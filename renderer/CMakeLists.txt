set(RENDERER_SOURCES
        src/main.cpp
        src/Camera.cpp
        include/Camera.h
        src/Game.cpp
        include/Game.h
        src/EntityView.cpp
        include/EntityView.h
)

add_executable(Renderer ${RENDERER_SOURCES})

target_link_libraries(Renderer
        PRIVATE
        Logic
)