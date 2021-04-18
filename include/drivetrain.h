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

    std::map<driveMotors, vex::motor&> motorEnumToMotor {
        {E_MOTOR_BACK_LEFT, BackLeftDrive},
        {E_MOTOR_BACK_RIGHT, BackRightDrive},
        {E_MOTOR_FRONT_LEFT, FrontLeftDrive},
        {E_MOTOR_FRONT_RIGHT, FrontRightDrive}
    };

    std::map<driveSides, std::vector<vex::motor&>> sideEnumToMotors {
        {E_SIDE_LEFT, {BackLeftDrive, FrontLeftDrive}},
        {E_SIDE_RIGHT, {BackRightDrive, FrontRightDrive}}
    };

    std::vector<vex::motor&> allMotors {
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

        constexpr inline double inchesToDrivenWheelDegrees(const double& inches) {
            return inches * inchesPerDrivenWheelDegree;
        }

        constexpr inline double inchesToMotorDegrees(const double& inches) {
            return inches * inchesPerMotorDegree;
        }

        constexpr inline double inchesToTrackingWheelDegree(const double& inches) {
            return inches * inchesPerTrackingWheelDegree;
        }

        constexpr inline double drivenWheelDegreesToInches(const double& degrees) {
            return degrees / inchesPerDrivenWheelDegree;
        }

        constexpr inline double motorDegreesToInches(const double& degrees) {
            return degrees / inchesPerMotorDegree;
        }

        constexpr inline double trackingWheelDegreesToInches(const double& degrees) {
            return degrees / inchesPerDrivenWheelDegree;
        }
    } // namespace convert

    void resetIMEs(void);
    void resetIMEs(const vex::motor& motors...);
    void resetIMEs(const driveMotors& motors...);
    void resetIMEs(const driveSides& side...);

    // Brake mode by default
    void stopAll(void);
    void stopAll(const vex::brakeType& mode);

    // No args -> identical to stopAll(void)
    void stop(void);
    // Only mode -> identical to stopAll(vex::brakeType mode)
    void stop(const vex::brakeType& mode);
    void stop(const vex::motor& motors...)
    void stop(const driveMotors& motors...);
    void stop(const driveSides& sides...);
    void stop(const vex::brakeType& mode, const vex::motor& motors...);
    void stop(const vex::brakeType& mode, const driveMotors& motors...);
    void stop(const vex::brakeType& mode, const driveSides& sides...);

    // No motors specified -> spin all
    void spinInVolts(const double& volts);
    void spinInVolts(const double& volts, vex::motor motors...);
    void spinInVolts(const double& volts, const driveMotors& motors...);
    void spinInVolts(const double& volts, const driveSides& sides...);
} // namespace drivetrain