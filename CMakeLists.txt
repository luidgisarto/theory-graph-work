cmake_minimum_required(VERSION 3.17)
project(GraphTheoryWork)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraphTheoryWork main.cpp src/Graph.cpp src/Graph.h src/Edge.cpp src/Edge.h src/Node.cpp src/Node.h src/managers/FileManager.cpp src/managers/FileManager.h src/managers/MenuManager.cpp src/managers/MenuManager.h)