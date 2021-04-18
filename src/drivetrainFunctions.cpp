#include "drivetrain.h"

namespace drivetrain {
    void resetIMEs() {
        for (auto& i : allMotors) {
            i.resetRotation();
        }
    }

    void resetIMEs(vex::motor motors...) {
        for (auto& i : motors) {
            i.resetRotation();
        }
    }

    void resetIMEs(driveMotors motors...) {
        for (auto& i : motors) {
            motorEnumToMotor[i].resetRotation();
        }
    }

    void resetIMEs(driveSides sides...) {
        for (auto& i : sides) {
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

    void stopAll(vex::brakeType mode) {
        for (auto& i : allMotors) {
            i.stop(mode);
        }
    }

    void stop() {
        stopAll();
    }

    void stop(vex::brakeType mode) { 
        stopAll(mode);
    }

    void stop(vex::motor motors...) {
        for (auto& i : motors) {
            i.stop(vex::brake);
        }
    }

    void stop(driveMotors motors...) {
        for (auto& i : motors) {
            motorEnumToMotor[i].stop(vex::brake);
        }
    }

    void stop(driveSides sides...) {
        for (auto& i : sides) {
            for (auto& j : sideEnumToMotors[i]) {
                i.stop(vex::brake);
            }
        }
    }

    void stop(vex::brakeType mode, vex::motor motors...) {
        for (auto& i : motors) {
            i.stop(mode);
        }
    }

    void stop(vex::brakeType mode, driveMotors motors...) {
        for (auto& i : motors) {
            motorEnumToMotor[i].stop(mode);
        }
    }

    void stop(vex::brakeType mode, driveSides sides...) {
        for (auto& i : sides) {
            for (auto& j : sideEnumToMotors[i]) {
                i.stop(mode);
            }
        }
    }

} // namespace drivetrain