#include "drivetrain.h"

namespace drivetrain {

  void resetIMEs() {
    for (auto &i : allMotors) {
      i->resetRotation();
    }
  }

  void resetIMEs(std::vector<vex::motor> &motors) {
    for (auto &i : motors) {
      i.resetRotation();
    }
  }

  void resetIMEs(const std::vector<driveMotors> &motors) {
    for (auto i : motors) {
      motorEnumToMotor[i]->resetRotation();
    }
  }

  void resetIMEs(const std::vector<driveSides> &sides) {
    for (auto &i : sides) {
      for (auto &j : sideEnumToMotors[i]) {
        j->resetRotation();
      }
    }
  }

  void resetIMEs(vex::motor &motor) { motor.resetRotation(); }

  void resetIMEs(const driveMotors &motor) {
    motorEnumToMotor[motor]->resetRotation();
  }

  void resetIMEs(const driveSides &side) {
    for (auto &i : sideEnumToMotors[side]) {
      i->resetRotation();
    }
  }

  // Defaults to "Brake" mode if none specified
  void stopAll() {
    for (auto &i : allMotors) {
      i->stop(vex::brake);
    }
  }

  void stopAll(const vex::brakeType &mode) {
    for (auto &i : allMotors) {
      i->stop(mode);
    }
  }

  void stop() { stopAll(); }

  void stop(const vex::brakeType &mode) { stopAll(mode); }

  void stop(std::vector<vex::motor> &motors) {
    for (auto &i : motors) {
      i.stop(vex::brake);
    }
  }

  void stop(const std::vector<driveMotors> &motors) {
    for (driveMotors i : motors) {
      motorEnumToMotor[i]->stop(vex::brake);
    }
  }

  void stop(const std::vector<driveSides> &sides) {
    for (auto i : sides) {
      for (auto &j : sideEnumToMotors[i]) {
        j->stop(vex::brake);
      }
    }
  }

  void stop(vex::motor &motor) {
    motor.stop(vex::brake);
  }

  void stop(const driveMotors &motor) {
    motorEnumToMotor[motor]->stop(vex::brake);
    
  }

  void stop(const driveSides &side) {
    for (auto &j : sideEnumToMotors[side]) {
      j->stop(vex::brake);
    }
  }

  void stop(const vex::brakeType &mode, std::vector<vex::motor> &motors) {
    for (auto &i : motors) {
      i.stop(mode);
    }
  }

  void stop(const vex::brakeType &mode, const std::vector<driveMotors> &motors) {
    for (auto i : motors) {
      motorEnumToMotor[i]->stop(mode);
    }
  }

  void stop(const vex::brakeType &mode, const std::vector<driveSides> &sides) {
    for (auto i : sides) {
      for (auto &j : sideEnumToMotors[i]) {
        j->stop(mode);
      }
    }
  }

  void stop(const vex::brakeType &mode, vex::motor &motor) {
    motor.stop(mode);
    
  }

  void stop(const vex::brakeType &mode, const driveMotors &motor) {
    motorEnumToMotor[motor]->stop(mode);
  }

  void stop(const vex::brakeType &mode, const driveSides &side) {
    for (auto &j : sideEnumToMotors[side]) {
      j->stop(mode);
    }
  }

  void spinInVolts(const double &volts) {
    for (auto &i : allMotors) {
      i->spin(vex::fwd, volts, vex::volt);
    }
  }

  void spinInVolts(const double &volts, std::vector<vex::motor> &motors) {
    for (auto &i : motors) {
      i.spin(vex::fwd, volts, vex::volt);
    }
  }

  void spinInVolts(const double &volts, std::vector<driveMotors> &motors) {
    for (auto i : motors) {
      motorEnumToMotor[i]->spin(vex::fwd, volts, vex::volt);
    }
  }

  void spinInVolts(const double &volts, std::vector<driveSides> &sides) {
    for (auto i : sides) {
      for (auto &j : sideEnumToMotors[i]) {
        j->spin(vex::fwd, volts, vex::volt);
      }
    }
  }

  void spinInVolts(const double &volts, vex::motor &motor) {
    motor.spin(vex::fwd, volts, vex::volt);
  }

  void spinInVolts(const double &volts, driveMotors &motor) {

    motorEnumToMotor[motor]->spin(vex::fwd, volts, vex::volt);
  }

  void spinInVolts(const double &volts, const driveSides &side) {
    for (auto &j : sideEnumToMotors[side]) {
      j->spin(vex::fwd, volts, vex::volt);
    }
  }

  void spinInPct(const double &pct) { spinInVolts(pct * pctToVoltsCoeff); }

  void spinInPct(const double &pct, std::vector<vex::motor> &motors) {
    spinInVolts(pct * pctToVoltsCoeff, motors);
  }

  void spinInPct(const double &pct, const std::vector<driveMotors> &motors) {
    spinInVolts(pct * pctToVoltsCoeff, motors);
  }

  void spinInPct(const double &pct, const std::vector<driveSides> &sides) {
    spinInVolts(pct, sides);
  }

  void spinInPct(const double &pct, vex::motor &motor) {
    spinInVolts(pct * pctToVoltsCoeff, motor);
  }

  void spinInPct(const double &pct, const driveMotors &motor) {
    spinInVolts(pct * pctToVoltsCoeff, motor);
  }

  void spinInPct(const double &pct, const driveSides &side) {
    spinInVolts(pct, side);
  }
} // namespace drivetrain