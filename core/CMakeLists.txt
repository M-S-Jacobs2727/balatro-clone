set(SOURCES
    src/Application.h
    # src/Application.cpp
    # src/Window.h
    # src/Window.cpp
    # src/Layer.h
    # src/Layer.cpp
    # src/Event.h
    # src/WindowEvents.h
    # src/InputEvents.h
    # src/Renderer/Renderer.h
    # src/Renderer/Renderer.cpp
    # src/Renderer/Shader.h
    # src/Renderer/Shader.cpp
)

add_library(Core STATIC)

target_sources(Core PRIVATE ${SOURCES})

target_link_libraries(Core PRIVATE SFML::Graphics SFML::System)

target_include_directories(Core PUBLIC "src")