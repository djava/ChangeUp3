#include "lib/controller.h"
#include "lib/units/units.h"
#include "lib/APIWrappers.h"
#include "pros/rtos.hpp"

namespace lib {
    controller::controller(const controllerTypes& type) 
        : HALController{HAL::controller(type)}, type{type} {}

    void controller::printTaskFn() {
        while (true) {
            if (!printQueue.empty()) {
                printObj obj = printQueue.front();
                HALController.print(obj.row, obj.col, obj.text);
                printQueue.pop();
            }
            lib::delay(55_ms);
        }
    }

    QPercent controller::getAxisPct(const joystickAxes& axis) {
        constexpr double axisValToPct = 100.0/127.0;
        return QPercent(HALController.getJoystickAxis(axis) * axisValToPct) * percent;
    }
    
    int controller::getAxisVal(const joystickAxes& axis) {
        return HALController.getJoystickAxis(axis);
    }

    bool controller::getButtonPressed(const controllerButtons &button) {
        return HALController.getButtonPressed(button);
    }

    void controller::clearScreen() {
        HALController.clearScreen();
    }

    void controller::print(const int& row, const int& col, const std::string& text) {
        printQueue.push({row, col, text});
    }

    void controller::print(const int& row, const int& col, const std::stringstream& text) {
        printQueue.push({row, col, text.str()});
    }

    void controller::rumble(const std::string& text) {
        printQueue.push({rumblePrintRow, 0, text});
    }
    
    void controller::rumble(const std::stringstream& text) {
        printQueue.push({rumblePrintRow, 0, text.str()});
    }
}