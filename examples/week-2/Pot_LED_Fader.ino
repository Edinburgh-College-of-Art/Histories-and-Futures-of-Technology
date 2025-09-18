//=======================================================
// File: Pot_LED_Fader.ino
//
// Description:
//  This code reads the potentiometer value and adjusts 
//  an LED's brightness using PWM.
//
//  Upload this code to your Arduino and open 
//  the Serial Monitor to view live readings.
//
// Wiring: 
//  
//   GND ---> Potentiometer ---> 5V
//                 |
//                 |
//                 A0
//
//   Pin 3 (PWM) ---> LED ---> 220Ω ---> GND
//  
//  This code is in the public domain
//=======================================================

// Store pin numbers
int potPin = A0;
int ledPin = 3;

void setup() {
  // Begin serial communication
  Serial.begin(9600); // ensure Serial Monitor is also using baud rate of 9600

  // Initialise LED pin as output
  pinMode(ledPin, OUTPUT);
  // Don't need to set potPin as INPUT, analog pins are input by default
}

void loop() {
  // Get potentiometer value
  int potValue = analogRead(potPin);  
  
  // Use map() to adjust input range
  // input:  0-1023
  // output: 0-255
  int brightness = map(potValue, 0, 1023, 0, 255);
  
  // Set LED brightness using PWM (value between 0 and 255)
  analogWrite(ledPin, brightness);

  // Print output to serial monitor
  Serial.print(potValue);
  Serial.print(",");
  Serial.println(brightness);
}
