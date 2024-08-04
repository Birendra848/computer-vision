#include "image_formation/perspective_projection.hpp"
#include "matplotlibcpp.h"
#include <iostream>
#include <vector>

namespace plt = matplotlibcpp;

int main() {
    std::vector<double> Z_values;
    std::vector<double> lengths;

    for (double Z = 10; Z <= 1000; Z += 10) {
        auto projected = image_formation::projectLineSegment(Z, 1);
        double length = projected[1].x - projected[0].x;
        Z_values.push_back(Z);
        lengths.push_back(length);
    }

    plt::plot(Z_values, lengths);
    plt::xlabel("Distance Z");
    plt::ylabel("Projected Length");
    plt::title("Projected Length vs Distance");
    plt::show();

    return 0;
}

