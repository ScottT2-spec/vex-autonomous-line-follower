#include "vex.h"
using namespace vex;

brain Brain;
controller Controller1;

// Motors
motor LeftMotor(PORT1, ratio18_1, false);
motor RightMotor(PORT10, ratio18_1, true); // had to reverse this one or robot spins

motor ArmMotor(PORT8, ratio36_1, false);
motor ClawMotor(PORT3, ratio36_1, false);

// Sensors
distance DistSensor(PORT5);                 // front distance sensor
line LineSensor(Brain.ThreeWirePort.A);     // line tracker underneath

int speed = 40;
int turnFix = 25;
int stopDist = 150; // mm


void preSetup() {
  ArmMotor.setStopping(hold);   // stops arm from dropping
  ClawMotor.setStopping(hold);
  ArmMotor.setVelocity(60, percent);
  ClawMotor.setVelocity(60, percent);
}


// ------------ AUTONOMOUS (line + obstacle) ------------
void autonomousMode() {

  while(true) {

    int lineVal = LineSensor.value(percent);     // lower = darker line
    int dist = DistSensor.objectDistance(mm);

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("Line: %d", lineVal);
    Brain.Screen.setCursor(2,1);
    Brain.Screen.print("Dist: %d", dist);

    // if something is too close, stop and turn away
    if(dist > 0 && dist < stopDist) {

      Brain.Screen.setCursor(3,1);
      Brain.Screen.print("Too close!");

      LeftMotor.stop();
      RightMotor.stop();
      wait(400, msec);

      // back up a bit
      LeftMotor.spinFor(reverse, 180, degrees, false);
      RightMotor.spinFor(reverse, 180, degrees);
      
      // turn right to avoid
      LeftMotor.spinFor(forward, 200, degrees, false);
      RightMotor.spinFor(reverse, 200, degrees);
    }

    // otherwise just follow the line
    else {

      if(lineVal < 45) {
        // on the line
        LeftMotor.spin(forward, speed, percent);
        RightMotor.spin(forward, speed, percent);
      }
      else {
        // lost the line, try turning to find it again
        LeftMotor.spin(forward, turnFix, percent);
        RightMotor.spin(reverse, turnFix, percent);
      }
    }

    wait(25, msec); // small delay so brain doesn’t lag
  }
}


// ------------ DRIVER CONTROL ------------
void usercontrol() {

  while(true) {

    // tank drive
    LeftMotor.spin(forward, Controller1.Axis3.position(), percent);
    RightMotor.spin(forward, Controller1.Axis2.position(), percent);

    // arm up/down
    if(Controller1.ButtonL1.pressing()) {
      ArmMotor.spin(forward);
    }
    else if(Controller1.ButtonL2.pressing()) {
      ArmMotor.spin(reverse);
    }
    else {
      ArmMotor.stop();
    }

    // claw open/close
    if(Controller1.ButtonR1.pressing()) {
      ClawMotor.spin(forward);
    }
    else if(Controller1.ButtonR2.pressing()) {
      ClawMotor.spin(reverse);
    }
    else {
      ClawMotor.stop();
    }

    wait(20, msec);
  }
}


int main() {

  preSetup();

  // change this depending on what you're testing
  autonomousMode();
  // usercontrol();

}
