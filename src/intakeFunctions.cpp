#include "intakes.h"

namespace intakes {
  void spinMaxIn() {
    for (auto& i: allMotors) {
      i.spin(vex::fwd, voltMax * directionCoeff, vex::volt);
    }
  }

  void spinMaxIn(const std::vector<intakeMotors>& motors) {
    for (auto& i: motors) {
      intakeEnumToMotor.at(i).spin(vex::fwd, voltMax * directionCoeff, vex::volt);
    }
  }

  void spinMaxIn(std::vector<vex::motor>& motors) {
    for (auto& i: motors) {
      i.spin(vex::fwd, voltMax * directionCoeff, vex::volt);
    }
  }

  void spinMaxIn(vex::motor& motor) {
    motor.spin(vex::fwd, voltMax * directionCoeff, vex::volt);
  }

  void spinMaxIn(const intakeMotors& motor) {
    intakeEnumToMotor.at(motor).spin(vex::fwd, voltMax * directionCoeff, vex::volt);
  }

  void spinMax() {
    spinMaxIn();
  }

  void spinMax(const std::vector<intakeMotors>& motors) {
    spinMaxIn(motors);
  }

  void spinMax(std::vector<vex::motor>& motors) {
    spinMaxIn(motors);
  }

  void spinMax(const intakeMotors& motors) {
    spinMaxIn(motors);
  }

  void spinMax(vex::motor& motors) {
    spinMaxIn(motors);
  }

  void spinMaxOut() {
    for (auto& i: allMotors) {
      i.spin(vex::fwd, -voltMax * directionCoeff, vex::volt);
    }
  }

  void spinMaxOut(const std::vector<intakeMotors>& motors) {
    for (auto& i: motors) {
      intakeEnumToMotor.at(i).spin(vex::fwd, -voltMax * directionCoeff, vex::volt);
    }
  }

  void spinMaxOut(std::vector<vex::motor>& motors) {
    for (auto& i: motors) {
      i.spin(vex::fwd, -voltMax * directionCoeff, vex::volt);
    }
  }

  void spinMaxOut(const intakeMotors& motor) {
    intakeEnumToMotor.at(motor).spin(vex::fwd, -voltMax * directionCoeff, vex::volt);
  }

  void spinMaxOut(vex::motor& motor) {
    motor.spin(vex::fwd, -voltMax * directionCoeff, vex::volt);
  }

  void spinInVolts(const double& volts) {
    for (auto& i: allMotors) {
      i.spin(vex::fwd, volts * directionCoeff, vex::volt);
    }
  }

  void spinInVolts(const double& volts, const std::vector<intakeMotors>& motors) {
    for (auto& i: motors) {
      intakeEnumToMotor.at(i).spin(vex::fwd, volts * directionCoeff, vex::volt);
    }
  }

  void spinInVolts(const double& volts, std::vector<vex::motor>& motors) {
    for (auto& i: motors) {
      i.spin(vex::fwd, volts * directionCoeff, vex::volt);
    }
  }

  void spinInVolts(const double& volts, const intakeMotors& motor) {
    intakeEnumToMotor.at(motor).spin(vex::fwd, volts * directionCoeff, vex::volt);
  }

  void spinInVolts(const double& volts, vex::motor& motor) {
    motor.spin(vex::fwd, volts * directionCoeff, vex::volt);
  }

  void spinOutVolts(const double& volts) {
    for (auto& i: allMotors) {
      i.spin(vex::fwd, -volts * directionCoeff, vex::volt);
    }
  }

  void spinOutVolts(const double& volts, const std::vector<intakeMotors>& motors) {
    for (auto& i: motors) {
      intakeEnumToMotor.at(i).spin(vex::fwd, -volts * directionCoeff, vex::volt);
    }
  }

  void spinOutVolts(const double& volts, std::vector<vex::motor>& motors) {
    for (auto& i: motors) {
      i.spin(vex::fwd, -volts * directionCoeff, vex::volt);
    }
  }

  void spinOutVolts(const double& volts, const intakeMotors& motor) {
    intakeEnumToMotor.at(motor).spin(vex::fwd, -volts * directionCoeff, vex::volt);
  }

  void spinOutVolts(const double& volts, vex::motor& motor) {
    motor.spin(vex::fwd, -volts * directionCoeff, vex::volt);
  }

  void spinInPct(const double& pct) {
    for (auto& i: allMotors) {
        i.spin(vex::fwd, pct * pctToVoltsCoeff * directionCoeff, vex::volt);
    }
  }

  void spinInPct(const double& pct, const std::vector<intakeMotors>& motors) {
    for (auto& i: motors) {
        intakeEnumToMotor.at(i).spin(vex::fwd, pct * pctToVoltsCoeff * directionCoeff, vex::volt);
    }
  }

  void spinInPct(const double& pct, std::vector<vex::motor>& motors) {
    for (auto& i: motors) {
        i.spin(vex::fwd, pct * pctToVoltsCoeff * directionCoeff, vex::volt);
    }
  }

  void spinInPct(const double& pct, const intakeMotors& motor) {
    intakeEnumToMotor.at(motor).spin(vex::fwd, pct * pctToVoltsCoeff * directionCoeff, vex::volt);
  }

  void spinInPct(const double& pct, vex::motor& motor) {
    motor.spin(vex::fwd, pct * pctToVoltsCoeff * directionCoeff, vex::volt);
  }

  void spinOutPct(const double& pct) {
    for (auto& i: allMotors) {
      i.spin(vex::fwd, -pct * pctToVoltsCoeff * directionCoeff, vex::volt);
    }
  }

  void spinOutPct(const double& pct, const std::vector<intakeMotors>& motors) {
      for (auto& i: motors) {
        intakeEnumToMotor.at(i).spin(vex::fwd, -pct * pctToVoltsCoeff * directionCoeff, vex::volt);
      }
  }

  void spinOutPct(const double& pct, std::vector<vex::motor>& motors) {
      for (auto& i: motors) {
          i.spin(vex::fwd, -pct * pctToVoltsCoeff * directionCoeff, vex::volt);
      }
  }

  void spinOutPct(const double& pct, const intakeMotors& motor) {
    intakeEnumToMotor.at(motor).spin(vex::fwd, -pct * pctToVoltsCoeff * directionCoeff, vex::volt);
  }

  void spinOutPct(const double& pct, vex::motor& motor) {
    motor.spin(vex::fwd, -pct * pctToVoltsCoeff * directionCoeff, vex::volt);
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

  void stop(const std::vector<intakeMotors>& motors) {
      for (auto& i: motors) {
          intakeEnumToMotor.at(i).stop(vex::brake);
      }
  }

  void stop(std::vector<vex::motor>& motors) {
      for (auto& i: motors) {
          i.stop(vex::brake);
      }
  }

  void stop(const vex::brakeType& mode, const std::vector<intakeMotors>& motors) {
      for (auto& i: motors) {
          intakeEnumToMotor.at(i).stop(mode);
      }
  }

  void stop(const vex::brakeType& mode, std::vector<vex::motor>& motors) {
      for (auto& i: motors) {
          i.stop(mode);
      }
  }

  void stop(const intakeMotors& motor) {
    intakeEnumToMotor.at(motor).stop(vex::brake);
  }

  void stop(vex::motor& motor) {
    motor.stop(vex::brake);
  }

  void stop(const vex::brakeType& mode, const intakeMotors& motor) {
    intakeEnumToMotor.at(motor).stop(mode);
  }

  void stop(const vex::brakeType& mode, vex::motor& motor) {
    motor.stop(mode);
  }
}