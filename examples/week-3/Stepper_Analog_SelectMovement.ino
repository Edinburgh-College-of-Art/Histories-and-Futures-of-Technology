//=======================================================
// File: Stepper_Analog_SelectMovement.ino
//
// Description:
//
//  This sketch uses the analog read value to control the
//  type of movement of a stepper motor.
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
//  | Arduino | Stepper |
//  |---------|---------|
//  | GND     | -       |
//  | 5V      | +       |
//  | 8       | IN1     |
//  | 9       | IN2     |
//  | 10      | IN3     |
//  | 11      | IN4     |
//
//   GND ---> Analog sensor ---> 5V
//                 |
//                 |
//                 A0
//
//=======================================================

#include <Stepper.h>  // Arduino stepper motor library

// Define pin numbers
int inputPin = A0;

int in1Pin = 8;
int in2Pin = 9;
int in3Pin = 10;
int in4Pin = 11;

// Global Variables
int moveDistance, moveTime, moveSpeed;
bool cw = true, changeDirection;

const int stepsPerRevolution = 2048;
Stepper stepper = Stepper(stepsPerRevolution, in1Pin, in3Pin, in2Pin, in4Pin);

void setup() {
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Get position from analog input value
  int readValue = analogRead(inputPin);  // Get value from analog pin
  int stepperMode = map(readValue, 0, 1000, 0, 3);

  // Select movement type
  switch (stepperMode) {
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

  // move stepper
  move();

  // Print values to serial monitor
  Serial.print(readValue);
  Serial.print(",");
  Serial.print(stepperMode);
  Serial.println();
}

//=======================================================

void move() {
  // Set motor speed
  stepper.setSpeed(moveSpeed);

  // Move stepper pre-defined distance
  if (cw == true) stepper.step(-moveDistance);
  if (cw == false) stepper.step(moveDistance);

  // Wait for pre-defined time
  delay(moveTime);

  if (changeDirection) cw = !cw;  // change direction
}

void smoothAndSlow() {
  moveDistance = 20;
  moveTime = 0;
  moveSpeed = 2;
  changeDirection = false;
}

void smoothAndFast() {
  moveDistance = 20;
  moveTime = 0;
  moveSpeed = 10;
  changeDirection = false;
}

void jaggedAndSlow() {
  moveDistance = 500;
  moveTime = 1000;
  moveSpeed = 5;
  changeDirection = true;
}

void jaggedAndFast() {
  moveDistance = 500;
  moveTime = 200;
  moveSpeed = 10;
  changeDirection = true;
}