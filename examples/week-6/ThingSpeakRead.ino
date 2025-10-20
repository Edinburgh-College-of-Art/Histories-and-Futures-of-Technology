/*
    Read the latest value of Field 1 from Thingspeak every 15 seconds
    and update the servo to reflect the new value.
*/

#include <DI.h>
#include <ThingSpeak.h>
#include <WiFiNINA.h>

const char *ssid = "HANABI";
const char *password = "lowernorwood";

WiFiClient client;

const unsigned long postingInterval =
    15000; // ThingSpeak has a rate limit of 15 seconds
unsigned long lastRequest = 0;
/**********************/
unsigned long channelNumber =
    1234567; // ********* You need to change this value
const char *writeAPIKey = "ABCDEFGHIJKLMNOP"; // and this one *************
/**********************/

Servo servo1;

//
void setup() {
  Serial.begin(9600);

  int conn = WiFi.begin(ssid, password);
  if (conn != WL_CONNECTED) {
    Serial.print("Failed to Connect");
    while (1) {
    }
  }

  Serial.print("Connected to ");
  Serial.println(ssid);

  ThingSpeak.begin(client);

  servo1.attach(SERVO_1);
}

//
void loop() {
  if (millis() - lastRequest > postingInterval) {
    int val = ThingSpeak.readIntField(channelNumber, 1, readAPIKey);
    lastRequest = millis();

    // Update the servo
    int angle = map(val, 0, 1023, 0, 180);
    Serial.print(val);
    Serial.print(", ");
    Serial.println(angle);

    servo1.write(angle);
    delay(15);
  }

  delay(25);
}