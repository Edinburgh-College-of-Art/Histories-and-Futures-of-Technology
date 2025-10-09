//=======================================================
// File: DIBoard_GroveSound_NeoPixel.ino
//
// Description:
//  This code uses the input from a Grove sound sensor to
//  create a "sound meter" with the onboard NeoPixels.
//
//  Upload this code to your Arduino and open
//  the Serial Monitor to view live readings.
//
// Wiring:
//  Connect Grove sound sensor to the Grove 2 Dev 
//  connector on the DI board. 
//
//  This code is in the public domain
//=======================================================

#include <DI.h> // DI Board Library

#define SOUND_PIN A2
#define MAX_INPUT_VAL 300

#define NUM_LEDS 9

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Initialise onboard components (which include NeoPixels)
  setupEverything();
  LEDS.setBrightness(50);  // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  // 1. Get sound value
  int soundValue = analogRead(SOUND_PIN);
  soundValue = constrain(soundValue, 0, MAX_INPUT_VAL);

  // 2. Get number of LEDs to turn on (0-9)
  int ledsOn = map(soundValue, 0, MAX_INPUT_VAL, 0, NUM_LEDS);

  // 3. Clear all LED states (turn them all off)
  LEDS.clear();

  // 4. Set pixel colour(s)
  for (int pixel = 0; pixel < ledsOn; pixel++) {
    if (pixel < 4)
      LEDS.setPixelColor(pixel, 0, 255, 0);  // Pixels 1-4 = Green
    else if (pixel < 7)
      LEDS.setPixelColor(pixel, 255, 150, 0);  // Pixels 5-7 = Yellow
    else
      LEDS.setPixelColor(pixel, 255, 0, 0);  // Pixels 8-9 = Red
  }

  // 5. Display changes
  LEDS.show();

  // 6. Print data to serial monitor
  Serial.print(soundValue);
  Serial.print(",");
  Serial.print(0);
  Serial.print(",");
  Serial.print(MAX_INPUT_VAL);
  Serial.print(",");
  Serial.println(ledsOn);
}