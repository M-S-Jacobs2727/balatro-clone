set(SOURCES
    src/main.cpp
    src/AppLayer.cpp
    src/VoidLayer.cpp
    src/OverlayLayer.cpp
)

add_executable(balatro-clone)

target_sources(balatro-clone PRIVATE ${SOURCES})

target_link_libraries(balatro-clone Core)

target_include_directories(balatro-clone PRIVATE src core)
target_compile_features(balatro-clone PRIVATE cxx_std_23)
