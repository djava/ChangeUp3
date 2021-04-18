#include "autonMethodLibrary.h"

using namespace vex;
namespace dt = drivetrain;


// Make a curve towards an object. We will input how far the curve will last,
// and the speed of the left side and right side
void turnCurve(const double& targetDistance, const double& leftSpeed, const &double rightSpeed) {
  constexpr double lowerPowerLimit = 15.0;
  constexpr double pctToVoltsCoeff = 12.0;

  double drivenWheelDegreesToComplete = dt::convert::inchesToDrivenWheelDegrees(targetDistance);
  
  LeftRotation.resetPosition();
  while (fabs(LeftRotation.position(deg)) < degrees) {
    double percentCompleted = 100 * fabs(FrontLeftDrive.angle()) / drivenWheelDegreesToComplete;
    
    if (percentCompleted <= 3) {
      double lSpeed = clamp(leftSpeed / 10.0, -lowerPowerLimit, lowerPowerLimit);
      double rSpeed = clamp(rightSpeed / 10.0, -lowerPowerLimit, lowerPowerLimit);
      dt::spinInVolts(lSpeed / 25.0 * pctToVoltsCoeff, dt::E_SIDE_LEFT);
      dt::spinInVolts(rSpeed / 25.0 * pctToVoltsCoeff, dt::E_SIDE_RIGHT);

    } else if (percentCompleted <= 30) {
      double lSpeed = clamp(leftSpeed * 3.33 * percentCompleted, -lowerPowerLimit, lowerPowerLimit);
      double rSpeed = clamp(rightSpeed * 3.33 * percentCompleted, -lowerPowerLimit, lowerPowerLimit);
      dt::spinInVolts(lSpeed / 75.0 * pctToVoltsCoeff, dt::E_SIDE_LEFT);
      dt::spinInVolts(rSpeed / 75.0 * pctToVoltsCoeff, dt::E_SIDE_RIGHT);

    } else if (percentCompleted <= 70) {
      dt::spinInVolts(leftSpeed / 100.0 * pctToVoltsCoeff, dt::E_SIDE_LEFT);
      dt::spinInVolts(rightSpeed / 100.0 * pctToVoltsCoeff, dt::E_SIDE_RIGHT);

    } else {
      int lSpeed = (leftSpeed * (100 - percentCompleted)) * 0.0333;
      lSpeed = clamp(lSpeed, std::min(-lowerPowerLimit, -leftSpeed * 3.0 / 16.0), 
                             std::max(lowerPowerLimit, leftSpeed * 3.0 / 16));
      int rSpeed = (rightSpeed * (100 - percentCompleted)) * 0.0333;
      rSpeed = clamp(rSpeed, std::min(-lowerPowerLimit, -rightSpeed * 3.0 / 16.0), 
                             std::max(lowerPowerLimit, rightSpeed * 3.0 / 16));

      dt::spinInVolts(lspeed / 50.0 * pctToVoltsCoeff, dt::E_SIDE_LEFT);
      dt::spinInVolts(rSpeed / 50.0 * pctToVoltsCoeff, dt::E_SIDE_RIGHT);
    }
  }
  dt::stopAll();
}

double globalX;
double globalY;
double heading1;

// This is a base function always running in the background, it helps provide
// coordinates for the goTo and turn functions.
void positionTracking() {
  // Starting Position
  globalX = 36.0; 
  globalY = 0.0;

  LeftRotation.resetPosition();
  RightRotation.resetPosition();
  while (true) {
    // Add 360 to prevent it going negative, add 90 for degree shift to match the polar coordinate system
    double initialHeadingDeg = fmod(360.0 + 90.0 - Inertial.heading(), 360.0);
    double initialHeadingRad = initialHeadingDeg * (M_PI / 180.0);
    double initialLeftPos = LeftRotation.position(deg);
    double initialRight = RightRotation.position(deg);
    wait(5, msec);

    double leftChange = (LeftRotation.position(deg) - initialLeft) * dt::trackingWheelSizeInInches * M_PI / 360.0;
    double rightChange = (RightRotation.position(deg) - initialRight) * dt::trackingWheelSizeInInches * M_PI / 360.0;
    double movement = (leftChange + rightChange) / 2;

    globalX += cos(initialHeadingRad) * movement;
    globalY += sin(initialHeadingRad) * movement;
    heading1 = initialHeadingDeg;

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    std::stringstream odomDebugLine;
    odomDebugLine << "X: " << globalX << "     Y: " << globalY << "     H: " << initialHeadingDeg;
    Brain.Screen.print(odomDebugLine.str().c_str());
  }
}

/*Go to function. This function is used to move the robot to a certain point The
  robot will turn to face the point and go ther automatically. finalX is the x
  valie of the point we have to go to. final Y is the same but for the Y
  coordinate. For now, final heading will always be 361 until I can get a curve
  function working, turnDirection is the direction we want the robot to turn
  towards when it turns to face the point we want it to go to. -1 is turn left
  and 1 is turn right. kP and kD are values used in the PD function to adjust
  the speed. We usually start with 0.4 and 0.6 and then guess and check until we
  get the speeds we want. minSpeed is the minimum speed the robot shoud travel
  at any time, usuallyy set at 15 but can be changed based on circumstances.
  Error margin is the "accuracy" meter. This tells the function how close is
  good enough. Usually set at about 0.25 inches but again, can be adjusted based
  on circumstances. (Final heading has since been eliminated until I make a
  curve function.)
 */

void goTo(double finalX, double finalY, int turnDirection, double kP, double kD,
          double minSpeed, double errorMargin) {
  int sign1;
  int sign2;
  double changeX = finalX - globalX;
  double changeY = finalY - globalY;
  if (changeX < 0) {
    sign1 = -1;
  } else if (changeX > 0) {
    sign1 = 1;
  }
  if (changeY < 0) {
    sign2 = -1;
  } else if (changeY > 0) {
    sign2 = 1;
  }
  int fsign1 = sign1;
  int fsign2 = sign2;
  double turnHeading;
  double error = (sqrt(changeX * changeX + changeY * changeY));
  double prevError = (sqrt(changeX * changeX + changeY * changeY));
  double deviationHeading = atan(changeY / changeX) * (180 / M_PI);
  if (deviationHeading < 0) {
    deviationHeading = deviationHeading * -1;
  }
  if (changeY > 0 && changeX > 0) {
    turnHeading = deviationHeading;
  }
  if (changeY > 0 && changeX < 0) {
    turnHeading = 180 - deviationHeading;
  }
  if (changeY < 0 && changeX < 0) {
    turnHeading = 180 + deviationHeading;
  }
  if (changeY < 0 && changeX > 0) {
    turnHeading = 360 - deviationHeading;
  }
  if (turnDirection == -1) {
    turnLeft(turnHeading);
  }
  if (turnDirection == 1) {
    turnRight(turnHeading);
  }
  wait(200, msec);
  double errorDerivative = -1;
  while (error > errorMargin && sign1 == fsign1 && sign2 == fsign2) {
    changeX = finalX - globalX;
    changeY = finalY - globalY;
    error = (sqrt(changeX * changeX + changeY * changeY));
    errorDerivative = (error - prevError) / (Brain.timer(msec));
    Brain.resetTimer();
    prevError = error;
    double speed = (kP * error) + (kD * errorDerivative);
    if (speed < 0) {
      speed = speed * -1;
    }
    if (minSpeed > speed) {
      speed = minSpeed;
    }
    FrontLeftDrive.spin(fwd, speed * 12 / 100, volt);
    BackLeftDrive.spin(fwd, speed * 12 / 100, volt);
    FrontRightDrive.spin(fwd, speed * 12 / 100, volt);
    BackRightDrive.spin(fwd, speed * 12 / 100, volt);
    wait(15, msec);
    if (changeX < 0) {
      fsign1 = -1;
    } else if (changeX > 0) {
      fsign1 = 1;
    }
    if (changeY < 0) {
      fsign2 = -1;
    } else if (changeY > 0) {
      fsign2 = 1;
    }
  }
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
}

void turnLeft(double degrees) {
  int finalHeading = (450 - degrees) % 360;
  double changeHeading = finalHeading - Inertial.heading();
  if (changeHeading > 0) {
    changeHeading = changeHeading - 360;
  }
  float origChangeHeading = changeHeading;
  Inertial.resetRotation();
  wait(30, msec);
  // 0.07 for auton
  float kp = 0.11;
  float kd = 30;
  float previousAngleError;
  float angleDerivative;
  float turnV = 1.5;
  int flatTurnValue = 1;
  float angleError = Inertial.rotation(deg) - changeHeading;
  previousAngleError = angleError;
  while (Inertial.rotation(deg) > (changeHeading)) {
    angleError = Inertial.rotation(deg) - changeHeading;
    angleDerivative = angleError - previousAngleError;
    turnV = (angleError * kp) - (angleDerivative * kd) + flatTurnValue;
    previousAngleError = angleError;
    // if(turnV > 17){turnV = 17;}  //auton
    // if(turnV < 10){turnV = 10;}  //auton
    if (turnV > 25) {
      turnV = 25;
    } // skills
    if (turnV < 15) {
      turnV = 15;
    } // skills

    BackLeftDrive.spin(fwd, -turnV * 2 * 12 / 100, volt);
    FrontLeftDrive.spin(fwd, -turnV * 2 * 12 / 100, volt);
    BackRightDrive.spin(fwd, turnV * 2 * 12 / 100, volt);
    FrontRightDrive.spin(fwd, turnV * 2 * 12 / 100, volt);
    wait(10, msec);
  }
  /*
  finalHeading = (450 - degrees)%360;
  changeHeading = finalHeading - Inertial.heading();
  if(changeHeading > 0){ changeHeading = changeHeading - 360;}
  origChangeHeading = changeHeading;
  Inertial.resetRotation();
  wait(30, msec);
  kp = 0.125;
  kd = 60;
  turnV = 1.5;
  flatTurnValue = 2;
  angleError = Inertial.rotation(deg) - changeHeading;
  previousAngleError = angleError;
  while(Inertial.rotation(deg) > changeHeading){
    angleError = Inertial.rotation(deg) - changeHeading;
    angleDerivative = angleError - previousAngleError;
    turnV = (angleError * kp) - (angleDerivative * kd) + flatTurnValue;
    previousAngleError = angleError;
    if(turnV > 50){turnV = 50;}


    BackLeftDrive.spin(fwd, -turnV * 2, pct);
    FrontLeftDrive.spin(fwd, -turnV * 2, pct);
    BackRightDrive.spin(fwd, turnV * 2, pct);
    FrontRightDrive.spin(fwd, turnV * 2, pct);
  }
  */
  BackLeftDrive.spin(fwd, 20, pct);
  FrontLeftDrive.spin(fwd, 20, pct);
  BackRightDrive.spin(fwd, -20, pct);
  FrontRightDrive.spin(fwd, -20, pct);
  wait(fabs(5 / 3 * origChangeHeading), msec);
  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);
}

void turnRight(double degrees) {
  int finalHeading = (450 - degrees);
  if (finalHeading > 360) {
    finalHeading = finalHeading - 360;
  }
  double changeHeading = finalHeading - Inertial.heading();
  if (changeHeading < 0) {
    changeHeading = changeHeading + 360;
  }
  float origChangeHeading = changeHeading;
  Inertial.resetRotation();
  wait(30, msec);
  float kp = 0.11; // 0.07 for auton
  float kd = 30;
  float previousAngleError;
  float angleDerivative;
  float turnV = 1.5;
  int flatTurnValue = 1;
  float angleError = changeHeading - Inertial.rotation(deg);
  previousAngleError = angleError;
  while (Inertial.rotation(deg) < (changeHeading - 5)) {
    angleError = changeHeading - Inertial.rotation(deg);
    angleDerivative = angleError - previousAngleError;
    turnV = (angleError * kp) + (angleDerivative * kd) + flatTurnValue;
    previousAngleError = angleError;
    // if(turnV > 17){turnV = 17;}  //auton
    // if(turnV < 10){turnV = 10;}  //auton
    if (turnV > 25) {
      turnV = 25;
    } // skills
    if (turnV < 15) {
      turnV = 15;
    } // skills

    BackLeftDrive.spin(fwd, turnV * 2 * 12 / 100, volt);
    FrontLeftDrive.spin(fwd, turnV * 2 * 12 / 100, volt);
    BackRightDrive.spin(fwd, -turnV * 2 * 12 / 100, volt);
    FrontRightDrive.spin(fwd, -turnV * 2 * 12 / 100, volt);
    wait(10, msec);
  }
  /*
  finalHeading = (450 - degrees);
  if(finalHeading > 360){ finalHeading = finalHeading - 360;}
  changeHeading = finalHeading - Inertial.heading();
  if(changeHeading < 0){ changeHeading = changeHeading + 360;}
  origChangeHeading = changeHeading;
  Inertial.resetRotation();
  wait(30, msec);
  kp = 0.125;
  kd = 10;
  previousAngleError;
  angleDerivative;
  turnV = 1.5;
  flatTurnValue = 1;
  angleError = changeHeading - Inertial.rotation(deg);
  previousAngleError = angleError;
  while(Inertial.rotation(deg) < changeHeading){
    angleError = changeHeading - Inertial.rotation(deg);
    angleDerivative = angleError - previousAngleError;
    turnV = (angleError*kp) + (angleDerivative * kd) + flatTurnValue;
    previousAngleError = angleError;
    if(turnV > 50){turnV = 50;}

    BackLeftDrive.spin(fwd, turnV * 2, pct);
    FrontLeftDrive.spin(fwd, turnV * 2, pct);
    BackRightDrive.spin(fwd, -turnV * 2, pct);
    FrontRightDrive.spin(fwd, -turnV * 2, pct);
  }
  */
  BackLeftDrive.spin(fwd, -20, pct);
  FrontLeftDrive.spin(fwd, -20, pct);
  BackRightDrive.spin(fwd, 20, pct);
  FrontRightDrive.spin(fwd, 20, pct);

  wait(5 / 3 * origChangeHeading, msec);

  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);
}

void backLinear(double targetDistance, int minSpeed, double kP) {
  FrontLeftDrive.resetRotation();
  FrontRightDrive.resetRotation();
  double degrees = targetDistance / 0.03599741582;
  while (FrontLeftDrive.rotation(deg) > degrees) {
    double inchesLeft =
        (degrees - FrontLeftDrive.rotation(deg)) * 0.03599741582;
    double speed = inchesLeft * kP;
    if (speed > minSpeed) {
      speed = minSpeed;
    }
    FrontLeftDrive.spin(fwd, speed, pct);
    FrontRightDrive.spin(fwd, speed, pct);
    BackLeftDrive.spin(fwd, speed, pct);
    BackRightDrive.spin(fwd, speed, pct);
    wait(10, msec);
  }
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
}

void backCurve(double targetDistance, int minSpeed, double kP, int leftSpeed,
               int rightSpeed) {
  FrontLeftDrive.resetRotation();
  FrontRightDrive.resetRotation();
  double degrees = targetDistance / 0.03599741582;
  double factor = rightSpeed / leftSpeed;
  while (FrontLeftDrive.rotation(deg) > degrees) {
    double inchesLeft =
        (degrees - FrontLeftDrive.rotation(deg)) * 0.03599741582;
    double speed = inchesLeft * kP;
    if (speed > minSpeed) {
      speed = minSpeed;
    }
    double rSpeed = factor * speed;
    FrontLeftDrive.spin(fwd, speed, pct);
    FrontRightDrive.spin(fwd, rSpeed, pct);
    BackLeftDrive.spin(fwd, speed, pct);
    BackRightDrive.spin(fwd, rSpeed, pct);
    wait(10, msec);
  }
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
}

void IgnoreX(double finalX, double finalY, int turnDirection, double kP,
             double kD, double minSpeed, double errorMargin) {
  int sign2;
  double changeX = finalX - globalX;
  double changeY = finalY - globalY;
  if (changeY < 0) {
    sign2 = -1;
  } else if (changeY > 0) {
    sign2 = 1;
  }
  int fsign2 = sign2;
  double turnHeading;
  double error = (sqrt(changeX * changeX + changeY * changeY));
  double prevError = (sqrt(changeX * changeX + changeY * changeY));
  double deviationHeading = atan(changeY / changeX) * (180 / M_PI);
  if (deviationHeading < 0) {
    deviationHeading = deviationHeading * -1;
  }
  if (changeY > 0 && changeX > 0) {
    turnHeading = deviationHeading;
  }
  if (changeY > 0 && changeX < 0) {
    turnHeading = 180 - deviationHeading;
  }
  if (changeY < 0 && changeX < 0) {
    turnHeading = 180 + deviationHeading;
  }
  if (changeY < 0 && changeX > 0) {
    turnHeading = 360 - deviationHeading;
  }
  if (turnDirection == -1) {
    turnLeft(turnHeading);
  }
  if (turnDirection == 1) {
    turnRight(turnHeading);
  }
  wait(350, msec);
  double errorDerivative = -1;
  while (error > errorMargin && sign2 == fsign2) {
    changeX = finalX - globalX;
    changeY = finalY - globalY;
    error = (sqrt(changeX * changeX + changeY * changeY));
    errorDerivative = (error - prevError) / (Brain.timer(msec));
    Brain.resetTimer();
    prevError = error;
    double speed = (kP * error) + (kD * errorDerivative);
    if (speed < 0) {
      speed = speed * -1;
    }
    if (minSpeed > speed) {
      speed = minSpeed;
    }
    FrontLeftDrive.spin(fwd, speed, pct);
    BackLeftDrive.spin(fwd, speed, pct);
    FrontRightDrive.spin(fwd, speed, pct);
    BackRightDrive.spin(fwd, speed, pct);
    wait(10, msec);
    if (changeY < 0) {
      fsign2 = -1;
    } else if (changeY > 0) {
      fsign2 = 1;
    }
  }
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
}

void IgnoreY(double finalX, double finalY, int turnDirection, double kP,
             double kD, double minSpeed, double errorMargin) {
  int sign1;
  double changeX = finalX - globalX;
  double changeY = finalY - globalY;
  if (changeX < 0) {
    sign1 = -1;
  } else if (changeX > 0) {
    sign1 = 1;
  }
  int fsign1 = sign1;
  double turnHeading;
  double error = (sqrt(changeX * changeX + changeY * changeY));
  double prevError = (sqrt(changeX * changeX + changeY * changeY));
  double deviationHeading = atan(changeY / changeX) * (180 / M_PI);
  if (deviationHeading < 0) {
    deviationHeading = deviationHeading * -1;
  }
  if (changeY > 0 && changeX > 0) {
    turnHeading = deviationHeading;
  }
  if (changeY > 0 && changeX < 0) {
    turnHeading = 180 - deviationHeading;
  }
  if (changeY < 0 && changeX < 0) {
    turnHeading = 180 + deviationHeading;
  }
  if (changeY < 0 && changeX > 0) {
    turnHeading = 360 - deviationHeading;
  }
  if (turnDirection == -1) {
    turnLeft(turnHeading);
  }
  if (turnDirection == 1) {
    turnRight(turnHeading);
  }
  wait(350, msec);
  double errorDerivative = -1;
  while (error > errorMargin && sign1 == fsign1) {
    changeX = finalX - globalX;
    changeY = finalY - globalY;
    error = (sqrt(changeX * changeX + changeY * changeY));
    errorDerivative = (error - prevError) / (Brain.timer(msec));
    Brain.resetTimer();
    prevError = error;
    double speed = (kP * error) + (kD * errorDerivative);
    if (speed < 0) {
      speed = speed * -1;
    }
    if (minSpeed > speed) {
      speed = minSpeed;
    }
    FrontLeftDrive.spin(fwd, speed, pct);
    BackLeftDrive.spin(fwd, speed, pct);
    FrontRightDrive.spin(fwd, speed, pct);
    BackRightDrive.spin(fwd, speed, pct);
    wait(10, msec);
    if (changeX < 0) {
      fsign1 = -1;
    } else if (changeX > 0) {
      fsign1 = 1;
    }
  }
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
}
