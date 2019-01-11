project(sudoku)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O3 -march=native")

set(SOURCES
  ${PROJECT_SOURCE_DIR}/src/puzzle.cpp
  ${PROJECT_SOURCE_DIR}/src/util.cpp
  ${PROJECT_SOURCE_DIR}/src/solver.cpp
  ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_executable(run ${SOURCES})
