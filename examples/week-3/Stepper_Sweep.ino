//=======================================================
// File: Stepper_Sweep.ino
//
// Description:
//
//  This sketch will move a stepper motor clockwise then
//  counter-clockwise every second.
//
//  The type of movement of the motor is dictated by the
//  starting paramters. Changing these will change the
//  movement "characteristics"
//
// Pinout:
//
//  | Arduino | Stepper |
//  |---------|---------|
//  | GND     | -       |
//  | 5V      | +       |
//  | 8       | IN1     |
//  | 9       | IN2     |
//  | 10      | IN3     |
//  | 11      | IN4     |
//
//=======================================================

//=======================================================
// MOVEMENT PARAMTERS

bool startDirection = true;   // cw = true, ccw = false
bool changeDirection = true;  // change direction every move?

int moveDistance = 2048;  // steps travelled per move (2048 steps = 1 full revolution)
int moveTime = 1500;      // time spent before moving again (ms)
int moveSpeed = 10;       // RPM

//=======================================================

#include <Stepper.h>  // Arduino stepper motor library

// Define pin numbers
int in1Pin = 8;
int in2Pin = 9;
int in3Pin = 10;
int in4Pin = 11;

bool cw = startDirection;

const int stepsPerRevolution = 2048;
Stepper stepper = Stepper(stepsPerRevolution, in1Pin, in3Pin, in2Pin, in4Pin);

void setup() {
  // Set motor speed
  stepper.setSpeed(moveSpeed);
}

void loop() {
  // Move stepper pre-defined distance
  if (cw == true) stepper.step(-moveDistance);
  if (cw == false) stepper.step(moveDistance);

  // Wait for pre-defined time
  delay(moveTime);

  if (changeDirection) cw = !cw;  // change direction
}