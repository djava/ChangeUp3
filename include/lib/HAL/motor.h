#pragma once
#include "vex.h"
#include <map>

namespace lib {
namespace HAL {
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
      vex::motor vexMotor;
      static const std::map<motorCart, vex::gearSetting> HALEnumToVexCart;
      static const std::map<brakeMode, vex::brakeType> HALEnumToVexBrakeMode;

    public:
      motor(const int& port, const motorCart& cartridge);
      
      void spinMillivolts(const double& millivolts);
      void spinToPosDegRPM(const double& degrees, const double& velocity);
      void stop(const brakeMode& mode);

      double getIMEPositionDegrees();
      void resetIMEPosition();

      double getVelocityRPM();
      double getCurrentAmps();
      double getVoltageMillivolts();
      double getPowerWatts();
      double getTorqueNm();
      double getEfficiency();
      double getTemperatureDegC();
  };
}
}