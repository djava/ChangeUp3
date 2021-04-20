#pragma once
#include "config.h"
#include "vex.h"
#include <map>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>

namespace trackingWheels {

    namespace convert {
        constexpr double inchesPerWheelRotation = wheelSizeInInches * M_PI;
        constexpr double inchesPerWheelDegree = inchesPerWheelRotation / 360.0;

        constexpr inline double inchesToWheelDegrees(const double& inches) {
            return inches * inchesPerWheelDegree;
        }

        constexpr inline double wheelDegreesToInches(const double& degrees) {
            return degrees / inchesPerWheelDegree;
        }
    } // namespace convert

    // No args -> reset all
    void resetPositions(void);
    void resetPositions(const std::vector<trackingWheels>& wheels);
    void resetPositions(std::vector<vex::rotation>& sensors);
    void resetPositions(vex::rotation& sensor);
    void resetPositions(const trackingWheels& wheel);

    double getPosition(const trackingWheels& wheel);
    double getPosition(vex::rotation& sensor);

    // No args -> avg all wheel positions
    double getAvgPosition(void);
    double getAvgPosition(const std::vector<trackingWheels>& wheels);
    double getAvgPosition(std::vector<vex::rotation>& sensors);
} // namespace trackingWheels