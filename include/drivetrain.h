#pragma once
#include "config.h"
#include "vex.h"
#include <map>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>

namespace drivetrain {
    constexpr double pctToVoltsCoeff = 12.0 / 100.0;

    namespace convert {
        constexpr double wheelRPM = motorRPM * motorToWheelRatio;

        constexpr double inchesPerWheelRotation = wheelSizeInInches * M_PI;
        constexpr double inchesPerMotorRotation = inchesPerWheelRotation * motorToWheelRatio;

        constexpr double inchesPerWheelDegree = inchesPerWheelRotation / 360.0;
        constexpr double inchesPerMotorDegree = inchesPerMotorRotation / 360.0;

        constexpr inline double inchesToDrivenWheelDegrees(const double& inches) {
            return inches * inchesPerWheelDegree;
        }

        constexpr inline double inchesToMotorDegrees(const double& inches) {
            return inches * inchesPerMotorDegree;
        }

        constexpr inline double wheelDegreesToInches(const double& degrees) {
            return degrees / inchesPerWheelDegree;
        }

        constexpr inline double motorDegreesToInches(const double& degrees) {
            return degrees / inchesPerMotorDegree;
        }
    } // namespace convert

    void resetIMEs();
    void resetIMEs(std::vector<vex::motor>& motors);
    void resetIMEs(const std::vector<driveMotors>& motors);
    void resetIMEs(const std::vector<driveSides>& sides);
    void resetIMEs(vex::motor& motor);
    void resetIMEs(const driveMotors& motor);
    void resetIMEs(const driveSides& side);

    void stopAll();
    void stopAll(const vex::brakeType& mode);

    void stop();
    void stop(const vex::brakeType& mode);
    void stop(std::vector<vex::motor>& motors);
    void stop(const std::vector<driveMotors>& motors);
    void stop(const std::vector<driveSides>& sides);
    void stop(const driveMotors& motor);
    void stop(const driveSides& side);
    void stop(vex::motor& motor);
    void stop(const vex::brakeType& mode, std::vector<vex::motor>& motors);
    void stop(const vex::brakeType& mode, const std::vector<driveMotors>& motors);
    void stop(const vex::brakeType& mode, const std::vector<driveSides>& sides);
    void stop(const vex::brakeType& mode, vex::motor& motor);
    void stop(const vex::brakeType& mode, const driveMotors& motor);
    void stop(const vex::brakeType& mode, const driveSides& side);

    void spinInVolts(const double& volts);
    void spinInVolts(const double& volts, std::vector<vex::motor>& motors);
    void spinInVolts(const double& volts, const std::vector<driveMotors>& motors);
    void spinInVolts(const double& volts, const std::vector<driveSides>& sides);
    void spinInVolts(const double& volts, vex::motor& motor);
    void spinInVolts(const double& volts, const driveMotors& motor);
    void spinInVolts(const double& volts, const driveSides& side);

    void spinInPct(const double& pct);
    void spinInPct(const double& pct, std::vector<vex::motor>& motors);
    void spinInPct(const double& pct, const std::vector<driveMotors>& motors);
    void spinInPct(const double& pct, const std::vector<driveSides>& sides);
    void spinInPct(const double& pct, vex::motor& motor);
    void spinInPct(const double& pct, const driveSides& side);
    void spinInPct(const double& pct, const driveMotors& motor);
} // namespace drivetrain