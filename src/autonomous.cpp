#include "autonomous.h"

namespace dt = drivetrain;

void Left() {
  intakes::spinMaxIn();
  turnCurve(15, 15, 56);
  intakes::stopAll();
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  intakes::spinMaxOut();
  backLinear(-9, -40, 3);
}

void leftAndMiddle(){
  intakes::spinMaxIn();
  turnCurve(16, 15, 56);
  intakes::stop();
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  intakes::spinMaxOut();
  turnCurve(51, -50, -68);
  
  IgnoreX(53.5, 1.25, turnDirection::left, 2.2, 60, 45, 0.5);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  intakes::stop(hold);

  backLinear(-10.5, -40, 3);

  intakes::spinMaxIn(intakes::motors::left);
  intakes::spinInPct(80, intakes::motors::right);
  Indexer.spin(fwd, 80, pct);
}

void rightAndMiddle(){
  intakes::spinMaxIn();
  turnCurve(23.5, 70, 20);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(300, msec);
  Indexer.stop(brake);
  wait(200, msec);
  Shooter.stop(hold);
  wait(1,sec);
  intakes::spinMaxOut();
  turnCurve(58, -85, -48);
  
  Indexer.spin(fwd, 13, volt);
  IgnoreX(68, -1.25, turnDirection::right, 2.2, 60, 45, 0.5);
  
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  intakes::stop(hold);

  backLinear(-10.5, -40, 3);
}

void Right(){
  intakes::spinMaxIn();
  turnCurve(23.5, 70, 20);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(300, msec);
  Indexer.stop(brake);
  wait(200, msec);
  Shooter.stop(hold);
  wait(1,sec);
  intakes::spinMaxOut();
  backLinear(-11.25, -25, 5);
}

void progSkills(){
  
  // 36, 27
  Indexer.spin(fwd, 13, volt);
  intakes::spinMaxIn();
  IgnoreX(36, 15, turnDirection::none, 2.3, 60, 45, 0.5);
  // 11, 4.5
  
  goTo(14, 0, turnDirection::left, 2.1, 60, 45, 0.5);
  //decrease y
  wait(200,msec);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(200, msec);
  Indexer.stop(brake);
  wait(200, msec);
  Shooter.stop(hold);
  wait(400, msec);
  
  
  //2nd
  backLinear(-11.25, -45, 2);
  intakes::spinMaxIn();
  IgnoreX(15.25, 54, turnDirection::right, 1.8, 60, 35, 0.5);
  wait(200, msec);
 //increase y
  
  IgnoreY(15.75, 60, turnDirection::left, 2.1, 60, 35, 0.5);

  Indexer.spin(fwd, 100, pct);
  wait(200, msec);
  //increase y
  Shooter.spin(fwd, 13, volt);
  wait(200, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Shooter.stop(hold);
  Indexer.spin(fwd, 100, pct);
  wait(400, msec);
  intakes::spinMaxOut();
  
  //3rd
  backLinear(-7.5, -20, 2);
  
  intakes::spinMaxIn();
  IgnoreX(29.5, 98, turnDirection::right, 2.1, 60, 35, 0.5);
  backLinear(-1.5, -40, 2);
  
  IgnoreY(14., 119, turnDirection::left, 2.1, 60, 40, 0.5);
  //lower x
  wait(500, msec);
  Shooter.spin(fwd, 13, volt);
  wait(200, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Shooter.stop(hold);
  wait(400, msec);

  //14.75, 114.8
  setCoordinates(1);
  
  //4th
  backLinear(-7.5, -25, 2);
  
  //Increase X
  Indexer.spin(fwd, 100, pct);
  IgnoreY(70.5, 108, turnDirection::right, 1.8, 60, 30, 0.5);
  intakes::stop(brake, intakes::motors::left);
  //Increase X
  Indexer.stop(brake);
  IgnoreX(70.5, 110.5, turnDirection::left, 2.1, 60, 35, 0.5);
  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 13, volt);
  wait(600, msec);
  Shooter.stop(hold);
  wait(400, msec);
  
  
  //70, 111.75
  
  //5th
  backLinear(-2.25, -20, 2);
  intakes::spinMaxIn();
  Indexer.spin(fwd, 100, pct);
  IgnoreY(112, 116.5, turnDirection::right, 1.6, 60, 25, 0.5);
  Indexer.stop(brake);

  goTo(124, 118, turnDirection::left, 3, 60, 35, 0.5);
  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 13, volt);
  wait(600, msec);
  Shooter.stop(hold);
  

  
  // 6th
  backLinear(-15, -40, 2);
  intakes::spinMaxIn();
  Indexer.spin(fwd, 100, pct);
  IgnoreX(107, 64, turnDirection::right, 1.8, 60, 30, 0.5);
  IgnoreY(123, 61, turnDirection::left, 1.8, 60, 30, 0.5);
  Shooter.spin(fwd, 100, pct);
  wait(150, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Shooter.stop(brake);
  
  intakes::spinMaxOut();

  //127,62.5
  setCoordinates(2);

  // 7th
  backLinear(-8, -30, 2);
  
  Indexer.spin(fwd, 100, pct);
  intakes::spinMaxIn();
  IgnoreX(113.5, 19.5, turnDirection::right, 2.1, 60, 35, 0.5);
  backLinear(-8, -20, 2);

  IgnoreY(128, 5, turnDirection::left, 3, 60, 35, 0.5);
  //lower x
  Shooter.spin(fwd, 13, volt);
  wait(200, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Shooter.stop(hold);
  wait(400, msec);

  
  
  //8th
  backLinear(-8, -30, 2);
  IgnoreY(80, 12, turnDirection::right, 2.1, 60, 40, 0.5);
  IgnoreX(79, 6.5, turnDirection::right, 2.2, 60, 40, 0.5);
  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 13, volt);
  wait(600, msec);
  Shooter.stop(hold);


  //9th

  backLinear(-4, -30, 3);
  intakes::spinMaxIn();
  Indexer.spin(fwd, 100, pct);
  IgnoreX(69, 36.5, turnDirection::right, 2.2, 60, 40, 0.5);

  wait(200, msec);

  intakes::spinMaxOut();
  dt::spinInPct(45, dt::sides::right);
  wait(30, msec);
  dt::spinInPct(45, dt::sides::left);

  wait(600, msec);
  
  dt::stop();

  wait(400, msec);

  dt::spinInPct(-25);

  wait(800, msec);

  dt::spinInPct(30, dt::sides::left);
  dt::spinInPct(40, dt::sides::right);

  wait(1000, msec);
  dt::spinInPct(30, dt::sides::left);

  wait(400, msec);
  
  dt::stop(coast);
  wait(100, msec);
  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 100, pct);


  wait(5, sec);
  dt::stop(coast);
}

void homeRow(){
  intakes::spinMaxIn();
  Indexer.spin(fwd, 100, pct);
  wait(200, msec);
  turnCurve(15, 25, 50);
  wait(200, msec);
  Shooter.spin(fwd, 100, pct);
  int ballCount = 0;
  dt::spinInPct(3);
  int timer1=0;
  while (ballCount < 2 && timer1 < 600){
    timer1++;
    if(Limit.pressing()){
      ballCount++;
      while(Limit.pressing()&&timer1<300){
        wait(5, msec);
        timer1++;
      }
    }
    wait(5, msec);
  }

  wait(20, msec);
  intakes::spinMaxOut();

  wait(600, msec);  
  
  Indexer.stop(brake);
  intakes::spinMaxOut();
  backLinear(-2.4, -30, 3);
  
  turnCurve(45, -50, -68);
  ballCount = 0;
  
  intakes::spinMaxIn();
  IgnoreX(64, 3, turnDirection::left, 2.2, 60, 45, 0.5);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  timer1 = 0;
  wait(100, msec);
  dt::spinInPct(1);
  while (ballCount < 2 && timer1 < 600){
    timer1++;
    if(Limit.pressing()){
      ballCount++;
      while(Limit.pressing()){
        wait(5, msec);
      }
    }
    wait(5, msec);
  }
  wait(20, msec);
  intakes::spinMaxOut();

  wait(200, msec);  
  
  Indexer.spin(reverse, 50, pct);
  intakes::spinMaxOut();

  backLinear(-11, -40, 3); 

  intakes::spinMaxIn();
  Indexer.spin(fwd, 100, pct);
  ballCount = 0;

  IgnoreY(128, -6, turnDirection::left, 1.65, 60, 30, 0.5);

  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);

  wait(100, msec);
  timer1 = 0;
  while (ballCount < 2 && timer1 < 600){
    timer1++;
    if(Limit.pressing()){
      ballCount++;
      while(Limit.pressing()){
        wait(5, msec);
      }
    }
    wait(5, msec);
  }
  wait(50, msec);
  intakes::spinMaxOut();

  wait(100, msec);

  Shooter.stop(hold);
  Indexer.spin(reverse, 100, pct);
  backLinear(-14.4, -40, 3);

  dt::stop(coast);
}

void homeRowRight(){
  intakes::spinMaxIn();
  Indexer.spin(fwd, 60, pct);
  wait(300, msec);
  turnCurve(24.6, 80, 20);
  intakes::spinMaxOut();
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
  Shooter.spin(fwd, 13, volt);
  intakes::spinMaxIn();
  IgnoreX(68, 1.5, 1, 2.2, 60, 45, 0.5);
  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 100, pct);
  ballCount = 0;
  while(ballCount < 2){
    int prevBallCount = ballCount;
    if(LineSensor.value(pct) < 56){
      ballCount++;
    }
    if(prevBallCount < ballCount){
      wait(125, msec);
    }
  }
  intakes::spinMaxOut();
  wait(100, msec);
  Indexer.spin(reverse, 30, pct);
  wait(200, msec);
  Shooter.stop(brake);
  backLinear(-14, -30, 3);
  Shooter.spin(fwd, 100, pct);
  wait(500, msec);
  intakes::spinMaxIn(intakes::motors::left);
  intakes::spinInPct(80, intakes::motors::right);
  Indexer.spin(fwd, 80, pct);
  IgnoreY(127.75, 20.5, 1, 1.75, 60, 35, 0.5);
  Shooter.spin(fwd, 100, pct);
  wait(500, msec);
  
  // wait(100, msec);
  intakes::spinMaxOut();
  wait(200, msec);
  backLinear(-12, -40, 3);
  intakes::stop(coast);
  */
  
}

void rightAndSide(){
  intakes::spinMaxIn();
  Indexer.spin(fwd, 100, pct);
  wait(300, msec);
  turnCurve(24.6, 70, 28);
  Shooter.spin(fwd, 13, volt);
  wait(100, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Shooter.stop(brake);
  intakes::spinMaxOut();
  wait(500, msec);
  backLinear(-1.6, -25, 2);
  Indexer.spin(fwd, 100, pct);

  IgnoreX(6.75, -27,turnDirection::left, 2.2, 60, 35, 0.5);
  intakes::spinMaxIn();
  dt::spinInPct(100, dt::sides::left);
  dt::spinInPct(85, dt::sides::right);
  wait(500, msec);

  dt::spinInPct(10);
  int tracker = 0;
  int ballCount = 0;
  while (ballCount < 1 && tracker < 300){
    if(Limit.pressing()){
      ballCount++;
      while(Limit.pressing()){
        wait(10, msec);
      }
    }
    wait(10, msec);
    tracker++;
  }
  dt::stop(coast);

  wait(300, msec);
  Indexer.spin(fwd, 100, pct);
  Shooter.spin(fwd, 100, pct);

  wait(800, msec);
  Shooter.spin(reverse, 100, pct);

  wait(800, msec);
  Shooter.spin(fwd, 100, pct);

  wait(500, msec);
  intakes::spinMaxOut();
  wait(500, msec);
  backLinear(-8, -40, 4);
}

void Side(){
  
}

void Center(){
  Inertial.setHeading(270, deg);
  wait(2, sec);

  intakes::spinMaxIn();
  IgnoreY(0, 0, turnDirection::none, 2.2, 60, 45, 0.5);

  IgnoreX(0, 29, turnDirection::right, 2.2, 60, 45, 0.5);

  IgnoreY(-18, 31.5, turnDirection::left, 2.2, 60, 45, 70);
  wait(8, sec);

  intakes::spinMaxIn();
  dt::spinInPct(100);

  wait(500, msec);

  dt::stop(coast);

  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Shooter.stop(brake);

  intakes::spinMaxOut();
  dt::spinInPct(-100);

  wait(500, msec);


  dt::stop(coast);


  wait(5, sec);
  dt::stop(coast);
}

void OrcahBlue(){
  intakes::spinMaxIn();
  turnCurve(16, 15, 56);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);
  intakes::spinMaxOut();
  turnCurve(51, -50, -68);
  
  IgnoreX(53.5, 1.25, turnDirection::left, 2.2, 60, 45, 0.5);
  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Shooter.stop(hold);

  intakes::stop(hold);

  backLinear(-11.2, -40, 3);

  intakes::spinMaxIn(intakes::motors::left);
  intakes::spinInPct(80, intakes::motors::right);
  Indexer.spin(fwd, 80, pct);

  IgnoreY(129.75, -39, turnDirection::left, 1.65, 60, 30, 0.5);

  Indexer.spin(fwd, 13, volt);
  Shooter.spin(fwd, 100, pct);
  wait(600, msec);
  intakes::spinMaxOut();

  wait(1, sec);
  backLinear(-19.6, -40, 3);

  dt::stop(coast);
}