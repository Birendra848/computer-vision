# src/CMakeLists.txt

# Add the subdirectory for the image_formation module
add_subdirectory(image_formation)

# Add the main executable
add_executable(perspective_projection main.cpp)

# Link the libraries
target_link_libraries(perspective_projection image_formation Eigen3::Eigen ${Python3_LIBRARIES})
