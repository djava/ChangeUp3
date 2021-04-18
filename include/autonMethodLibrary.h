#pragma once
#include <vex.h>
#include <utility>
#define _USE_MATH_DEFINES
#include <cmath>
#include "drivetrain.h"

void testLinearEquation(double targetDistance, int maxSpeed);
void turnRight(double degrees);
void turnLeft(double degrees);
void turnCurve(double targetDistance, double leftSpeed, double rightSpeed);
void turnLeft1(double degrees);
void dropLinearEquation(double targetDistance, int maxSpeed);
void positionTracking();
void goTo(double finalX, double finalY, int turnDirection, double kP, double kD, double minSpeed, double errorMargin);
void backLinear(double targetDistance, int minSpeed, double kP);
void IgnoreX(double finalX, double finalY, int turnDirection, double kP, double kD, 
              double minSpeed, double errorMargin);
void IgnoreY(double finalX, double finalY, int turnDirection, double kP, double kD, 
              double minSpeed, double errorMargin);

template <typename T>
T clamp(const T& num, const T& lower, const T& upper) {
    return std::max(lower, std::min(num, upper));
}