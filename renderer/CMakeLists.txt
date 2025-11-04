set(RENDERER_SOURCES
        src/main.cpp
        src/Camera.cpp
        include/Camera.h
        src/Game.cpp
        include/Game.h
        src/entity/EntityView.cpp
        include/entity/EntityView.h
        src/states/StateManager.cpp
        include/states/StateManager.h
        src/states/IState.cpp
        include/states/IState.h
        src/states/MenuState.cpp
        include/states/MenuState.h
)

add_executable(Renderer ${RENDERER_SOURCES})

target_link_libraries(Renderer
        PRIVATE
        Logic
)