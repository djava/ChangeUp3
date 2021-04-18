#pragma once
#include "drivetrainConfig.h"
#include "vex.h"
#include <map>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>

namespace trackingWheels {

    typedef enum trackingWheels {
        E_TRACKING_LEFT,
        E_TRACKING_RIGHT
    } trackingWheels;

    std::map<trackingWheels, vex::rotation> wheelEnumToRotationSensor {
        {E_TRACKING_LEFT, RotationLeft},
        {E_TRACKING_RIGHT, RotationRight}
    };

    std::vector<vex::rotation> allRotationSensors {
        RotationLeft, RotationRight
    };

    namespace convert {
        constexpr double inchesPerWheelRotation = wheelSizeInInches * M_PI;
        constexpr double inchesPerWheelDegree = inchesPerWheelRotation / 360.0;

        constexpr inline double inchesToWheelDegrees(const double& inches) {
            return inches * inchesPerWheelDegree;
        }

        constexpr inline double wheelDegreesToInches(const double& degrees) {
            return degrees / inchesPerDrivenWheelDegree;
        }
    } // namespace convert

    // No args -> reset all
    void resetPositions(void);
    void resetPositions(const trackingWheels& wheels...);
    void resetPositions(const vex::rotation& sensors...);

    double getPosition(const trackingWheels& wheel);
    double getPosition(const vex::rotation& sensor);

    // No args -> avg all wheel positions
    double getAvgPosition(void);
    double getAvgPosition(const trackingWheels& wheels...);
    double getAvgPosition(const vex::rotation& sensors...);
} // namespace trackingWheels