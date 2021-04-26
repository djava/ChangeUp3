#include "lib/HAL/HAL.h"

namespace lib::HAL {
  #ifdef IS_VEXCODE

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

  motor::motor(const int& port, const motorCart& cartridge = motorCart::green_200RPM) 
    : vexMotor{vex::motor (port, HALEnumToVexCart.at(cartridge))} { }

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

  #else

  const std::map<motorCart, pros::motor_gearset_e_t> motor::HALEnumToVexCart {
    {motorCart::red_100RPM, pros::E_MOTOR_GEARSET_36},
    {motorCart::green_200RPM, pros::E_MOTOR_GEARSET_18},
    {motorCart::blue_600RPM, pros::E_MOTOR_GEARSET_06}
  };

  const std::map<brakeMode, pros::motor_brake_mode_e_t> motor::HALEnumToVexBrakeMode {
    {brakeMode::coast, pros::E_MOTOR_BRAKE_COAST},
    {brakeMode::brake, pros::E_MOTOR_BRAKE_BRAKE},
    {brakeMode::hold, pros::E_MOTOR_BRAKE_HOLD}
  };

  motor::motor(const int& port, const motorCart& cartridge = motorCart::green_200RPM) 
    : vexMotor{pros::Motor (port, HALEnumToVexCart.at(cartridge))} { }

  void motor::spinMillivolts(const double& millivolts) {
    vexMotor.move_voltage(millivolts);
  }

  void motor::spinToPosDegRPM(const double& degrees, const double& velocity) {
    vexMotor.move_absolute(degrees, velocity);
  }

  void motor::stop(const brakeMode& mode) {
    vexMotor.set_brake_mode(HALEnumToVexBrakeMode.at(mode));
    vexMotor.move_velocity(0);
  }

  double motor::getIMEPositionDegrees() {
    return vexMotor.get_position();
  }

  void motor::resetIMEPosition() {
    vexMotor.tare_position();
  }

  double motor::getVelocityRPM() {
    return vexMotor.get_actual_velocity();
  }

  double motor::getCurrentAmps() {
    return vexMotor.get_current_draw() / 1000.0;
  }

  double motor::getVoltageMillivolts() {
    return vexMotor.get_voltage();
  }

  double motor::getPowerWatts() {
    return vexMotor.get_power();
  }

  double motor::getTorqueNm() {
    return vexMotor.get_torque();
  }

  double motor::getTemperatureDegC() {
    return vexMotor.get_temperature();
  }

  #endif
}
