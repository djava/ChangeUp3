#include "autonMethodLibrary.h"

using namespace vex;
namespace dt = drivetrain;
namespace tracking = trackingWheels;


// Make a curve towards an object. We will input how far the curve will last,
// and the speed of the left side and right side
void turnCurve(const double& targetDistance, const double& leftSpeed, const double& rightSpeed) {
  dt::resetIMEs(BackLeftDrive);
  constexpr double lowerPowerLimit = 15.0;
  constexpr double pctToVoltsCoeff = 12.0;

  double trackingWheelDegreesToComplete = tracking::convert::inchesToWheelDegrees(targetDistance);
  
  tracking::resetPositions(tracking::wheels::left);
  while (fabs(tracking::getAvgPosition()) < trackingWheelDegreesToComplete) {
    double percentCompleted =
              100 * fabs(tracking::getPosition(tracking::wheels::left)) / trackingWheelDegreesToComplete;
    
    if (percentCompleted <= 3) {
      double lSpeed = clamp(leftSpeed / 10.0, -lowerPowerLimit, lowerPowerLimit);
      double rSpeed = clamp(rightSpeed / 10.0, -lowerPowerLimit, lowerPowerLimit);
      dt::spinInVolts(lSpeed / 25.0 * pctToVoltsCoeff, {dt::driveSides::left});
      dt::spinInVolts(rSpeed / 25.0 * pctToVoltsCoeff, {dt::driveSides::right});

    } else if (percentCompleted <= 30) {
      double lSpeed = clamp(leftSpeed * 3.33 * percentCompleted, -lowerPowerLimit, lowerPowerLimit);
      double rSpeed = clamp(rightSpeed * 3.33 * percentCompleted, -lowerPowerLimit, lowerPowerLimit);
      dt::spinInVolts(lSpeed / 75.0 * pctToVoltsCoeff, {dt::driveSides::left});
      dt::spinInVolts(rSpeed / 75.0 * pctToVoltsCoeff, {dt::driveSides::right});

    } else if (percentCompleted <= 70) {
      dt::spinInVolts(leftSpeed / 100.0 * pctToVoltsCoeff, {dt::driveSides::left});
      dt::spinInVolts(rightSpeed / 100.0 * pctToVoltsCoeff, {dt::driveSides::right});

    } else {
      double lSpeed = (leftSpeed * (100 - percentCompleted)) * 0.0333;
      lSpeed = clamp(lSpeed, std::min(-lowerPowerLimit, -leftSpeed * 3.0 / 16.0), 
                             std::max(lowerPowerLimit, leftSpeed * 3.0 / 16));
      double rSpeed = (rightSpeed * (100 - percentCompleted)) * 0.0333;
      rSpeed = clamp(rSpeed, std::min(-lowerPowerLimit, -rightSpeed * 3.0 / 16.0), 
                             std::max(lowerPowerLimit, rightSpeed * 3.0 / 16));

      dt::spinInVolts(lSpeed / 50.0 * pctToVoltsCoeff, {dt::driveSides::left});
      dt::spinInVolts(rSpeed / 50.0 * pctToVoltsCoeff, {dt::driveSides::right});
    }
  }
  dt::stopAll();
}

double globalX;
double globalY;
double heading1;
int numberChange = 0;

// This is a base function always running in the background, it helps provide
// coordinates for the goTo and turn functions.
void positionTracking() {
  constexpr double degToRadCoeff = M_PI * 180.0;

  // Starting Position
  globalX = 36.0; 
  globalY = 0.0;

  tracking::resetPositions();
  while (true) {
    // Add 360 to prevent it going negative, add 90 for degree shift to match the polar coordinate system
    double initialHeadingDeg = fmod(360.0 + 90.0 - Inertial.heading(), 360.0);
    double initialHeadingRad = initialHeadingDeg * degToRadCoeff;
    double initialLeftPos = LeftRotation.position(deg);
    double initialRightPos = RightRotation.position(deg);
    wait(5, msec);

    double leftChange = (LeftRotation.position(deg) - initialLeftPos) * tracking::wheelSizeInInches * M_PI / 360.0;
    double rightChange = (RightRotation.position(deg) - initialRightPos) * tracking::wheelSizeInInches * M_PI / 360.0;
    double movement = (leftChange + rightChange) / 2;

    globalX += cos(initialHeadingRad) * movement;
    globalY += sin(initialHeadingRad) * movement;
    heading1 = initialHeadingDeg;

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    std::stringstream odomDebugLine;
    odomDebugLine << "X: " << globalX << "     Y: " << globalY << "     H: " << initialHeadingDeg;
    Brain.Screen.print(odomDebugLine.str().c_str());

    if (numberChange == 1) {
      globalX = 14.75;
      globalY = 0;
      numberChange = 0;
    } else if (numberChange == 2) {
      globalX = 127;
      globalY = 62.5;
      numberChange = 0;
    }
  }
}

/*Go to function.
  This function is used to move the robot to a certain point The
  robot will turn to face the point and go there automatically.

  finalX is the x valie of the point we have to go to.
  final Y is the same but for the Y coordinate.
  For now, final heading will always be 360 until I can get a curve function working
  turnDirection is the direction we want the robot to turn  towards when it turns to face the point we want it to go to.
  -1 is turn left and 1 is turn right.

  kP and kD are values used in the PD function to adjust the speed. We usually start with 0.4 and 0.6 and then guess and check until we
  get the speeds we want.

  minSpeed is the minimum speed the robot shoud travel at any time, usually set at 15 but can be changed based on circumstances.
  Error margin is the "accuracy" meter. This tells the function how close is
  good enough. Usually set at about 0.25 inches but again, can be adjusted based
  on circumstances. (Final heading has since been eliminated until I make a
  curve function.)
 */

void goTo(double finalX, double finalY, turnDirection turnDirection, double kP = 0.4,
          double kD = 0.6, double minSpeed = 15.0, double errorMargin = 0.25) {

  double changeX = finalX - globalX;
  double changeY = finalY - globalY;
  
  double turnHeading;
  double deviationHeading = fabs(atan2f(changeY, changeX)) * (180 / M_PI);
  if (changeY > 0) {
    turnHeading = changeX > 0 ? deviationHeading : 180 - deviationHeading;
  } else {
    turnHeading = changeX > 0 ? 360 - deviationHeading : 180 + deviationHeading;
  }

  turn(turnDirection, turnHeading);

  int signX = changeX < 0 ? -1 : 1;
  int signY = changeY < 0 ? -1 : 1;
  int fsignX = signX;
  int fsignY = signY;
  double error = sqrt(pow(changeX, 2) + pow(changeY, 2));
  double prevError = error;
  wait(300, msec);
  
  double errorDerivative = 2.4;
  while (error > errorMargin && signX == fsignX && signY == fsignY) {
    changeX = finalX - globalX;
    changeY = finalY - globalY;

    error = sqrt(pow(changeX, 2) + pow(changeY, 2));
    errorDerivative = (error - prevError);
    prevError = error;
    Brain.resetTimer();
    
    double speed = fabs((kP * error) + (kD * errorDerivative));
    speed = std::max(minSpeed, speed);
    dt::spinInVolts(speed * 12.0 / 100.0);
    wait(15, msec);
  
    fsignX = changeX < 0 ? -1 : 1;
    fsignY = changeY < 0 ? -1 : 1;
  }

  dt::stopAll();
}

void turn(const turnDirection& direction, const double& degrees) {
  constexpr double kP = 0.45;
  constexpr double kD = 2.5;
  constexpr double flatTurnValue = 3.4;

  if (direction == turnDirection::none) return;
  // Multiply voltages by this to turn left or right, -1 -> left, 1 -> right
  int directionCoeff = direction == turnDirection::left ? -1 : 1;

  // Add 360 to prevent negatives (break the mod), add 90 for shift to match
  // up with the polar coordinate system
  double finalHeading = fmod(360.0 + 90.0 - degrees, 360.0);
  double changeHeading = finalHeading - Inertial.heading();
  changeHeading -= (changeHeading > 0) * 360;
  double origChangeHeading = changeHeading;

  Inertial.resetRotation();
  wait(30, msec);

  double turnVelocity = 1.5;
  double previousAngleError = Inertial.rotation(deg) - changeHeading;

  while (Inertial.rotation(deg) > changeHeading) {
    double angleError = Inertial.rotation(deg) - changeHeading;
    double angleDerivative = angleError - previousAngleError;
    previousAngleError = angleError;

    turnVelocity = (angleError * kP) - (angleDerivative * kD) + flatTurnValue;
    turnVelocity = std::max(turnVelocity, 10.0);

    dt::spinInVolts(directionCoeff * turnVelocity * 2 * 9 / 100, {dt::driveSides::left});
    dt::spinInVolts(-directionCoeff * turnVelocity * 2 * 9 / 100, {dt::driveSides::right});
    wait(10, msec);
  }

  dt::spinInVolts(directionCoeff * 0.2 * 12.0, {dt::driveSides::left});
  dt::spinInVolts(-directionCoeff * 0.2 * 12.0, {dt::driveSides::right});
  wait(fabs(origChangeHeading / 3.0), msec);
  
  dt::stopAll(coast);
}

void backLinear(double targetDistance, double minSpeed, double kP) {
  constexpr double pctToVoltCoeff = 12.0 / 100.0;

  tracking::resetPositions();
  double degreesToCompleteMove = tracking::convert::inchesToWheelDegrees(targetDistance);
  while (tracking::getAvgPosition() > degreesToCompleteMove) {
    double inchesLeftToCompleteMove = 
              tracking::convert::wheelDegreesToInches(degreesToCompleteMove - tracking::getAvgPosition());

    double speed = inchesLeftToCompleteMove * kP;
    speed = std::max(speed, minSpeed);

    dt::spinInVolts(speed * pctToVoltCoeff);
    wait(10, msec);
  }
  dt::stopAll();
}

void backCurve(double targetDistance, double minSpeed, double kP, double leftSpeed, double rightSpeed) {
  tracking::resetPositions();
  double degreesToCompleteMove = tracking::convert::inchesToWheelDegrees(targetDistance);
  double curveFactor = rightSpeed / leftSpeed;
  while (tracking::getPosition(tracking::wheels::left) > degreesToCompleteMove) {
    double inchesLeftInMove = 
            tracking::convert::inchesToWheelDegrees(degreesToCompleteMove - tracking::getPosition(tracking::wheels::left));

    double lSpeed = inchesLeftInMove * kP;
    lSpeed = std::max(lSpeed, minSpeed);
    
    double rSpeed = curveFactor * lSpeed;

    dt::spinInVolts(lSpeed, {dt::driveSides::left});
    dt::spinInVolts(rSpeed, {dt::driveSides::right});
    wait(10, msec);
  }
  dt::stopAll();
}

void IgnoreX(double finalX, double finalY, const turnDirection& turnDirection, double kP,
             double kD, double minSpeed, double errorMargin) {
  constexpr double radToDegCoeff = 180.0 / M_PI;
  constexpr double pctToVoltCoeff = 12.0 / 100.0;

  double changeX = finalX - globalX;
  double changeY = finalY - globalY;
  bool isInitialChangeYNegative = changeY < 0;

  double deviationHeading = fabs(atan2f(changeY, changeX)) * radToDegCoeff;
  double turnHeading;
  if (isInitialChangeYNegative) {
    turnHeading = changeX > 0 ? deviationHeading : 180 - deviationHeading;
  } else {
    turnHeading = changeX > 0 ? 180 + deviationHeading : 360 - deviationHeading;
  }

  turn(turnDirection, turnHeading);
  wait(350, msec);
  
  double error = sqrt(pow(changeX, 2) + pow(changeY, 2));
  double prevError = error + 5;
  double errorDerivative = -1;
  while (error > errorMargin && isInitialChangeYNegative == (changeY < 0)) {
    changeX = finalX - globalX;
    changeY = finalY - globalY;

    error = (sqrt(pow(changeX, 2) + pow(changeY, 2)));
    errorDerivative = (error - prevError) / (Brain.timer(msec));
    prevError = error;
    Brain.resetTimer();

    double speed = fabs((kP * error) + (kD * errorDerivative));
    speed = std::max(minSpeed, speed);

    dt::spinInVolts(speed * pctToVoltCoeff);
    wait(10, msec);
  }
  dt::stopAll();
}

void IgnoreY(double finalX, double finalY, const turnDirection& turnDirection, double kP,
             double kD, double minSpeed, double errorMargin) {
  constexpr double radToDegCoeff = 180.0 / M_PI;
  constexpr double pctToVoltCoeff = 12.0 / 100.0;

  double changeX = finalX - globalX;
  double changeY = finalY - globalY;
  bool isInitialChangeXNegative = changeX < 0;

  double deviationHeading = fabs(atan2f(changeY, changeX)) * radToDegCoeff;
  double turnHeading;
  if (isInitialChangeXNegative) {
    turnHeading = changeX > 0 ? deviationHeading : 180 - deviationHeading;
  } else {
    turnHeading = changeX > 0 ? 180 + deviationHeading : 360 - deviationHeading;
  }

  turn(turnDirection, turnHeading);
  wait(350, msec);
  
  double error = sqrt(pow(changeX, 2) + pow(changeY, 2));
  double prevError = error;
  double errorDerivative = -1;
  while (error > errorMargin && isInitialChangeXNegative == (changeX < 0)) {
    changeX = finalX - globalX;
    changeY = finalY - globalY;

    error = (sqrt(pow(changeX, 2) + pow(changeY, 2)));
    errorDerivative = (error - prevError) / (Brain.timer(msec));
    prevError = error;
    Brain.resetTimer();

    double speed = fabs((kP * error) + (kD * errorDerivative));
    speed = std::max(minSpeed, speed);

    dt::spinInVolts(speed * pctToVoltCoeff);
    wait(10, msec);
  }
  dt::stopAll();
}

void setCoordinates(int changeNumber) {
  numberChange = changeNumber;
}