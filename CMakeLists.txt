cmake_minimum_required(VERSION 3.28)
project(BalatroClone LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(balatro 
    src/main.cpp
    src/Game.cpp
    src/model/GameModel.cpp
    src/view/GameView.cpp
    src/controller/GameController.cpp
)
target_compile_features(balatro PRIVATE cxx_std_17)
target_link_libraries(balatro PRIVATE SFML::Graphics)