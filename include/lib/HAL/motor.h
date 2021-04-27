#pragma once
#include "lib/HAL/APIHeader.h"
#include <map>

namespace lib::HAL {
    enum class motorCart { red_100RPM, green_200RPM, blue_600RPM };

    enum class brakeMode { coast, brake, hold };

    class motor {
    private:
    #ifdef IS_VEXCODE
        vex::motor vexMotor;
        static const std::map<motorCart, vex::gearSetting> HALEnumToVexCart;
        static const std::map<brakeMode, vex::brakeType> HALEnumToVexBrakeMode;
    #else
        pros::Motor vexMotor;
        static const std::map<motorCart, pros::motor_gearset_e_t> HALEnumToVexCart;
        static const std::map<brakeMode, pros::motor_brake_mode_e_t> HALEnumToVexBrakeMode;
    #endif

    public:
        motor(const int &port, const motorCart &cartridge);

        void spinMillivolts(const double &millivolts);
        void spinRPM(const double& rpm);
        void spinToPosDegRPM(const double &degrees, const double &velocity);
        void stop(const brakeMode &mode);

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
} // namespace lib::HAL
