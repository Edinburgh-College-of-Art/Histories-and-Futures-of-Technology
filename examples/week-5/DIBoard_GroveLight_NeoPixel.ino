//=======================================================
// File: DIBoard_GroveLight_NeoPixel.ino
//
// Description:
//  This code uses the input from a Grove digital light
//  sensor to create a "light meter" with the onboard
//  NeoPixels.
//
//  Upload this code to your Arduino and open
//  the Serial Monitor to view live readings.
//
// Wiring:
//  Connect Grove digital light sensor to the Grove I2C
//  connector on the DI board.
//
//  This code is in the public domain
//=======================================================

#include <DI.h>  // DI Board Library

#include <Wire.h>                   // I2C Library
#include <Digital_Light_TSL2561.h>  // Digital Light Sensor Library

#define MAX_INPUT_VAL 500
#define NUM_LEDS 9

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Initialise onboard components (which include NeoPixels)
  setupEverything();
  LEDS.setBrightness(50);  // Set BRIGHTNESS to about 1/5 (max = 255)

  // Initialise light sensor
  Wire.begin();  // Start I2C
  TSL2561.init();
}

void loop() {
  // 1. Get light value
  int lightValue = TSL2561.readVisibleLux();
  lightValue = constrain(lightValue, 0, MAX_INPUT_VAL);  // Keep between 0-MAX_INPUT_VAL

  // 2. Get number of LEDs to turn on (0-9)
  int ledsOn = map(lightValue, 0, MAX_INPUT_VAL, 0, NUM_LEDS);

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
  Serial.print(TSL2561.readVisibleLux());
  Serial.print(",");
  Serial.print(lightValue);
  Serial.print(",");
  Serial.println(scaledValue);
}