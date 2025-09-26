//=======================================================
// File: Servo_Analog_SelectMovement.ino
//
// Description:
//
//  This sketch uses the analog read value to control the
//  type of movement of a servo motor.
//
//  You can use the analog read value to select:
//      - Smooth and slow movement.
//      - Smooth and fast movement.
//      - Jagged and slow movement.
//      - Jagged and fast movement.
//
//  Upload this sketch and open the serial monitor to
//  view debug messages.
//
// Pinout:
//
//  | Arduino | Servo        |
//  |---------|--------------|
//  | GND     | Black/Brown  |
//  | 5V      | Red          |
//  | 9 (PWM) | White/Orange |
//
//   GND ---> Analog sensor ---> 5V
//                 |
//                 |
//                 A0
//
//=======================================================

#include <Servo.h>  // Arduino servo motor library

// Define pin numbers
int inputPin = A0;
int servoPin = 9;

// Global variables
int numSteps, moveDelay, stepDelay;  // step parameters
int position = 0;
bool goingUp = true;

Servo servo;  // This object will handle the servo control signals

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Tell the servo object what pin the servo is connected to
  servo.attach(servoPin);
}

void loop() {
  // Get position from analog input value
  int readValue = analogRead(inputPin);  // Get value from analog pin
  int servoMode = map(readValue, 0, 1023, 0, 3);

  // Select movement type
  switch (servoMode) {
    case 0:
      smoothAndSlow();
      break;
    case 1:
      smoothAndFast();
      break;
    case 2:
      jaggedAndSlow();
      break;
    case 3:
      jaggedAndFast();
      break;
  }

  // move servo
  move();

  // Print values to serial monitor
  Serial.print(readValue);
  Serial.print(",");
  Serial.print(servoMode);
  Serial.println();
}

//=======================================================

void move() {
  // Move to next position...
  for (int i = 0; i < numSteps; i++) {
    // Check if reached limits
    if (position == 0) goingUp = true;
    if (position == 180) goingUp = false;

    // Increment position
    if (goingUp == true) position++;   // +1 if going up
    if (goingUp == false) position--;  // -1 if going down

    servo.write(position);
    delay(stepDelay);
  }

  // Wait for step time before moving to next position
  delay(moveDelay);
}

void smoothAndSlow() {
  numSteps = 1;
  stepDelay = 20;
  moveDelay = 0;
}

void smoothAndFast() {
  numSteps = 10;
  stepDelay = 3;
  moveDelay = 0;
}

void jaggedAndSlow() {
  numSteps = 30;
  stepDelay = 1;
  moveDelay = 1000;
}

void jaggedAndFast() {
  numSteps = 30;
  stepDelay = 1;
  moveDelay = 200;
}