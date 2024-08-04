#include "image_formation/perspective_projection.hpp"
#include <cmath>
#include <vector>
#include <matplotlibcpp.h>
#include <Eigen/Dense>

namespace plt = matplotlibcpp;

// Function to plot how the projected length changes with distance Z
void plotLengthChanges(double Xa, double Xb) {
    double f = 1; // Focal length
    std::vector<double> projections;

    // Loop through different distances (Z)
    for (int i = 10; i < 1000; ++i) {
        // Calculate the projected lengths of points Xa and Xb
        double a = (-f * Xa) / i;
        double b = (-f * Xb) / i;

        // Calculate the distance between the projected points
        double dist = std::sqrt((a - b) * (a - b));
        projections.push_back(dist);
    }

    // Plot the changes in projected length
    plt::plot(projections);
    plt::ylabel("projected length");
    plt::xlabel("distance Z");
    plt::show();
}

// Function to project a cube and plot the projected points
void cubeProjection() {
    // Define the vertices of a cube in homogeneous coordinates (4th column is for affine transformations)
    Eigen::MatrixXd cube(8, 4);
    cube << 0, 0, 0, 1,
            1, 0, 0, 1,
            1, 1, 0, 1,
            0, 1, 0, 1,
            0, 0, 1, 1,
            1, 0, 1, 1,
            1, 1, 1, 1,
            0, 1, 1, 1;

    double f = 1; // Focal length
    double tx = 0; // Translation along x-axis
    double ty = 0; // Translation along y-axis
    double tz = 100; // Translation along z-axis

    // Rotation angles around x, y, and z axes (in radians)
    double Rx = M_PI / 6;  // 30 degrees
    double Ry = M_PI / 6;  // 30 degrees
    double Rz = 0;

    // Rotation matrix around x-axis
    Eigen::Matrix3d RMx;
    RMx << 1, 0, 0,
           0, std::cos(Rx), -std::sin(Rx),
           0, std::sin(Rx), std::cos(Rx);

    // Rotation matrix around y-axis
    Eigen::Matrix3d RMy;
    RMy << std::cos(Ry), 0, std::sin(Ry),
           0, 1, 0,
           -std::sin(Ry), 0, std::cos(Ry);

    // Rotation matrix around z-axis
    Eigen::Matrix3d RMz;
    RMz << std::cos(Rz), -std::sin(Rz), 0,
           std::sin(Rz), std::cos(Rz), 0,
           0, 0, 1;

    // Combined rotation matrix (Z * Y * X)
    Eigen::Matrix3d M = RMz * RMy * RMx;

    // Extrinsic camera matrix (combines rotation and translation)
    Eigen::MatrixXd M_ext(3, 4);
    M_ext << M, Eigen::Vector3d(tx, ty, tz);

    // Intrinsic camera matrix (focal length)
    Eigen::Matrix3d K;
    K << f, 0, 0,
         0, f, 0,
         0, 0, 1;

    std::vector<double> x; // x-coordinates of projected points
    std::vector<double> y; // y-coordinates of projected points

    // Project each vertex of the cube
    for (int i = 0; i < cube.rows(); ++i) {
        Eigen::Vector4d point = cube.row(i).transpose();
        Eigen::Vector3d r = K * (M_ext * point);
        x.push_back(r(0) / r(2)); // Normalize by dividing by z-coordinate
        y.push_back(r(1) / r(2));
    }

    // Plot the projected points
    plt::scatter(x, y);
    plt::xlim(-0.005, 0.02); // Set x-axis limits
    plt::ylim(-0.01, 0.012); // Set y-axis limits
    plt::show();
}
