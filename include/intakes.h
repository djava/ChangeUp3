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
    void spinMax(const std::vector<intakeMotors>& motors);
    void spinMax(std::vector<vex::motor>& motors);
    void spinMax(const intakeMotors& motor);
    void spinMax(vex::motor& motor);

    // No motors specified -> spin all
    void spinMaxIn(void);
    void spinMaxIn(const std::vector<intakeMotors>& motors);
    void spinMaxIn(std::vector<vex::motor>& motors);
    void spinMaxIn(const intakeMotors& motor);
    void spinMaxIn(vex::motor& motor);

    void spinMaxOut(void);
    void spinMaxOut(const std::vector<intakeMotors>& motors);
    void spinMaxOut(std::vector<vex::motor>& motors);
    void spinMaxOut(const intakeMotors& motor);
    void spinMaxOut(vex::motor& motor);

    // No motors specified -> spin all
    void spinInVolts(const double& volts);
    void spinInVolts(const double& volts, const std::vector<intakeMotors>& motors);
    void spinInVolts(const double& volts, std::vector<vex::motor>& motors);
    void spinInVolts(const double& volts, const intakeMotors& motor);
    void spinInVolts(const double& volts, vex::motor& motor);

    void spinOutVolts(const double& volts);
    void spinOutVolts(const double& volts, const std::vector<intakeMotors>& motors);
    void spinOutVolts(const double& volts, std::vector<vex::motor>& motors);
    void spinOutVolts(const double& volts, const intakeMotors& motor);
    void spinOutVolts(const double& volts, vex::motor& motor);

    void spinInPct(const double& pct);
    void spinInPct(const double& pct, std::vector<vex::motor>& motors);
    void spinInPct(const double& pct, const std::vector<intakeMotors>& motors);
    void spinInPct(const double& pct, vex::motor& motor);
    void spinInPct(const double& pct, const intakeMotors& motor);

    void spinOutPct(const double& pct);
    void spinOutPct(const double& pct, const std::vector<intakeMotors>& motors);
    void spinOutPct(const double& pct, std::vector<vex::motor>& motors);
    void spinOutPct(const double& pct, const intakeMotors& motor);
    void spinOutPct(const double& pct, vex::motor& motor);

    // Default to brake mode to be consistent with drive
    void stopAll(void);
    void stopAll(const vex::brakeType& mode);
    
    // No motors specified -> stop all
    // Default to brake mode to be consistent with drive
    void stop(void);
    void stop(const vex::brakeType& mode);
    void stop(const std::vector<intakeMotors>& motors);
    void stop(std::vector<vex::motor>& motors);
    void stop(const vex::brakeType& mode, const std::vector<intakeMotors>& motors);
    void stop(const vex::brakeType& mode, std::vector<vex::motor>& motors);
    void stop(const intakeMotors& motor);
    void stop(vex::motor& motor);
    void stop(const vex::brakeType& mode, const intakeMotors& motors);
    void stop(const vex::brakeType& mode, vex::motor& motors);
}