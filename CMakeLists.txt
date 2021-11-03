cmake_minimum_required(VERSION 3.16)
project(graph_coloring_bee)

set(CMAKE_CXX_STANDARD 20)

add_executable(graph_coloring_bee main.cpp work-classes/Graph.cpp work-classes/Graph.h helpers/Generator.cpp helpers/Generator.h work-classes/AlgorithmABC.cpp work-classes/AlgorithmABC.h)