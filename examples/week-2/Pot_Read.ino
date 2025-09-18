//=======================================================
// File: Pot_Read.ino
//
// Description:
//  This code reads the potentiometer value and outputs 
//  it to the Serial Monitor. 
//  
//  Upload the code to your Arduino and open 
//  the Serial Monitor to view the live readings.
//
// Pinout: 
//
//   GND ---> Potentiometer ---> 5V
//                 |
//                 |
//                 A0
//  
//  This code is in the public domain
//=======================================================

// Store pin number
int potPin = A0;

void setup() {
  // Begin serial communication
  Serial.begin(9600); // ensure Serial Monitor is also using baud rate of 9600
}

void loop() {
  // Get potentiometer value
  int potValue = analogRead(potPin);  

  // Print output to serial monitor
  Serial.println(potValue);
}
