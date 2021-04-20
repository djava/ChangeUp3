#pragma once
#include "vex.h"
#include <map>
#include <vector>
#include <memory>

namespace drivetrain {
    constexpr double motorRPM = 200.0;
    // Motor-side / Wheel-side 
    constexpr double motorToWheelRatio = 24.0/12.0;
    constexpr double wheelSizeInInches = 4.125;

    typedef enum class driveMotors {
        backLeft,
        backRight,
        frontLeft,
        frontRight
    } motors;

    typedef enum class driveSides {
        left,
        right
    } sides;

    static std::map<driveMotors, vex::motor> motorEnumToMotor {
        {motors::backLeft, BackLeftDrive},
        {motors::backRight, BackRightDrive},
        {motors::frontLeft, FrontLeftDrive},
        {motors::frontRight, FrontRightDrive}
    };

    static std::map<driveSides, std::vector<vex::motor>> sideEnumToMotors {
        {sides::left, {BackLeftDrive, FrontLeftDrive}},
        {sides::right, {BackRightDrive, FrontRightDrive}}
    };

    static std::vector<vex::motor> allMotors {
        BackLeftDrive, BackRightDrive, FrontLeftDrive, BackRightDrive
    };
}

namespace trackingWheels {
    constexpr double wheelSizeInInches = 2.75;
    constexpr double wheelToRotationSensorRatio = 1.0/1.0;

    typedef enum class trackingWheels {
        left,
        right
    } wheels;

    static std::map<trackingWheels, vex::rotation> wheelEnumToRotationSensor {
        {wheels::left, LeftRotation},
        {wheels::right, RightRotation}
    };

    static std::vector<vex::rotation> allRotationSensors {
        RightRotation, LeftRotation
    };
}

namespace intakes {
    constexpr bool fwdToIntake = true;

    typedef enum class intakeMotors {
        left,
        right
    } motors;

    static std::map<intakeMotors, vex::motor> intakeEnumToMotor {
        {motors::left, LeftIntake},
        {motors::right, RightIntake}
    };

    static std::vector<vex::motor> allMotors {
        LeftIntake, RightIntake
    };
}