// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// BackLeftDrive        motor         1               
// BackRightDrive       motor         4               
// FrontLeftDrive       motor         11              
// FrontRightDrive      motor         20              
// Shooter              motor         8               
// Indexer              motor         15              
// Inertial             inertial      2               
// LeftIntake           motor         3               
// RightIntake          motor         13              
// LeftRotation         rotation      12              
// RightRotation        rotation      10              
// LineSensor           line          B               
// Limit                limit         C               
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\arybo                                            */
/*    Created:      Fri Jul 17 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// BackLeftDrive        motor         1               
// BackRightDrive       motor         4               
// FrontLeftDrive       motor         11              
// FrontRightDrive      motor         20              
// Shooter               motor         8               
// Indexer              motor         15              
// Inertial             inertial      2               
// LeftIntake           motor         3               
// RightIntake          motor         13              
// LeftRotation         rotation      12              
// RightRotation        rotation      10              
// LineSensor           line          B               
// Limit                limit         C               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "opControl.h"
#include "autonomous.h"
#include "autonMethodLibrary.h"

using namespace vex;

// global instance of competition
competition Competition;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Inertial.setHeading(270, degrees);
  wait(2000, msec);

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}


void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  thread t1(homeRow);
  thread t2(positionTracking);

  t1.join();
  t2.join();
  // ..........................................................................
}


void usercontrol(void) {
  // User control code here, inside the loop
  Controller1.ButtonR1.pressed(intakes::spinMaxIn);
  Controller1.ButtonRight.pressed(intakes::spinMaxOut);
  Controller1.ButtonR1.released(intakes::stopAll);
  Controller1.ButtonRight.released(intakes::stopAll);
  
  while (1) {
    joystickControl();
    indexerControl();
    shooterControl();
    screenControl();

    // goalAlign();
    wait(20, msec); // Sleep the task for a short amount of time to
                     // prevent wasted resources.
    if(Controller1.ButtonA.pressing()){
      Inertial.setHeading(270, deg);
      wait(2, sec);
      thread t1(homeRow);
      thread t2(positionTracking);

      t1.join();
      t2.join();
      }
    // else if (Controller1.ButtonB.pressing()){
    //   testQuadEquation(100, 80.00);
    // }
    wait(20, msec);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}