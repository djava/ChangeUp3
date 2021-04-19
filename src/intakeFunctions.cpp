#include "intakes.h"

namespace intakes {
    void spinMaxIn() {
        for (auto& i: allMotors) {
            i.spin(vex::fwd, voltMax * directionCoeff, vex::volts)
        }
    }

    void spinMaxIn(const intakeMotors& motors...) {
        for (auto& i: {motors...}) {
            intakeEnumToMotor[i].spin(vex::fwd, voltMax * directionCoeff, vex::volts);
        }
    }

    void spinMaxIn(const vex::motor& motors...) {
        for (auto& i: {motors...}) {
            i.spin(vex::fwd, voltMax * directionCoeff, vex::volts);
        }
    }

    void spinMax() {
        spinMaxIn();
    }

    void spinMax(const intakeMotors& motors...) {
        spinMaxIn(motors...);
    }

    void spinMax(const vex::motor& motors...) {
        spinMaxIn(motors...);
    }

    void spinMaxOut() {
        for (auto& i: allMotors) {
            i.spin(vex::fwd, -voltMax * directionCoeff, vex::volts)
        }
    }

    void spinMaxOut(const intakeMotors& motors...) {
        for (auto& i: {motors...}) {
            intakeEnumToMotor[i].spin(vex::fwd, -voltMax * directionCoeff, vex::volts);
        }
    }

    void spinMaxOut(const vex::motor& motors...) {
        for (auto& i: {motors...}) {
            i.spin(vex::fwd, -voltMax * directionCoeff, vex::volts);
        }
    }

    void spinInVolts(const double& volts) {
        for (auto& i: allMotors) {
            i.spin(vex::fwd, volts * directionCoeff, vex::volts)
        }
    }

    void spinInVolts(const double& volts, const intakeMotors& motors...) {
        for (auto& i: {motors...}) {
            intakeEnumToMotor[i].spin(vex::fwd, volts * directionCoeff, vex::volts);
        }
    }

    void spinInVolts(const double& volts, const vex::motor& motors...) {
        for (auto& i: {motors...}) {
            i.spin(vex::fwd, volts * directionCoeff, vex::volts);
        }
    }

    void spinOutVolts(const double& volts) {
        for (auto& i: allMotors) {
            i.spin(vex::fwd, -volts * directionCoeff, vex::volts)
        }
    }

    void spinOutVolts(const double& volts, const intakeMotors& motors...) {
        for (auto& i: {motors...}) {
            intakeEnumToMotor[i].spin(vex::fwd, -volts * directionCoeff, vex::volts);
        }
    }

    void spinOutVolts(const double& volts, const vex::motor& motors...) {
        for (auto& i: {motors...}) {
            i.spin(vex::fwd, -volts * directionCoeff, vex::volts);
        }
    }

    void spinInPct(const double& pct) {
        for (auto& i: allMotors) {
            i.spin(vex::fwd, pct * pctToVoltsCoeff * directionCoeff, vex::volts)
        }
    }

    void spinInPct(const double& pct, const intakeMotors& motors...) {
        for (auto& i: {motors...}) {
            intakeEnumToMotor[i].spin(vex::fwd, pct * pctToVoltsCoeff * directionCoeff, vex::volts);
        }
    }

    void spinInPct(const double& pct, const vex::motor& motors...) {
        for (auto& i: {motors...}) {
            i.spin(vex::fwd, pct * pctToVoltsCoeff * directionCoeff, vex::volts);
        }
    }

    void spinOutPct(const double& pct) {
        for (auto& i: allMotors) {
            i.spin(vex::fwd, -pct * pctToVoltsCoeff * directionCoeff, vex::volts)
        }
    }

    void spinOutPct(const double& pct, const intakeMotors& motors...) {
        for (auto& i: {motors...}) {
            intakeEnumToMotor[i].spin(vex::fwd, -pct * pctToVoltsCoeff * directionCoeff, vex::volts);
        }
    }

    void spinOutPct(const double& pct, const vex::motor& motors...) {
        for (auto& i: {motors...}) {
            i.spin(vex::fwd, -pct * pctToVoltsCoeff * directionCoeff, vex::volts);
        }
    }

    void stopAll() {
        for (auto& i: allMotors) {
            i.stop(vex::brake);
        }
    }

    void stopAll(const vex::brakeType& mode) {
        for (auto& i: allMotors) {
            i.stop(mode);
        }
    }

    void stop() {
        stopAll();
    }

    void stop(const vex::brakeType& mode) {
        stopAll(mode);
    }

    void stop(const intakeMotors& motors...) {
        for (auto& i: {motors...}) {
            intakeEnumToMotor[i].stop(vex::brake);
        }
    }

    void stop(const vex::motor& motors...) {
        for (auto& i: {motors...}) {
            i.stop(vex::brake);
        }
    }

    void stop(const vex::brakeType& mode, const intakeMotors motors...) {
        for (auto& i: {motors...}) {
            intakeEnumToMotor[i].stop(mode);
        }
    }

    void stop(const vex::brakeType& mode, const vex::motor& motors...) {
        for (auto& i: {motors...}) {
            i.stop(mode);
        }
    }
}