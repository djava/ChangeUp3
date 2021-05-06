#pragma once
#include "lib/HAL/HAL.h"
#include "lib/units/units.h"
#include "lib/APIWrappers.h"
#include <queue>
#include <functional>
#include <sstream>
#include "main.h"

namespace lib {
    using HAL::controllerButtons;
    using HAL::joystickAxes;
    using HAL::controllerTypes;
    class controller {
    private:
        typedef struct printObj { int row; int col; std::string text; } printObj;

        HAL::controller HALController;
        const controllerTypes type;

        static constexpr int rumblePrintRow = 4;

        std::queue<printObj> printQueue {};

        void printTaskFn();
        std::unique_ptr<lib::task> printTask = std::make_unique<lib::task>(
                        [&]{this->printTaskFn();}, lib::task::normalPriority - 2, "Controller Print Task");

    public:
        controller(const controllerTypes& type);

        QPercent getAxisPct(const joystickAxes& axis);
        int getAxisVal(const joystickAxes& axis);
        bool getButtonPressed(const controllerButtons& button);

        void clearScreen();

        template <int line, typename = std::enable_if_t<line >= 1 && line <= 3>>
        void clearLine() { HALController.clearLine(line); }

        void print(const int& row, const int& col, const std::string& text);
        void print(const int& row, const int& col, const std::stringstream& text);
        void rumble(const std::string& morseCode);
        void rumble(const std::stringstream& morseCode);

        QPercent getBatteryLevel();
    };
}