#include "lib/HAL/controller.h"
#include "pros/misc.h"

namespace lib::HAL {
    #ifdef IS_VEXCODE

    #else

    const std::map<joystickAxes, pros::controller_analog_e_t> controller::HALEnumToVexAxis {
        {joystickAxes::leftX, pros::E_CONTROLLER_ANALOG_LEFT_X},
        {joystickAxes::rightX, pros::E_CONTROLLER_ANALOG_RIGHT_X},
        {joystickAxes::leftY, pros::E_CONTROLLER_ANALOG_LEFT_Y},
        {joystickAxes::rightY, pros::E_CONTROLLER_ANALOG_RIGHT_Y}
    };
    
    const std::map<controllerButtons, pros::controller_digital_e_t> controller::HALEnumToVexButton {
        {controllerButtons::left, pros::E_CONTROLLER_DIGITAL_LEFT},
        {controllerButtons::right, pros::E_CONTROLLER_DIGITAL_RIGHT},
        {controllerButtons::up, pros::E_CONTROLLER_DIGITAL_UP},
        {controllerButtons::down, pros::E_CONTROLLER_DIGITAL_DOWN},
        {controllerButtons::A, pros::E_CONTROLLER_DIGITAL_A},
        {controllerButtons::B, pros::E_CONTROLLER_DIGITAL_B},
        {controllerButtons::X, pros::E_CONTROLLER_DIGITAL_X},
        {controllerButtons::Y, pros::E_CONTROLLER_DIGITAL_Y},
        {controllerButtons::L1, pros::E_CONTROLLER_DIGITAL_L1},
        {controllerButtons::L2, pros::E_CONTROLLER_DIGITAL_L2},
        {controllerButtons::R1, pros::E_CONTROLLER_DIGITAL_R1},
        {controllerButtons::R2, pros::E_CONTROLLER_DIGITAL_R2},
    };

    const std::map<controllerTypes, pros::controller_id_e_t> controller::HALEnumToVexType {
        {controllerTypes::master, pros::E_CONTROLLER_MASTER},
        {controllerTypes::partner, pros::E_CONTROLLER_PARTNER}
    };

    controller::controller(const controllerTypes& type)
        : vexController{pros::Controller (HALEnumToVexType.at(type))} {}
    
    int controller::getJoystickAxis(const joystickAxes& axis) {
        return vexController.get_analog(HALEnumToVexAxis.at(axis));
    }

    bool controller::getButtonPressed(const controllerButtons& button) {
        return vexController.get_digital(HALEnumToVexButton.at(button));
    }

    void controller::clearScreen() {
        vexController.clear();
    }
    
    void controller::clearLine(const int& line) {
        vexController.clear_line(line);
    }

    void controller::print(const int& row, const int& col, const std::string& text) {
        vexController.set_text(row, col, text);
    }

    int controller::getBatteryPercentage() {
        return vexController.get_battery_level();
    }
    
    #endif
}