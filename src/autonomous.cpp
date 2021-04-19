#include "autonomous.h"

namespace dt = drivetrain;

void leftAndCenter() {}

void Left() {
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(15, 15, 56);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  backLinear(-9, -40, 3);
}

void leftAndMiddle() {
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(16, 15, 56);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  turnCurve(51, -50, -68);

  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  LeftIntake.stop(hold);
  RightIntake.stop(hold);

  backLinear(-10.5, -40, 3);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 80, pct);
  Indexer.spin(fwd, 80, pct);
}

void rightAndMiddle() {
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(23.5, 70, 20);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(300, msec);
  Indexer.stop(brake);
  wait(200, msec);
  Shooter.stop(hold);
  wait(1, sec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  turnCurve(58, -85, -48);

  Indexer.spin(fwd, 13, volt);

  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  LeftIntake.stop(hold);
  RightIntake.stop(hold);

  backLinear(-10.5, -40, 3);
}

void Right() {
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(23.5, 70, 20);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(300, msec);
  Indexer.stop(brake);
  wait(200, msec);
  Shooter.stop(hold);
  wait(1000, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  backLinear(-11.25, -25, 5);
}

void progSkills() {

  // 36, 27
  Indexer.spin(fwd, 13, volt);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  // 11, 4.5

  // decrease y
  wait(200, msec);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(200, msec);
  Indexer.stop(brake);
  wait(200, msec);
  Shooter.stop(hold);
  wait(400, msec);

  // 2nd
  backLinear(-11.25, -45, 2);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  wait(200, msec);
  // increase y
  LeftIntake.stop(brake);
  RightIntake.stop(brake);


  Indexer.spin(fwd, 100, pct);
  wait(200, msec);
  // increase y
  Shooter.spin(fwd, 13, volt);
  wait(200, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Shooter.stop(hold);
  Indexer.spin(fwd, 100, pct);
  wait(400, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  // 3rd
  backLinear(-7.5, -20, 2);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  backLinear(-1.5, -40, 2);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);

  // lower x
  wait(500, msec);
  Shooter.spin(fwd, 13, volt);
  wait(200, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Shooter.stop(hold);
  wait(400, msec);

  // 14.75, 114.8

  setCoordinates(1);

  // 4th
  backLinear(-7.5, -25, 2);

  // Increase X
  Indexer.spin(fwd, 100, pct);
  Indexer.stop(brake);
  RightIntake.stop(brake);
  LeftIntake.stop(brake);
  // Increase X
  Indexer.stop(brake);
  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 13, volt);
  wait(600, msec);
  Shooter.stop(hold);
  wait(400, msec);

  // 70, 111.75

  // 5th
  backLinear(-2.25, -20, 2);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  Indexer.stop(brake);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);

  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 13, volt);
  wait(600, msec);
  Shooter.stop(hold);

  // 6th
  backLinear(-15, -40, 2);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Shooter.spin(fwd, 100, pct);
  wait(150, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Shooter.stop(brake);

  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  // 127,62.5

  setCoordinates(2);

  // 7th

  backLinear(-8, -30, 2);

  Indexer.spin(fwd, 100, pct);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  backLinear(-8, -20, 2);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);

  // lower x
  Shooter.spin(fwd, 13, volt);
  wait(200, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Shooter.stop(hold);
  wait(400, msec);

  // 8th
  backLinear(-8, -30, 2);
  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 13, volt);
  wait(600, msec);
  Shooter.stop(hold);

  // 9th

  backLinear(-4, -30, 3);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);

  wait(200, msec);

  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  wait(30, msec);

  wait(600, msec);

  dt::stopAll();

  wait(400, msec);


  wait(800, msec);

  dt::spinInPct(30, dt::E_SIDE_LEFT);
  dt::spinInPct(40, dt::E_SIDE_RIGHT);

  wait(1000, msec);
  dt::spinInPct(30, dt::E_SIDE_LEFT)

  wait(400, msec);

  dt::stopAll(coast);
  wait(100, msec);
  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 100, pct);

  wait(5, sec);
  dt::stopAll(coast);
}

void homeRow() {
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  wait(200, msec);
  turnCurve(15, 25, 50);
  wait(200, msec);
  Shooter.spin(fwd, 100, pct);
  dt::spinInPct(3);
  while (ballCount < 2 && timer1 < 600) {
    timer1++;
    if (Limit.pressing()) {
      ballCount++;
      while (Limit.pressing() && timer1 < 300) {
        wait(5, msec);
        timer1++;
      }
    }
    wait(5, msec);
  }

  wait(20, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  wait(600, msec);

  Indexer.stop(brake);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  backLinear(-2.4, -30, 3);

  turnCurve(45, -50, -68);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(100, msec);
  dt::spinInPct(1);
  while (ballCount < 2 && timer1 < 600) {
    timer1++;
    if (Limit.pressing()) {
      ballCount++;
      while (Limit.pressing()) {
        wait(5, msec);
      }
    }
    wait(5, msec);
  }
  wait(20, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  wait(200, msec);

  Indexer.spin(reverse, 50, pct);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  backLinear(-11, -40, 3);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);


  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);

  wait(100, msec);
  while (ballCount < 2 && timer1 < 600) {
    timer1++;
    if (Limit.pressing()) {
      ballCount++;
      while (Limit.pressing()) {
        wait(5, msec);
      }
    }
    wait(5, msec);
  }
  wait(50, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  wait(100, msec);

  Shooter.stop(hold);
  Indexer.spin(reverse, 100, pct);
  backLinear(-14.4, -40, 3);

  dt::stopAll(coast);
}

void homeRowRight() {
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 60, pct);
  wait(300, msec);
  turnCurve(24.6, 80, 20);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  Shooter.spin(fwd, 13, volt);
  // wait(100, msec);
  wait(800, msec);
  Shooter.stop(hold);
  Indexer.stop(brake);

  wait(300, msec);
  backLinear(-8, -40, 3);
  // wait(100, msec);
  // wait(300, msec);

  /*
  turnCurve(61, -80, -50);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 13, volt);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);

  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 100, pct);
  while(ballCount < 2){
    int prevBallCount = ballCount;
    if(LineSensor.value(pct) < 56){
      ballCount++;
    }
    if(prevBallCount < ballCount){
      wait(125, msec);
    }
  }
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  wait(100, msec);
  Indexer.spin(reverse, 30, pct);
  wait(200, msec);
  Sorter.stop(brake);

  backLinear(-14, -30, 3);
  Sorter.spin(fwd, 100, pct);
  wait(500, msec);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 80, pct);
  Indexer.spin(fwd, 80, pct);

  Sorter.spin(fwd, 100, pct);

  wait(500, msec);

  // wait(100, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  wait(200, msec);
  backLinear(-12, -40, 3);

  dt::stopAll(coast);
  */
}

void rightAndSide() {
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  wait(300, msec);
  turnCurve(24.6, 70, 28);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Shooter.spin(fwd, 13, volt);
  wait(100, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Shooter.stop(brake);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  wait(500, msec);
  backLinear(-1.6, -25, 2);
  Indexer.spin(fwd, 100, pct);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);

  dt::spinInPct(100, dt::E_SIDE_LEFT);
  dt::spinInPct(85, dt::E_SIDE_RIGHT);
  wait(500, msec);

  dt::spinInPct(10);
  while (ballCount < 1 && tracker < 300) {
    if (Limit.pressing()) {
      ballCount++;
      while (Limit.pressing()) {
        wait(10, msec);
      }
    }
    wait(10, msec);
    tracker++;
  }
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  dt::stopAll(coast);

  wait(300, msec);
  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 100, pct);

  wait(800, msec);
  Shooter.spin(reverse, 100, pct);

  wait(800, msec);
  Shooter.spin(fwd, 100, pct);

  wait(500, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  wait(500, msec);
  backLinear(-8, -40, 4);
}

void Center() {
  Inertial.setHeading(270, deg);
  wait(2, sec);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);


  IgnoreY(-18, 31.5, -1, 2.2, 60, 45, 70);
  wait(8, sec);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  dt::spinInPct(100);

  wait(500, msec);

  dt::stopAll(coast);

  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Shooter.stop(brake);

  LeftIntake.spin(fwd, -100, pct);
  RightIntake.spin(fwd, -100, pct);

  dt::spinInPct(-100);

  wait(500, msec);
  dt::stopAll(coast);
  wait(5, sec);
  dt::stopAll(coast);
}

void OrcahBlue() {
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(16, 15, 56);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  turnCurve(51, -50, -68);

  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  LeftIntake.stop(hold);
  RightIntake.stop(hold);

  backLinear(-11.2, -40, 3);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 80, pct);
  Indexer.spin(fwd, 80, pct);


  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  wait(1, sec);
  backLinear(-19.6, -40, 3);

  dt::stopAll(coast);
}