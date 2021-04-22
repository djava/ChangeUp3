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

  // class motor {
  //   private:
  //     HAL::motor HALMotor;
  //     const int port;
  //     const motorCart cartridge;
  //     brakeMode currentBrakeMode;

  //   public:
  //     bool reversed;


  // };
}