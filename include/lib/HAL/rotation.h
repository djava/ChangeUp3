#pragma once
#include "lib/HAL/APIHeader.h"
#include "pros/rotation.hpp"

namespace lib::HAL {
    class rotation {
    private:
    #ifdef IS_VEXCODE
        vex::rotation vexRotation;
    #else
        pros::Rotation vexRotation;
    #endif
    public:
        rotation(const int& port);
        int getPositionCentiDeg();
        int getVelocityCentiDegPerSec();
        int getAbsAngleCentiDeg();
    };
}