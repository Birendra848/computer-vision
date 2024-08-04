#include "image_formation/perspective_projection.hpp" // Include our header file
#include <cmath> // Include for mathematical functions

namespace image_formation { // Start of the image_formation namespace

// Implementation of Exercise 1
std::vector<Point2D> projectLineSegment(double Z, double f) {
    std::vector<Point2D> projectedPoints; // Create a vector to store projected points
    
    // Calculate x-coordinates of projected points using perspective projection formula
    double x1 = -5 * f / Z; // Left point
    double x2 = 5 * f / Z;  // Right point
    
    // Add projected points to the vector
    projectedPoints.push_back({x1, 0}); // Use list initialization to create Point2D
    projectedPoints.push_back({x2, 0});
    
    return projectedPoints; // Return the vector of projected points
}

// Implementation of Exercise 2
std::vector<Point2D> project3DCube(const std::vector<Point3D>& cube, double f) {
    std::vector<Point2D> projectedPoints; // Create a vector to store projected points
    
    // Iterate through each 3D point in the cube
    for (const auto& point : cube) { // Use range-based for loop and auto keyword
        // Apply perspective projection formula
        double x = point.x * f / point.z;
        double y = point.y * f / point.z;
        
        // Add projected 2D point to the vector
        projectedPoints.push_back({x, y});
    }
    
    return projectedPoints; // Return the vector of projected points
}

} // End of namespace image_formation
