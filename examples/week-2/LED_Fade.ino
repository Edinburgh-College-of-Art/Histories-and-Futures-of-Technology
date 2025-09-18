//=======================================================
// File: LED_Fader.ino
//
// Description:
//  Use PWM to fade an LED on for one second, then fade
//  off for one second, repeatedly.
//
// Pinout:
//
//   Pin 3 (PWM) ---> LED ---> 220Ω ---> GND
//
//  This code is in the public domain
//=======================================================

// Store pin number
int ledPin = 3;

// Calculate delay time needed to go between 0-255 in 1 second
int delayTimeInMilliseconds = 1000 / 255;

void setup() {
  // Begin serial communication
  Serial.begin(9600);  // ensure Serial Monitor is also using baud rate of 9600

  // Initialise LED pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn up brightness (0-255)
  Serial.println("FADE ON");

  for (int i = 0; i < 255; i++) {
    analogWrite(ledPin, i);
    Serial.println("Brightness: " + String(i));
    delay(delayTimeInMilliseconds);
  } 

  // Turn down brightness (255-0)
  Serial.println("FADE OFF");

  for (int i = 0; i < 255; i++) {
    analogWrite(ledPin, 255 - i);
    Serial.println("Brightness: " + String(255 - i));
    delay(delayTimeInMilliseconds);
  } 
}