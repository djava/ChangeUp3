#pragma once
#include "vex.h"

namespace drivetrain {
    constexpr double motorRPM = 200.0;
    // Motor-side / Wheel-side 
    constexpr double motorToWheelRatio = 24.0/12.0;
    constexpr double wheelSizeInInches = 4.125;

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
}

namespace trackingWheels {
    constexpr double wheelSizeInInches = 2.75;
    constexpr double wheelToRotationSensorRatio = 1.0/1.0;

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
}

namespace intakes {
    constexpr bool fwdToIntake = true;

    typedef enum intakeMotors {
        E_INTAKE_LEFT,
        E_INTAKE_RIGHT
    } intakeMotors;

    std::map<intakeMotors, vex::motor> intakeEnumToMotor {
        {E_INTAKE_LEFT, LeftIntake},
        {E_INTAKE_RIGHT, RightIntake}
    };

    std::vector<vex::motor> allMotors {
        LeftIntake, RightIntake
    };
}