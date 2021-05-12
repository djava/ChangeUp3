#include "lib/rotation.h"
#include "lib/units/QAngularSpeed.h"

namespace lib {
    rotation::rotation(int port, std::string nickname = "")
    : HALRotation{HAL::rotation (port)}, reversed{false}, nickname{nickname} {}

    rotation::rotation(int port, bool reversed, std::string nickname = "")
    : HALRotation{HAL::rotation (port)}, reversed{reversed}, nickname{nickname} {}

    void rotation::resetAngle(QAngle angle) {
        // Slightly confusing logic but it works, verified in this repl: 
        // https://replit.com/@LeoRiesenbach/OrdinaryPracticalFiber#main.py
        internalAngleAdjustment += reverseCoeff() * (getAbsAngle() - angle);
    }

    void rotation::resetPosition(QAngle pos) {
        // Slightly confusing logic but it works, verified in this repl: 
        // https://replit.com/@LeoRiesenbach/OrdinaryPracticalFiber#main.py
        internalAngleAdjustment += reverseCoeff() * (getPosition() - pos);
    }

    QAngle rotation::getPosition() {
        return positionAdjust(HALRotation.getPositionCentiDeg() * 100.0 * 1.0_deg);
    }

    QAngularSpeed rotation::getVelocity() {
        return reverseCoeff() * HALRotation.getVelocityCentiDegPerSec() * 1.0_cps;
    }

    QAngle rotation::getAbsAngle() {
        return angleAdjust(HALRotation.getAbsAngleCentiDeg() * 100.0 * 1.0_deg);
    }
}