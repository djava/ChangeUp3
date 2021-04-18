#pragma once
#include "drivetrainConfig.h"
#include <vex.h>
#include <map>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>

namespace drivetrain {
    typedef enum driveMotors {
        E_MOTOR_BACK_LEFT,
        E_MOTOR_BACK_RIGHT,
        E_MOTOR_FRONT_LEFT,
        E_MOTOR_FRONT_RIGHT
    } driveMotors;

    typedef enum driveSides {
        E_SIDE_LEFT,
        E_SIDE_RIGHT
    } driveSides;

    std::map<driveMotors, vex::motor> motorEnumToMotor {
        {E_MOTOR_BACK_LEFT, BackLeftDrive},
        {E_MOTOR_BACK_RIGHT, BackRightDrive},
        {E_MOTOR_FRONT_LEFT, FrontLeftDrive},
        {E_MOTOR_FRONT_RIGHT, FrontRightDrive}
    };

    std::map<driveSides, std::vector<vex::motor>> sideEnumToMotors {
        {E_SIDE_LEFT, {BackLeftDrive, FrontLeftDrive}},
        {E_SIDE_RIGHT, {BackRightDrive, FrontRightDrive}}
    };

    std::vector<vex::motor> allMotors {
        BackLeftDrive, BackRightDrive, FrontLeftDrive, BackRightDrive
    };

    namespace convert {
        constexpr double drivenWheelRPM = motorRPM * motorToDrivenWheelRatio;

        constexpr double inchesPerDrivenWheelRotation = drivenWheelSizeInInches * M_PI;
        constexpr double inchesPerMotorRotation = inchesPerDrivenWheelRotation * motorToWheelRatio;
        constexpr double inchesPerTrackingWheelRotation = trackingWheelSizeInInches * M_PI;

        constexpr double inchesPerDrivenWheelDegree = inchesPerDrivenWheelRotation / 360.0;
        constexpr double inchesPerMotorDegree = inchesPerMotorRotation / 360.0;
        constexpr double inchesPerTrackingWheelDegree = inchesPerTrackingWheelRotation / 360.0;

        constexpr inline double inchesToDrivenWheelDegrees(double inches) {
            return inches * inchesPerDrivenWheelDegree;
        }

        constexpr inline double inchesToMotorDegrees(double inches) {
            return inches * inchesPerMotorDegree;
        }

        constexpr inline double inchesToTrackingWheelDegree(double inches) {
            return inches * inchesPerTrackingWheelDegree;
        }

        constexpr inline double drivenWheelDegreesToInches(double degrees) {
            return degrees / inchesPerDrivenWheelDegree;
        }

        constexpr inline double motorDegreesToInches(double degrees) {
            return degrees / inchesPerMotorDegree;
        }

        constexpr inline double trackingWheelDegreesToInches(double degrees) {
            return degrees / inchesPerDrivenWheelDegree;
        }
    } // namespace convert

    void resetIMEs(void);
    void resetIMEs(vex::motor motors...);
    void resetIMEs(driveMotors motors...);
    void resetIMEs(driveSides side...);

    // Brake mode by default
    void stopAll(void);
    void stopAll(vex::brakeType mode);

    // No args -> identical to stopAll(void)
    void stop(void);
    // Only mode -> identical to stopAll(vex::brakeType mode)
    void stop(vex::brakeType mode);
    void stop(vex::motor motors...)
    void stop(driveMotors motors...);
    void stop(driveSides sides...);
    void stop(vex::brakeType mode, vex::motor motors...);
    void stop(vex::brakeType mode, driveMotors motors...);
    void stop(vex::brakeType mode, driveSides sides...);
} // namespace drivetrain