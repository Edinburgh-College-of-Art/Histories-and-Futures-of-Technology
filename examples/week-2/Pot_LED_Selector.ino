//=======================================================
// File: Pot_LED_Selector.ino
//
// Description:
//  This code usees a potentiometer to select between 
//  two LEDs.
//
//  Upload this code to your Arduino and open
//  the Serial Monitor to view live readings.
//
// Pinout:
//
//   GND ---> Potentiometer ---> 5V
//                 |
//                 |
//                 A0
//
//   Pin 3 ---> LED ---> 220Ω ---> GND
//
//   Pin 5 ---> LED ---> 220Ω ---> GND
//
//  This code is in the public domain
//=======================================================

// Store pin numbers
int potPin = A0;
int led1Pin = 3;
int led2Pin = 5;

void setup() {
  // Begin serial communication
  Serial.begin(9600);  // ensure Serial Monitor is also using baud rate of 9600

  // Initialise LED pins as output
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  // Don't need to set potPin as INPUT, analog pins are input by default
}

void loop() {
  // Get potentiometer value
  int potValue = analogRead(potPin);

  // Print values to serial monitor
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(", LED Selected: ");
  

  if (potValue < 1023 / 2) {
      digitalWrite(led1Pin, HIGH); // LED 1 ON
      digitalWrite(led2Pin, LOW);  // LED 2 OFF
      Serial.println(1);
  }
  else {
      digitalWrite(led1Pin, LOW);  // LED 1 OFF
      digitalWrite(led2Pin, HIGH); // LED 2 ON
      Serial.println(2);
  }
    
}
