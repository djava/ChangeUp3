#pragma once
#include "lib/HAL/APIHeader.h"
#include "pros/misc.h"
#include <map>
#include <string>

namespace lib::HAL {
    enum class joystickAxes { 
        leftX, leftY, rightX, rightY 
    };

    enum class controllerButtons {
        left, right, up, down,
        A, B, X, Y,
        L1, L2, R1, R2
    };

    enum class controllerTypes {
        master, partner
    };

    class controller {
    private:
    #ifdef IS_VEXCODE
        vex::controller vexController;
        static const std::map<joystickAxes, vex::axis> HALEnumToVexAxis;
        static const std::map<controllerButtons, vex::Button> HALEnumToVexButton;
        static const std::map<controllerTypes, vex::controllerType> HALEnumToVexType;
    #else
        pros::Controller vexController;
        static const std::map<joystickAxes, pros::controller_analog_e_t> HALEnumToVexAxis;
        static const std::map<controllerButtons, pros::controller_digital_e_t> HALEnumToVexButton;
        static const std::map<controllerTypes, pros::controller_id_e_t> HALEnumToVexType;
    #endif

    public:
        controller(const controllerTypes& type);

        int getJoystickAxis(const joystickAxes& axis);
        bool getButtonPressed(const controllerButtons& button);

        void clearScreen();
        void clearLine(const int& line);
        void print(const int& row, const int& col, const std::string& text);
        void rumble(const std::string& morseCode);

        int getBatteryPercentage();
    };
}