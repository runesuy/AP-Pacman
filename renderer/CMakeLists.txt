set(RENDERER_SOURCES
        src/main.cpp
        src/utils/Camera.cpp
        include/utils/Camera.h
        src/Game.cpp
        include/Game.h
        src/entity/EntityView.cpp
        include/entity/EntityView.h
        src/states/StateManager.cpp
        include/states/StateManager.h
        src/states/IState.cpp
        include/states/IState.h
        src/states/menu/MenuState.cpp
        include/states/menu/MenuState.h
        src/states/DelegatingState.cpp
        include/states/DelegatingState.h
        src/core/IInputHandler.cpp
        include/core/IInputHandler.h
        src/core/IUpdateHandler.cpp
        include/core/IUpdateHandler.h
        src/core/IDrawHandler.cpp
        include/core/IDrawHandler.h
        src/states/menu/MenuUpdateHandler.cpp
        include/states/menu/MenuUpdateHandler.h
        src/states/menu/MenuDrawHandler.cpp
        include/states/menu/MenuDrawHandler.h
        src/states/menu/MenuInputHandler.cpp
        include/states/menu/MenuInputHandler.h
        src/states/StateManagerFactory.cpp
        include/states/StateManagerFactory.h
        src/states/IStateFactory.cpp
        include/states/IStateFactory.h
        src/states/DefaultStateFactory.cpp
        include/states/DefaultStateFactory.h
        src/config/IFactoryCollection.cpp
        include/config/IFactoryCollection.h
        src/config/DefaultFactoryCollection.cpp
        include/config/DefaultFactoryCollection.h
        src/parser/IConfigParser.cpp
        include/parser/IConfigParser.h
        src/parser/JSONConfigParser.cpp
        include/parser/JSONConfigParser.h
        src/exceptions/FileNotOpenedException.cpp
        include/exceptions/FileNotOpenedException.h
        src/config/IAppConfig.cpp
        include/config/IAppConfig.h
        src/config/DefaultAppConfig.cpp
        include/config/DefaultAppConfig.h
        include/drawable/IDrawable.h
        include/drawable/DrawObject.h
        src/drawable/IDrawable.cpp
        src/drawable/DrawObject.cpp
        src/drawable/ui/Button.cpp
        include/drawable/ui/Button.h
)

add_executable(Renderer ${RENDERER_SOURCES})
find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

target_include_directories(Renderer
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

target_include_directories(Renderer
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Renderer
        PRIVATE
        Logic
        sfml-graphics sfml-window sfml-system

)