#include "lib/motor.h"
#include "lib/units/units.h"

namespace lib {
    motor::motor(const int& port,
                 const motorCart& cartridge,
                 const bool& reversed ,
                 const brakeMode& currentBrakeMode,
                 const std::string& nickname
    ) : HALMotor{HAL::motor(port, cartridge)}, cartridge{cartridge}, port{port},
        reversed{reversed}, currentBrakeMode(currentBrakeMode), nickname{nickname} { }

    // void motor::spin(const QVoltage& voltage) {
    //     const int voltageInMillivolts = static_cast<int>(voltage.convert(millivolt));

    //     HALMotor.spinMillivolts(voltageInMillivolts);
    // }

    void motor::spin(const QAngularSpeed& velocity) {
        const double velInRpm = velocity.convert(rpm);

        HALMotor.spinRPM(velInRpm);
    }

    void motor::spin(const QPercent& percentVoltage) {
        constexpr double maxVoltage = 12000.0;
        constexpr double maxPercentage = 100.0;
        const double voltageInMV = percentVoltage.convert(percent) * maxVoltage / maxPercentage;

        HALMotor.spinMillivolts(voltageInMV);
    }

    void motor::stop(const brakeMode& mode) {
        HALMotor.stop(mode);
    }

    QAngle motor::getIMEPosition() {
        double posInDegrees = HALMotor.getIMEPositionDegrees();

        return (posInDegrees * 1_deg) - internalIMEAdjustment;
    }

    void motor::resetIMEPosition(const QAngle& angle = 0_deg) {
        internalIMEAdjustment += angle;

        HALMotor.resetIMEPosition();
    }

    QAngularSpeed motor::getVelocity() {
        return HALMotor.getVelocityRPM() * 1_rpm;
    }

    double motor::getCurrent() {
        return HALMotor.getCurrentAmps();
    }

    QVoltage motor::getVoltage() {
        return HALMotor.getVoltageMillivolts() * 1_mV;
    }
    
    double motor::getPower() {
        return HALMotor.getPowerWatts();
    }

    QTorque motor::getTorque() {
        return HALMotor.getTorqueNm() * 1_nM;
    }

    QPercent motor::getEfficiency() {
        return HALMotor.getEfficiency() * 1_pct;
    }

    QTemperature motor::getTemperature() {
        return HALMotor.getTemperatureDegC() * 1_degC;
    }
}