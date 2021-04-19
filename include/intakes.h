#pragma once
#include "config.h"
#include "vex.h"

namespace intakes {
    constexpr double pctToVoltsCoeff = 12.0 / 100.0;
    constexpr double voltMax = 12.0;

    // fwdToIntake is 1 if true, 0 if false
    // This maps true to 1 and false to -1
    constexpr int directionCoeff = (fwdToIntake * 2) - 1;

    void spinMax(void);
    void spinMax(const intakeMotors& motors...);
    void spinMax(const vex::motor& motors...);

    // No motors specified -> spin all
    void spinMaxIn(void);
    void spinMaxIn(const intakeMotors& motors...);
    void spinMaxIn(const vex::motor& motors...);

    void spinMax(void);
    void spinMax(const intakeMotors& motors...);
    void spinMax(const vex::motor& motors...);

    void spinMaxOut(void);
    void spinMaxOut(const intakeMotors& motors...);
    void spinMaxOut(const vex::motor& motors...);

    // No motors specified -> spin all
    void spinInVolts(const double& volts);
    void spinInVolts(const double& volts, const intakeMotors& motors...);
    void spinInVolts(const double& volts, const vex::motor& motors...);

    void spinOutVolts(const double& volts);
    void spinOutVolts(const double& volts, const intakeMotors& motors...);
    void spinOutVolts(const double& volts, const vex::motor& motors...);

    void spinInPct(const double& pct);
    void spinInPct(const double& pct, const vex::motor& motors...);
    void spinInPct(const double& pct, const intakeMotors& motors...);

    void spinOutPct(const double& pct);
    void spinOutPct(const double& pct, const intakeMotors& motors...);
    void spinOutPct(const double& pct, const vex::motor& motors...);

    // Default to brake mode to be consistent with drive
    void stopAll(void);
    void stopAll(const vex::brakeType& mode);
    
    // No motors specified -> stop all
    // Default to brake mode to be consistent with drive
    void stop(void);
    void stop(const vex::brakeType& mode);
    void stop(const intakeMotors& motors...);
    void stop(const vex::motor& motors...);
    void stop(const vex::brakeType& mode, const intakeMotors& motors...);
    void stop(const vex::brakeType& mode, const vex::motor& motors...);
}