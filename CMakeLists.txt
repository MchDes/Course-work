cmake_minimum_required(VERSION 3.16)

project(QUADRAT-SOLVER)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)

add_executable(solver
  main.cpp
)

file(GLOB_RECURSE COMPILER_SOURCES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp)

target_sources(solver
  PRIVATE
    ${COMPILER_SOURCES}
)

target_include_directories(solver PUBLIC
  ${PROJECT_SOURCE_DIR}/include/.
  ${PROJECT_SOURCE_DIR}/third_party/tabulate/include/.
)

add_subdirectory(third_party)
