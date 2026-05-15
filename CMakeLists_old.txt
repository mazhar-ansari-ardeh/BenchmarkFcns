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

if(APPLE)
  # Try to find libomp via Homebrew or provided prefixes
  if(NOT OpenMP_ROOT AND DEFINED ENV{CMAKE_PREFIX_PATH})
    set(OpenMP_ROOT $ENV{CMAKE_PREFIX_PATH})
  endif()

  find_library(
    OpenMP_omp_LIBRARY
    NAMES omp
    HINTS ${OpenMP_ROOT}/lib /opt/homebrew/opt/libomp/lib
          /usr/local/opt/libomp/lib)
  find_path(
    OpenMP_CXX_INCLUDE_DIR
    NAMES omp.h
    HINTS ${OpenMP_ROOT}/include /opt/homebrew/opt/libomp/include
          /usr/local/opt/libomp/include)

  if(OpenMP_omp_LIBRARY AND OpenMP_CXX_INCLUDE_DIR)
    # Help FindOpenMP by providing the flags it struggles to find with Apple
    # Clang
    set(OpenMP_CXX_FLAGS
        "-Xpreprocessor -fopenmp -I${OpenMP_CXX_INCLUDE_DIR}"
        CACHE STRING "")
    set(OpenMP_CXX_LIB_NAMES
        "omp"
        CACHE STRING "")
    set(OpenMP_omp_LIBRARY
        "${OpenMP_omp_LIBRARY}"
        CACHE FILEPATH "")
    set(OpenMP_CXX_LIBRARIES
        "${OpenMP_omp_LIBRARY}"
        CACHE STRING "")
    set(OpenMP_CXX_INCLUDE_DIRS
        "${OpenMP_CXX_INCLUDE_DIR}"
        CACHE STRING "")
  endif()
endif()

find_package(OpenMP REQUIRED)

if(OpenMP_FOUND)
  message(STATUS "OpenMP found")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS
      "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
  set(CMAKE_SHARED_LINKER_FLAGS
      "${CMAKE_SHARED_LINKER_FLAGS} ${OpenMP_SHARED_LINKER_FLAGS}")
else()
  message(FATAL_ERROR "OpenMP not found")
endif()

pybind11_add_module(
  _core
  src/C++/main.cpp
  src/C++/benchmarkfcns.cpp
  src/C++/multifidelity.cpp
  src/C++/multiobjective.cpp
  src/C++/composition.cpp
  src/C++/cec_data.cpp
  src/C++/cec.cpp)
target_link_libraries(_core PRIVATE Python3::Module OpenMP::OpenMP_CXX)
target_include_directories(_core PRIVATE ./src/C++/eigen-3.4.0)
target_link_libraries(_core PRIVATE pybind11::module)
target_compile_definitions(_core PRIVATE VERSION_INFO=${PROJECT_VERSION})
if(WIN32)
  target_compile_definitions(_core PRIVATE _USE_MATH_DEFINES)
endif()

# message(STATUS "Python version: ${Python3_VERSION}") message(STATUS "Python
# library: ${Python3_LIBRARY}") message(STATUS "Python include dir:
# ${Python3_INCLUDE_DIRS}")

install(TARGETS _core DESTINATION benchmarkfcns)
