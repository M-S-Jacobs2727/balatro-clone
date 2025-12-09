set(SOURCES
    src/main.cpp
    # src/AppLayer.h
    # src/AppLayer.cpp
    # src/VoidLayer.h
    # src/VoidLayer.cpp
    # src/OverlayLayer.h
    # src/OverlayLayer.cpp
)

add_executable(balatro-clone)

target_sources(balatro-clone PRIVATE ${SOURCES})

# Match VS filters to directory structure on disk
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

add_compile_definitions(
    GLFW_INCLUDE_NONE
)

target_link_libraries(balatro-clone Core)

target_include_directories(balatro-clone PRIVATE src)
target_compile_features(balatro-clone PRIVATE cxx_std_17)
