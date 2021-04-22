
#include "opControl.h"

using namespace vex;
namespace dt = drivetrain;

#include "lib/units/units.h"

int flywheelToggle;

void joystickControl() {
  constexpr double valueToVoltCoeff = 12.0 / 127.0;

  const int leftJoystickValue = Controller1.Axis3.value();
  const int rightJoystickValue = Controller1.Axis2.value();
  dt::spinInVolts(leftJoystickValue * valueToVoltCoeff, dt::sides::left);
  dt::spinInVolts(rightJoystickValue * valueToVoltCoeff, dt::sides::right);
}

void indexerControl() {
  // Convey Balls
  if (Controller1.ButtonL1.pressing()) {
    Indexer.spin(fwd, 100, pct);
  }

  else {
    Indexer.stop(brake);
  }
}

void shooterControl() {
  // Outtake
  if (Controller1.ButtonR2.pressing()) {
    intakes::spinMaxOut();
    Indexer.spin(reverse, 100, pct);
    Shooter.stop(hold);
  }

  // Middle Goal Dump
  if (Controller1.ButtonL2.pressing()) {
    Shooter.spin(fwd, 13, volt);
    wait(100, msec);
    while (Controller1.ButtonL2.pressing()) {
      Shooter.spin(fwd, 13, volt);
      Indexer.spin(fwd, 100, pct);
      joystickControl();
    }
  }
  // Poop
  else if (Controller1.ButtonY.pressing()) {
    Shooter.spin(fwd, -100, pct);
    if (Controller1.ButtonL1.pressing() == false) {
      Indexer.stop(brake);
    }
  }

  else {
    Shooter.stop(hold);
  }
}

void screenControl() {
  if (Controller1.ButtonX.pressing()) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);

    std::stringstream firstLine;
    firstLine << "I: " << Indexer.temperature(celsius) << "   BL: " << BackLeftDrive.temperature(celsius);
    Controller1.Screen.print(firstLine.str().c_str());
    Controller1.Screen.newLine();

    std::stringstream secondLine;
    secondLine << "S: " << Shooter.temperature(celsius) << "  BR: " << BackRightDrive.temperature(celsius);
    Controller1.Screen.print(secondLine.str().c_str());
    Controller1.Screen.newLine();

    std::stringstream thirdLine;
    thirdLine << "B: " << Brain.Battery.capacity(pct) << "      RI: " << RightIntake.temperature(celsius);
    Controller1.Screen.print(thirdLine.str().c_str());
  }
}
