//=======================================================
// File: Servo_Sweep.ino
//
// Description:
//
//  This sketch will move a servo motor between 0° to 180°
//
//  The type of movement of the servo is dictated by the
//  starting paramters. Changing these will change the
//  movement "characteristics"
//
// Pinout:
//
//  | Arduino | Servo        |
//  |---------|--------------|
//  | GND     | Black/Brown  |
//  | 5V      | Red          |
//  | 9 (PWM) | White/Orange |
//
//=======================================================

//=======================================================
// MOVEMENT PARAMTERS

int servoPin = 9;  // pin connected to servo

int startingPosition = 0;  // starting position (0-180)

int stepDistance = 20;  // distance travelled per step (0-180)
int stepTime = 1500;    // time spent at each step before next position (ms)
int stepSpeed = 9;      // speed of step movement (0-10)

//=======================================================

#include <Servo.h> // Arduino servo motor library

int position = startingPosition;
int delayTime = map(stepSpeed, 0, 10, 50, 1);
bool goingUp;

Servo servo;  // This object will handle the servo control signals

void setup() {
  // Tell the servo object what pin the servo is connected to
  servo.attach(servoPin);

  // Move to starting position
  servo.write(position);
}

void loop() {
  // Move to next position...
  for (int i = 0; i < stepDistance; i++) {
    // Check if reached limits
    if (position == 0) goingUp = true;
    if (position == 180) goingUp = false;

    // Increment position
    if (goingUp == true) position++;   // +1 if going up
    if (goingUp == false) position--;  // -1 if going down

    servo.write(position);
    delay(delayTime);
  }

  // Wait for step time before moving to next position
  delay(stepTime);
}
