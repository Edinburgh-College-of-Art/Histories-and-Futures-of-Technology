/*
    Send a reading from KNOB_1 and the string "Hello" to Thingspeak every 15
   seconds
*/

#include <DI.h>
#include <ThingSpeak.h>
#include <WiFiNINA.h>

const char *ssid = "HANABI";
const char *password = "lowernorwood";

WiFiClient client;

const unsigned long postingInterval = 15000; // ThingSpeak has a rate limit of 15 seconds
unsigned long lastRequest = 0;
/**********************/
unsigned long channelNumber = 1234567; // ********* You need to change this value
const char *writeAPIKey = "ABCDEFGHIJKLMNOP"; // and this one *************
/**********************/

void setup() {
  Serial.begin(9600);

  int conn = WiFi.begin(ssid, password);
  if (conn != WL_CONNECTED) {
    Serial.println("Failed to Connect");
    while (1) {
    }
  }

  Serial.print("Connected to ");
  Serial.println(ssid);

  ThingSpeak.begin(client);
}

void loop() {
  updateKnobs();

  if (millis() - lastRequest > postingInterval) {
    Serial.println(KNOB_1);
    ThingSpeak.setStatus("hello");
    ThingSpeak.setField(1, KNOB_1);
    ThingSpeak.writeFields(channelNumber, writeAPIKey);
    lastRequest = millis();
  }

  delay(25);
}