file(GLOB_RECURSE RENDERER_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.h
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