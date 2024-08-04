// This preprocessor directive ensures the header is only included once
#ifndef PERSPECTIVE_PROJECTION_HPP
#define PERSPECTIVE_PROJECTION_HPP

#include <vector> // Include the vector container from the standard library

namespace image_formation { // Start of the image_formation namespace

// Define a structure to represent a 2D point
struct Point2D {
    double x; // x-coordinate
    double y; // y-coordinate
};

// Define a structure to represent a 3D point
struct Point3D {
    double x; // x-coordinate
    double y; // y-coordinate
    double z; // z-coordinate
};

// Function declaration for Exercise 1
// It takes a distance Z and focal length f, returns a vector of 2D points
std::vector<Point2D> projectLineSegment(double Z, double f);

// Function declaration for Exercise 2
// It takes a vector of 3D points (cube) and focal length f, returns a vector of 2D points
std::vector<Point2D> project3DCube(const std::vector<Point3D>& cube, double f);

} // End of namespace image_formation

#endif // End of the include guard
