#pragma once
#include <vex.h>
#include <utility>
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <sstream>
#include "drivetrain.h"
#include "trackingWheels.h"

typedef enum turnDirection {
    E_TURN_DIRECTION_LEFT,
    E_TURN_DIRECTION_RIGHT
} autonTurnDirection

void turnCurve(const double& targetDistance, const double& leftSpeed, const double& rightSpeed);
void testLinearEquation(double targetDistance, int maxSpeed);
void turn(const autonTurnDirection& direction, const double& degrees);
void dropLinearEquation(double targetDistance, int maxSpeed);
void positionTracking();
void goTo(double finalX, double finalY, autonTurnDirection turnDirection, double kP, double kD, double minSpeed, double errorMargin);
void backLinear(double targetDistance, int minSpeed, double kP);
void IgnoreX(double finalX, double finalY, const autonTurnDirection& turnDirection, double kP, double kD, 
              double minSpeed, double errorMargin);
void IgnoreY(double finalX, double finalY, int turnDirection, double kP, double kD, 
              double minSpeed, double errorMargin);

template <typename T>
T clamp(const T& num, const T& lower, const T& upper) {
    return std::max(lower, std::min(num, upper));
}