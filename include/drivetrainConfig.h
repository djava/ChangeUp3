#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

namespace drivetrain {
    /**
     * User configuration
     */
    constexpr double motorRPM = 200.0;
    // Motor-side / Wheel-side 
    constexpr double motorToDrivenWheelRatio = 24.0/12.0;
    constexpr double drivenWheelSizeInInches = 4.125;
    constexpr double trackingWheelSizeInInches = 2.75;
}