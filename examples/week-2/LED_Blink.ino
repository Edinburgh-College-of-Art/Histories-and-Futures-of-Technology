//=======================================================
// File: LED_Blink.ino
//
// Description:
//
//  Basic LED Blink sketch, essentially same sketch as
//  can be found at File > Examples > 01.Basics > Blink
//
//  Turns an LED on for one second, then off for one 
//  second, repeatedly.
//
// Pinout:
//
//   Pin 3 ---> LED ---> 220Ω ---> GND
//
//  This code is in the public domain
//=======================================================

// Store pin number
int ledPin = 3;

void setup() {
  // Begin serial communication
  Serial.begin(9600);  // ensure Serial Monitor is also using baud rate of 9600

  // Initialise LED pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH); // LED On
  Serial.println("LED ON");   // Print to Serial Monitor
  delay(1000);

  digitalWrite(ledPin, LOW); // LED Off
  Serial.println("LED OFF"); // Print to Serial Monitor
  delay(1000);
}