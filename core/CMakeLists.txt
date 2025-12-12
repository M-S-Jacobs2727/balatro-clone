set(SOURCES
    src/Application.h
    src/Application.cpp
    src/Layer.h
    src/Layer.cpp
)

add_library(Core STATIC)

target_sources(Core PRIVATE ${SOURCES})

target_link_libraries(Core SFML::Graphics)

target_include_directories(Core PUBLIC "src")
target_compile_features(Core PRIVATE cxx_std_23)
