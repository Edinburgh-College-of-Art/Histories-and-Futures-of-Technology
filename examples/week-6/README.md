# Week 6

## Contents

- [Session Outline](#session-outline)
- [ThingSpeak](#thingspeak)
- [Code](#code)

## Session Outline

Week 6's session will look at sending data to and from a cloud data storage service - ThingSpeak.

## ThingSpeak

This week's session will require you to have set up an account to use ThingSpeak. ThingSpeak is a cloud data storage service that we will be sending data to and from out Arduino Nano 33 IoT boards using a Wi-Fi connection.

You can create your free account [here](http://www.mathworks.com/mwaccount/register) and then login at [www.thingspeak.com](www.thingspeak.com).

## Code

You will need to install the [WiFiNINA](https://docs.arduino.cc/libraries/wifinina/) and [ThingSpeak](https://docs.arduino.cc/libraries/thingspeak/) libraries before uploading these sketches.

- [ThingSpeakWrite.ino](./ThingSpeakWrite.ino) - for posting data to cloud
- [ThingSpeakRead.ino](./ThingSpeakRead.ino) - for pulling data from cloud
