set(RENDERER_SOURCES
        src/main.cpp
        src/Camera.cpp
        include/Camera.h
        src/Game.cpp
        include/Game.h
        src/EntityView.cpp
        include/EntityView.h
        src/StateManager.cpp
        include/StateManager.h
        src/IState.cpp
        include/IState.h
        src/MenuState.cpp
        include/MenuState.h
)

add_executable(Renderer ${RENDERER_SOURCES})

target_link_libraries(Renderer
        PRIVATE
        Logic
)