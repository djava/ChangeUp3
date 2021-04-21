#pragma once
#include <vex.h>
#include <utility>
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <sstream>
#include "drivetrain.h"
#include "trackingWheels.h"

typedef enum class turnDirection {
    left,
    right,
    none
} turnDirection;

void turnCurve(const double& targetDistance, const double& leftSpeed, const double& rightSpeed);
void testLinearEquation(double targetDistance, int maxSpeed);
void turn(const turnDirection& direction, const double& degrees);
void dropLinearEquation(double targetDistance, int maxSpeed);
void positionTracking();
void goTo(double finalX, double finalY, turnDirection turnDirection, double kP, double kD, double minSpeed, double errorMargin);
void backLinear(double targetDistance, double minSpeed, double kP);
void IgnoreX(double finalX, double finalY, const turnDirection& turnDirection, double kP, double kD, 
              double minSpeed, double errorMargin);
void IgnoreY(double finalX, double finalY, const turnDirection& turnDirection, double kP, double kD, 
              double minSpeed, double errorMargin);
void setCoordinates(int changeNumber);

template <typename T>
T clamp(const T& num, const T& lower, const T& upper) {
    return std::max(lower, std::min(num, upper));
}