#include "autonomous.h"

namespace dt = drivetrain;

void leftAndCenter() {}

void Left() {
  ////intakes::spinMaxIn();
  turnCurve(15, 15, 56);
  ////intakes::stopAll();
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  ////intakes::spinMaxOut();
  backLinear(-9, -40, 3);
}

void leftAndMiddle() {
  ////intakes::spinMaxIn();
  turnCurve(16, 15, 56);
  ////intakes::stopAll();
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  ////intakes::spinMaxOut();
  turnCurve(51, -50, -68);

  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  ////intakes::stopAll(hold);

  backLinear(-10.5, -40, 3);

  ////intakes::spinMaxIn(////intakes::motors::left);
  ////intakes::spinInPct(80.0, ////intakes::motors::right);
  Indexer.spin(fwd, 80, pct);
}

void rightAndMiddle() {
  ////intakes::spinMaxIn();
  turnCurve(23.5, 70, 20);
  ////intakes::stopAll();
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(300, msec);
  Indexer.stop(brake);
  wait(200, msec);
  Shooter.stop(hold);
  wait(1, sec);
  ////intakes::spinMaxOut();
  turnCurve(58, -85, -48);

  Indexer.spin(fwd, 13, volt);

  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  ////intakes::stopAll(hold);

  backLinear(-10.5, -40, 3);
}

void Right() {
  ////intakes::spinMaxIn();
  turnCurve(23.5, 70, 20);
  ////intakes::stopAll();
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(300, msec);
  Indexer.stop(brake);
  wait(200, msec);
  Shooter.stop(hold);
  wait(1000, msec);
  ////intakes::spinMaxOut();
  backLinear(-11.25, -25, 5);
}

void progSkills() {

  // 36, 27
  Indexer.spin(fwd, 13, volt);
  ////intakes::spinMaxIn();
  ////intakes::stopAll();
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

  ////intakes::spinMaxIn();
  wait(200, msec);
  // increase y
  ////intakes::stopAll();

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
  ////intakes::spinMaxOut();

  // 3rd
  backLinear(-7.5, -20, 2);

  ////intakes::spinMaxIn();
  backLinear(-1.5, -40, 2);
  ////intakes::stopAll();

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
  ////intakes::stopAll();
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
  ////intakes::spinMaxIn();
  Indexer.spin(fwd, 100, pct);
  Indexer.stop(brake);
  ////intakes::stopAll();

  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 13, volt);
  wait(600, msec);
  Shooter.stop(hold);

  // 6th
  backLinear(-15, -40, 2);
  ////intakes::spinMaxIn();
  Indexer.spin(fwd, 100, pct);
  ////intakes::stopAll();
  Shooter.spin(fwd, 100, pct);
  wait(150, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Shooter.stop(brake);

  ////intakes::spinMaxOut();

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
  ////intakes::spinMaxIn();
  Indexer.spin(fwd, 100, pct);

  wait(200, msec);

  ////intakes::spinMaxOut();
  wait(30, msec);

  wait(600, msec);

  dt::stopAll();

  wait(400, msec);


  wait(800, msec);

  dt::spinInPct(30, dt::sides::left);
  dt::spinInPct(40, dt::sides::right);

  wait(1000, msec);
  dt::spinInPct(30, dt::sides::left);

  wait(400, msec);

  dt::stopAll(coast);
  wait(100, msec);
  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 100, pct);

  wait(5, sec);
  dt::stopAll(coast);
}

void homeRow() {
  ////intakes::spinMaxIn();
  Indexer.spin(fwd, 100, pct);
  wait(200, msec);
  turnCurve(15, 25, 50);
  wait(200, msec);
  Shooter.spin(fwd, 100, pct);
  dt::spinInPct(3);
  int ballCount = 0;
  int timer1 = 0;
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
  ////intakes::spinMaxOut();

  wait(600, msec);

  Indexer.stop(brake);
  ////intakes::spinMaxOut();
  backLinear(-2.4, -30, 3);

  turnCurve(45, -50, -68);

  ////intakes::spinMaxIn();
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
  ////intakes::spinMaxOut();

  wait(200, msec);

  Indexer.spin(reverse, 50, pct);
  ////intakes::spinMaxOut();

  backLinear(-11, -40, 3);

  ////intakes::spinMaxIn();
  Indexer.spin(fwd, 100, pct);

  Indexer.spin(fwd, 13, volt); // HOW
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
  ////intakes::spinMaxOut();

  wait(100, msec);

  Shooter.stop(hold);
  Indexer.spin(reverse, 100, pct);
  backLinear(-14.4, -40, 3);

  dt::stopAll(coast);
}

void homeRowRight() {
  ////intakes::spinMaxIn();
  Indexer.spin(fwd, 60, pct);
  wait(300, msec);
  turnCurve(24.6, 80, 20);
  ////intakes::spinMaxOut();
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
  ////intakes::spinMaxIn();

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
  ////intakes::spinMaxOut();
  wait(100, msec);
  Indexer.spin(reverse, 30, pct);
  wait(200, msec);
  Sorter.stop(brake);

  backLinear(-14, -30, 3);
  Sorter.spin(fwd, 100, pct);
  wait(500, msec);
  ////intakes::spinMaxIn(////intakes::motors::left);
  ////intakes::spinInPct(////intakes::motors::right);
  Indexer.spin(fwd, 80, pct);

  Sorter.spin(fwd, 100, pct);

  wait(500, msec);

  // wait(100, msec);
  ////intakes::spinMaxOut();
  wait(200, msec);
  backLinear(-12, -40, 3);

  dt::stopAll(coast);
  */
}

void rightAndSide() {
  ////intakes::spinMaxIn();
  Indexer.spin(fwd, 100, pct);
  wait(300, msec);
  turnCurve(24.6, 70, 28);
  ////intakes::stopAll();
  Shooter.spin(fwd, 13, volt);
  wait(100, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Shooter.stop(brake);
  ////intakes::spinMaxOut();
  LeftIntake.spin(reverse, 100, pct);
  wait(500, msec);
  backLinear(-1.6, -25, 2);
  Indexer.spin(fwd, 100, pct);

  ////intakes::spinMaxIn();

  dt::spinInPct(100, dt::sides::left);
  dt::spinInPct(85, dt::sides::right);
  wait(500, msec);
  dt::spinInPct(10);

  int tracker = 0;
  int ballCount = 0;
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
  ////intakes::stopAll();
  dt::stopAll(coast);

  wait(300, msec);
  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 100, pct);

  wait(800, msec);
  Shooter.spin(reverse, 100, pct);

  wait(800, msec);
  Shooter.spin(fwd, 100, pct);

  wait(500, msec);
  ////intakes::spinMaxOut();
  LeftIntake.spin(reverse, 100, pct);
  wait(500, msec);
  backLinear(-8, -40, 4);
}

void Center() {
  Inertial.setHeading(270, deg);
  wait(2, sec);

  ////intakes::spinMaxIn();
  ////intakes::stopAll();

  IgnoreY(-18, 31.5, E_TURN_DIRECTION_LEFT, 2.2, 60, 45, 70);
  wait(8, sec);

  ////intakes::spinMaxIn();
  dt::spinInPct(100);

  wait(500, msec);

  dt::stopAll(coast);

  ////intakes::stopAll();
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Shooter.stop(brake);

  ////intakes::spinMaxOut();

  dt::spinInPct(-100);

  wait(500, msec);
  dt::stopAll(coast);
  wait(5, sec);
  dt::stopAll(coast);
}

void OrcahBlue() {
  ////intakes::spinMaxIn();
  turnCurve(16, 15, 56);
  ////intakes::stopAll();
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  ////intakes::spinMaxOut();
  turnCurve(51, -50, -68);

  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  ////intakes::stopAll(hold);

  backLinear(-11.2, -40, 3);

  ////intakes::spinMaxIn(////intakes::motors::left);
  ////intakes::spinInPct(////intakes::motors::right);
  Indexer.spin(fwd, 80, pct);

  ////intakes::stopAll();
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  ////intakes::spinMaxOut();

  wait(1, sec);
  backLinear(-19.6, -40, 3);

  dt::stopAll(coast);
}