# Copyright (c) 2022. Johan Lind

cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

set(JLE_ENGINE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
cmake_path(GET JLE_ENGINE_PATH PARENT_PATH enginePath)
set(JLE_ENGINE_PATH "${enginePath}/jle/engine")

message("The absolute engine path is \"${JLE_ENGINE_PATH}\"")

include(${JLE_ENGINE_PATH}/cmake/game1.cmake)

project(${JLE_GAME_BUILD})

add_executable(${JLE_GAME_BUILD}
        "cgfx.cpp"
        "main.cpp"
        "cSineWave.cpp")

include(${JLE_ENGINE_PATH}/cmake/game2.cmake)

if (BUILD_GHA)
    set(CMAKE_C_COMPILER ccache "${EMSCRIPTEN_ROOT_PATH}/emcc${EMCC_SUFFIX}")
    set(CMAKE_CXX_COMPILER ccache "${EMSCRIPTEN_ROOT_PATH}/em++${EMCC_SUFFIX}")
    message("The C Compiler Is: \"${CMAKE_C_COMPILER}\"")
    message("The CXX Compiler Is: \"${CMAKE_CXX_COMPILER}\"")
endif ()