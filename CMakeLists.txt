cmake_minimum_required(VERSION 3.22)

project(NeuralNet VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++")

file(GLOB_RECURSE NN_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(NeuralNet ${NN_SOURCES})
