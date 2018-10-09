/*
  WriteVoltage with Yun

  Reads an analog voltage from pin 0, and writes it to a channel on ThingSpeak every 20 seconds.

*/
//====================================================================================
#include "ThingSpeak.h"
#include "YunClient.h"
//====================================================================================
// client Details

YunClient client;
const unsigned long postingInterval = 15000;  // delay between updates. Minimum 15000

//====================================================================================
// API details

unsigned long channelNumber = 31461;
const char * writeAPIKey = "LD79EOAAWRVYF04Y"; // ENTER YOUR WRITE API KEY HERE!!!

//====================================================================================

void setup()
{
  Bridge.begin();
  ThingSpeak.begin(client);
}

//====================================================================================

void loop()
{

  unsigned long now = millis(); // Get a timestamp so you can calculate reading and sending intervals:

  if (now - lastRequest >= postingInterval)
  {
    int sensorValue = analogRead(A0);
    float voltage = sensorValue * (5.f / 1023.f);
    ThingSpeak.writeField(channelNumber , 1, voltage, writeAPIKey);

    lastRequest = now;
  }
}

//====================================================================================

