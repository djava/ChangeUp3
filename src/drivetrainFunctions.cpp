#include "drivetrain.h"

namespace drivetrain {
    void resetIMEs() {
        for (auto& i : allMotors) {
            i.resetRotation();
        }
    }

    void resetIMEs(const vex::motor& motors...) {
        for (auto& i : {motors...}) {
            i.resetRotation();
        }
    }

    void resetIMEs(const driveMotors& motors...) {
        for (auto& i : {motors...}) {
            motorEnumToMotor[i].resetRotation();
        }
    }

    void resetIMEs(const driveSides& sides...) {
        for (auto& i : {sides...}) {
            for (auto& j : sideEnumToMotors[i]) {
                j.resetRotation();
            }
        }
    }

    // Defaults to "Brake" mode if none specified
    void stopAll() {
        for (auto& i : allMotors) {
            i.stop(vex::brake);
        }
    }

    void stopAll(const vex::brakeType& mode) {
        for (auto& i : allMotors) {
            i.stop(mode);
        }
    }

    void stop() {
        stopAll();
    }

    void stop(const vex::brakeType& mode) { 
        stopAll(mode);
    }

    void stop(const vex::motor& motors...) {
        for (auto& i : {motors...}) {
            i.stop(vex::brake);
        }
    }

    void stop(const driveMotors& motors...) {
        for (auto& i : {motors...}) {
            motorEnumToMotor[i].stop(vex::brake);
        }
    }

    void stop(const driveSides& sides...) {
        for (auto& i : {sides...}) {
            for (auto& j : sideEnumToMotors[i]) {
                i.stop(vex::brake);
            }
        }
    }

    void stop(const vex::brakeType& mode, const vex::motor& motors...) {
        for (auto& i : {motors...}) {
            i.stop(mode);
        }
    }

    void stop(const vex::brakeType& mode, driveMotors motors...) {
        for (auto& i : {motors...}) {
            motorEnumToMotor[i].stop(mode);
        }
    }

    void stop(const vex::brakeType& mode, driveSides sides...) {
        for (auto& i : {sides...}) {
            for (auto& j : sideEnumToMotors[i]) {
                i.stop(mode);
            }
        }
    }

    void spinInVolts(const double& volts) {
        for (auto& i : allMotors) {
            i.spin(vex::fwd, volts, vex::volts);
        }
    }

    void spinInVolts(const double& volts, const vex::motor& motors...) {
        for (auto& i : {motors...}) {
            i.spin(vex::fwd, volts, vex::volts);
        }
    }

    void spinInVolts(const double& volts, const driveMotors& motors...) {
        for (auto& i : {motors...}) {
            motorEnumToMotor[i].spin(vex::fwd, volts, vex::volts);
        }
    }

    void spinInVolts(const double& volts, const driveSides& sides...) {
        for (auto& i : {sides...}) {
            for (auto& j : sideEnumToMotors[i]) {
                i.spin(vex::fwd, volts, vex::volts);
            }
        }
    }

    void spinInPct(const double& pct) {
        spinInVolts(pct * pctToVoltsCoeff);
    }

    void spinInPct(const double& pct, const vex::motor& motors...) {
        spinInVolts(pct * pctToVoltsCoeff, motors...);
    }

    void spinInPct(const double& pct, const driveMotors& motors...) {
        spinInVolts(pct * pctToVoltsCoeff, motors...);
    }

    void spinInPct(const double& pct, const driveSides& sides...) {
        spinInVolts(pct, sides...);
    }
} // namespace drivetrain