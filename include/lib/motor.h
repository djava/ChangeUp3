#pragma once
#include "HAL/HAL.h"
#include "units/units.h"

namespace lib { 
  enum class motorCart {  
    red_100RPM,
    green_200RPM,
    blue_600RPM
  };

  enum class brakeMode {
    coast,
    brake,
    hold
  };

  class motor {
    private:
      static const std::map<motorCart, vex::gearSetting> HALEnumToVexCart;
      static const std::map<brakeMode, vex::brakeType> HALEnumToVexBrakeMode;

      HAL::motor HALMotor;
      QAngle internalIMEAdjustment = 0_deg;

    public:
      const int port;
      const motorCart cartridge;

      bool reversed;
      brakeMode currentBrakeMode;
      std::string nickname;

      motor(const int& port, const motorCart& cartridge, const bool& reversed, const brakeMode& currentBrakeMode, std::string nickname);
      motor(const int& port, const motorCart& cartridge, const brakeMode& currentBrakeMode, std::string nickname);
      motor(const int& port, const bool& reversed, const brakeMode& currentBrakeMode, std::string nickname);
      motor(const int& port, const brakeMode& currentBrakeMode, std::string nickname);

      void spin(const QVoltage& voltage);
      void spin(const QAngularSpeed& velocity);
      void spin(const QPercent& percent);

      void stop(const brakeMode& mode);

      QAngle getIMEPosition();
      void resetIMEPosition(const QAngle& angle);

      QAngularSpeed getVelocity();
      // Current in Amps
      double getCurrent();
      QVoltage getVoltage();
      // Power in Watts
      double getPower();
      QTorque getTorque();
      QPercent getEfficiency();
      QTemperature getTemperature();
  };
}