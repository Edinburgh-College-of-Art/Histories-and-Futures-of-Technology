//=======================================================
// File: Stepper_Analog_Position.ino
//
// Description:
//
//  This sketch uses the analog read value to control the
//  position of a stepper motor.
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
int in1Pin = 8;
int in2Pin = 9;
int in3Pin = 10;
int in4Pin = 11;

int inputPin = A0;

// Stepper motors do not know their position like servos do
// We will need to track how many steps the motor has taken in code
int position = 0;

const int stepsPerRevolution = 2048;
Stepper stepper = Stepper(stepsPerRevolution, in1Pin, in3Pin, in2Pin, in4Pin);

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Set motor speed
  stepper.setSpeed(10);
}

void loop() {

  // Get target position from analog read value
  int readValue = analogRead(inputPin);
  int target = map(readValue, 0, 1023, 0, 204) * 10; // 0-1023 -> 0-2040

  // Stepper in direction of target position
  if (position < target) {
    stepper.step(10);
    position += 10;  // Keep track of step position
  }
  if (position > target) {
    stepper.step(-10);
    position -= 10;  // Keep track of step position
  }

  // Print values to serial monitor
  Serial.print(readValue);
  Serial.print(",");
  Serial.print(target);
  Serial.print(",");
  Serial.print(position);
  Serial.println();
}