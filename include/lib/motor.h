#pragma once
#include "HAL/HAL.h"
#include "units/units.h"

namespace lib {
    using HAL::motorCart;
    using HAL::brakeMode;

    class motor {
    private:

        HAL::motor HALMotor;
        QAngle internalIMEAdjustment = 0_deg;

    public:
        const int port;
        const motorCart cartridge;

        bool reversed;
        brakeMode currentBrakeMode;
        std::string nickname;

        motor(const int& port,
                 const motorCart& cartridge = motorCart::green_200RPM,
                 const bool& reversed = false,
                 const brakeMode& currentBrakeMode = brakeMode::coast,
                 const std::string& nickname = "");

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