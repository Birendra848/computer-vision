cmake_minimum_required(VERSION 3.10)
project(ComputerVision)

set(CMAKE_CXX_STANDARD 17)

# Find and include Eigen
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# Find Python and include its directories
find_package(PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

# Include Matplotlib-cpp
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add source directories
add_subdirectory(src)
