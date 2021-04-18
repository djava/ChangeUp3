#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

namespace drivetrain {
    constexpr double motorRPM = 200.0;
    // Motor-side / Wheel-side 
    constexpr double motorToWheelRatio = 24.0/12.0;
    constexpr double wheelSizeInInches = 4.125;
}

namespace trackingWheels {
    constexpr double wheelSizeInInches = 2.75;
    constexpr double wheelToRotationSensorRatio = 1.0/1.0;
}