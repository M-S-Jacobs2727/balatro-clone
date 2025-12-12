cmake_minimum_required(VERSION 3.28)
project(BalatroClone LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

include(dependencies.cmake)

add_subdirectory(core)
add_subdirectory(balatro-clone)
