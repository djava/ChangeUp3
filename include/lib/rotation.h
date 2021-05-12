#pragma once
#include "lib/HAL/HAL.h"
#include "lib/units/QAngle.h"
#include "lib/units/units.h"

namespace lib {
    class rotation {
    private:
        HAL::rotation HALRotation;

        QAngle internalPositionAdjustment = 0_deg;
        QAngle internalAngleAdjustment = 0_deg;

        inline int reverseCoeff() { return (reversed ? -1 : 1); }

        inline QAngle positionAdjust(QAngle sensorVal) {
            return reverseCoeff() * (sensorVal - internalPositionAdjustment);
        }

        inline QAngle angleAdjust(QAngle sensorVal) {
            return reverseCoeff() * (sensorVal - internalAngleAdjustment);
        }

    public:
        std::string nickname;

        bool reversed;

        rotation(int port, std::string nickname);
        rotation(int port, bool reversed, std::string nickname);

        void resetAngle(QAngle angle);
        void resetPosition(QAngle pos);
        QAngle getPosition();
        QAngularSpeed getVelocity();
        QAngle getAbsAngle();
    };
}