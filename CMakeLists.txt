# [cite_start]Require CMake 3.15+ (matching scikit-build-core) [cite: 1]
cmake_minimum_required(VERSION 3.15...3.27)

# [cite_start]project name and version are automatically passed from
# pyproject.toml [cite: 2]
project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Modern Python Discovery scikit-build-core provides the Python_EXECUTABLE and
#   hint paths. We only need one robust find_package call.
find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)

# 1. Pybind11 Discovery Since pybind11 is in your build-system.requires, it is
#   available in the build env.
find_package(pybind11 CONFIG REQUIRED)

# 1. Include Directories It's better to use target_include_directories to keep
#   scope clean.
include_directories(./src/C++/eigen-3.4.0)

# 1. Create the Module We use Python_add_library (from FindPython) which handles
#   the suffix (.pyd/.so) and linking requirements automatically.
python_add_library(_core MODULE src/C++/main.cpp src/C++/benchmarkfcns.cpp
                   src/C++/multifidelity.cpp WITH_SOABI)

# 1. Link Dependencies Link against the specific Python and pybind11 targets
target_link_libraries(_core PRIVATE pybind11::headers)

# Passing version as a define
target_compile_definitions(_core PRIVATE VERSION_INFO=${PROJECT_VERSION})

# 1. Installation The DESTINATION should match the folder name in your
#   'wheel.packages' setting
install(TARGETS _core DESTINATION benchmarkfcns)
