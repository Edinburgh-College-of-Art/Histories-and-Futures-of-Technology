//=======================================================
// File: Pot_Blinker.ino
//
// Description:
//  This code reads the potentiometer value and adjusts
//  the frequency of a blinking LED.
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
//   Pin 3 ---> LED ---> 220Ω ---> GND
//
//  This code is in the public domain
//=======================================================

// Store pin numbers
int potPin = A0;
int ledPin = 3;

void setup() {
  // Begin serial communication
  Serial.begin(9600);  // ensure Serial Monitor is also using baud rate of 9600

  // Initialise LED pin as output
  pinMode(ledPin, OUTPUT);
  // Don't need to set potPin as INPUT, analog pins are input by default
}

void loop() {
  // Get potentiometer value
  int potValue = analogRead(potPin);

  // Use map() to adjust input range
  // input:  0-1023
  // output: 20-1000
  int delayTimeInMilliseconds = map(potValue, 0, 1023, 20, 1000);

  // Print values to serial monitor
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(", Delay (ms): ");
  Serial.println(delayTimeInMilliseconds);

  // Blink LED
  digitalWrite(ledPin, HIGH);  // ON
  delay(delayTimeInMilliseconds);
  digitalWrite(ledPin, LOW);  // OFF
  delay(delayTimeInMilliseconds);
}
