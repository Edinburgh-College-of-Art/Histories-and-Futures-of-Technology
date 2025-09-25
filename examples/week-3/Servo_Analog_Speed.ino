//=======================================================
// File: Servo_Analog_Speed.ino
//
// Description:
//
//  This sketch uses the analog read value to control the
//  speed of a servo motor.
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
  // Get delay time from analog input value
  int readValue = analogRead(inputPin);              // Get value from analog pin
  int delayTime = map(readValue, 0, 1023, 10, 200);  // Scale from 0-1023 to 10-100

  // Increment position
  if (goingUp == true) position++;  // +1 if going up
  if (goingUp == false) position--; // -1 if going down
  
  // Check if reached limits
  if (position == 0) goingUp = true;    
  if (position == 180) goingUp = false;

  servo.write(position);  // Set servo to new position
  delay(delayTime);

  // Print values to serial monitor
  Serial.print(readValue);
  Serial.print(",");
  Serial.print(position);
  Serial.println();
}