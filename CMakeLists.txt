cmake_minimum_required(VERSION 3.15...3.27)

project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(_core src/C++/main.cpp src/C++/benchmarkfcns.cpp
                    src/C++/multifidelity.cpp src/C++/multiobjective.cpp)
target_link_libraries(_core PRIVATE Python3::Module)
target_include_directories(_core PRIVATE ./src/C++/eigen-3.4.0)
target_link_libraries(_core PRIVATE pybind11::module)
target_compile_definitions(_core PRIVATE VERSION_INFO=${PROJECT_VERSION})

# message(STATUS "Python version: ${Python3_VERSION}") message(STATUS "Python
# library: ${Python3_LIBRARY}") message(STATUS "Python include dir:
# ${Python3_INCLUDE_DIRS}")

install(TARGETS _core DESTINATION benchmarkfcns)
