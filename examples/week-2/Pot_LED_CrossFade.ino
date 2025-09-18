//=======================================================
// File: Pot_LED_CrossFade.ino
//
// Description:
//  This code usees a potentiometer to fade between 
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
//   Pin 3 (PWM) ---> LED ---> 220Ω ---> GND
//
//   Pin 5 (PWM) ---> LED ---> 220Ω ---> GND
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

  // Use map() to adjust input range
  // input:  0-1023
  // output: 0-255
  int brightness1 = map(potValue, 0, 1023, 0, 255);
  int brightness2 = map(potValue, 0, 1023, 255, 0); // inverse
  
  // Adjust LED brightness
  analogWrite(led1Pin, brightness1);
  analogWrite(led2Pin, brightness2);

  // Print values to serial monitor
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(", LED 1 Brightness: ");
  Serial.print(brightness1);
  Serial.print(", LED 2 Brightness: ");
  Serial.println(brightness2);
}
