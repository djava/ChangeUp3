#include "HAL/HAL.h"

namespace HAL {
  const std::map<motorCart, vex::gearSetting> motor::HALEnumToVexCart {
    {motorCart::red_100RPM, vex::ratio36_1},
    {motorCart::green_200RPM, vex::ratio18_1},
    {motorCart::blue_600RPM, vex::ratio6_1}
  };

  const std::map<brakeMode, vex::brakeType> motor::HALEnumToVexBrakeMode {
    {brakeMode::coast, vex::coast},
    {brakeMode::brake, vex::brake},
    {brakeMode::hold, vex::hold}
  };

  motor::motor(const int& port, const motorCart& cartridge = motorCart::green_200RPM, const bool& reversed = false) 
    : cartridge{cartridge},
      vexMotor{vex::motor (port, HALEnumToVexCart.at(cartridge), reversed)},
      port{port},
      reversed{reversed} { }

  void motor::spinMillivolts(const double& millivolts) {
    vexMotor.spin(vex::fwd, millivolts, vex::voltageUnits::mV);
  }

  void motor::spinToPosDegRPM(const double& degrees, const double& velocity) {
    vexMotor.spinToPosition(degrees, vex::deg, velocity, vex::rpm);
  }

  void motor::stop(const brakeMode& mode) {
    vexMotor.stop(HALEnumToVexBrakeMode.at(mode));
  }

  double motor::getIMEPositionDegrees() {
    return vexMotor.position(vex::deg);
  }

  void motor::resetIMEPosition() {
    vexMotor.resetPosition();
  }

  double motor::getVelocityRPM() {
    return vexMotor.velocity(vex::rpm);
  }

  double motor::getCurrentAmps() {
    return vexMotor.current(vex::amp);
  }

  double motor::getVoltageMillivolts() {
    return vexMotor.voltage(vex::voltageUnits::mV);
  }

  double motor::getPowerWatts() {
    return vexMotor.power(vex::watt);
  }

  double motor::getTorqueNm() {
    return vexMotor.torque(vex::Nm);
  }

  double motor::getTemperatureDegC() {
    return vexMotor.temperature(vex::celsius);
  }
}