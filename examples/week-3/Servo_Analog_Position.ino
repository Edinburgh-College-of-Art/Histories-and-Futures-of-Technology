//=======================================================
// File: Servo_Analog_Position.ino
//
// Description:
//
//  This sketch uses the analog read value to control the
//  position of a servo motor.
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

#include <Servo.h>

int inputPin = A0;
int servoPin = 9;

Servo servo;  // This object will handle the servo control signals

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Tell the servo object what pin the servo is connected to
  servo.attach(servoPin);
}

void loop() {
  // Get position from analog input value
  int readValue = analogRead(inputPin);                // Get value from analog pin
  int servoPosition = map(readValue, 0, 1023, 0, 180);  // Scale from 0-1023 to 0-180

  servo.write(servoPosition);  // Set servo to new position

  // Print values to serial monitor
  Serial.print(readValue);
  Serial.print(",");
  Serial.print(servoPosition);
  Serial.println();
}