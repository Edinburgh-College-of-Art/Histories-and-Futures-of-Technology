/*
  ThingSpeak sensor client

  This sketch connects an analog sensor to ThingSpeak, using an Arduino Yún.
  
*/
//====================================================================================

#include <Process.h>

//====================================================================================

String writeAPIKey = "YWDMU4I4LEB0V0PE";      // ENTER YOUR WRITE API KEY HERE!!!

//====================================================================================
// client info:
const unsigned long postingInterval = 15000;  // delay between updates. Minimum 15000
unsigned long lastRequest = 0;                // when you last made a request
String dataString = "";

//====================================================================================

void setup() 
{
  Bridge.begin(); // start serial port:
  Serial.begin(9600);
  while(!Serial){};   // Block waiting for Network Serial to open
  Serial.println("ThingSpeak client");
  updateData(); // Do a first update immediately
  sendData();
  lastRequest = millis();
}

//====================================================================================

void loop() 
{
  long now = millis(); // Get a timestamp so you can calculate reading and sending intervals:

  // If the sending interval has passed since the
  // last connection, then connect again and send data:
  if (now - lastRequest >= postingInterval) 
  {
    updateData();
    sendData();
    lastRequest = now;
  }
}

//====================================================================================

void updateData() 
{
  // ADD CODE HERE TO READ YOUR SENSOR(S) 
  
  // Convert the readings to a String to send it:
  dataString = "";
  dataString = "api_key=" + writeAPIKey + "&";
  dataString += "field1=";
  dataString += random(10) + 20;
//  dataString += "field2=";
//  dataString += ;
//  dataString += "field3=";
//  dataString += ;
// ETC ...
  
  Serial.println("dataString " + dataString);
}


// This function makes a HTTP connection to the server:
void sendData() 
{
  // Form the string for the URL parameter:
  String url = "https://api.thingspeak.com/update";
  Serial.println("url " + url);
  
  // Send the HTTP GET request.
  // Is better to declare the Process here, so when the
  // sendData function finishes the resources are immediately
  // released. Declaring it global works too, BTW.
  Process thingSpeak;
  Serial.print("\n\nSending data... ");
  thingSpeak.begin("curl");
  thingSpeak.addParameter("-k");
  thingSpeak.addParameter("--request");
  thingSpeak.addParameter("GET");
  thingSpeak.addParameter("--data");
  thingSpeak.addParameter(dataString);
  thingSpeak.addParameter(url);
  thingSpeak.run();
  Serial.println("done!");

  // If there's incoming data from the net connection, send it out the Serial:
  while (thingSpeak.available() > 0) 
  {
    char c = thingSpeak.read();
    Serial.write(c);
  }
}

