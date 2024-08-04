cmake_minimum_required(VERSION 3.10)
project(computer_vision)

set(CMAKE_CXX_STANDARD 14)

find_package(Python3 COMPONENTS Development NumPy)
find_package(PythonLibs 3.0 REQUIRED)

include_directories(include ${PYTHON_INCLUDE_DIRS} ${PYTHON_NUMPY_INCLUDE_DIR})

add_executable(perspective_projection 
    src/main.cpp
    src/image_formation/perspective_projection.cpp)

target_link_libraries(perspective_projection ${PYTHON_LIBRARIES})
