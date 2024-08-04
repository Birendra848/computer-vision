# src/image_formation/CMakeLists.txt

# Create a static library from the perspective_projection.cpp file
add_library(image_formation STATIC perspective_projection.cpp)

# Include the header files
target_include_directories(image_formation PUBLIC ${CMAKE_SOURCE_DIR}/include ${PYTHON_INCLUDE_DIRS})

# Link the Python libraries
target_link_libraries(image_formation ${PYTHON_LIBRARIES})
