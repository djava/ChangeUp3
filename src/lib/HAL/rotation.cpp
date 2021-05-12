#include "lib/HAL/rotation.h"

namespace lib::HAL {

    rotation::rotation(const int& port)
    #ifdef IS_PROS
    : vexRotation{pros::Rotation (port)} {}
    #else
    : vexRotation{vex::Rotation (port)} {}
    #endif

    #ifdef IS_PROS
    int rotation::getPositionCentiDeg() {
        return vexRotation.get_position();
    }

    int rotation::getVelocityCentiDegPerSec() {
        return vexRotation.get_velocity();
    }

    int rotation::getAbsAngleCentiDeg() {
        return vexRotation.get_angle();
    }
    #else
    //TODO: VEXCode implementation
    #endif
}