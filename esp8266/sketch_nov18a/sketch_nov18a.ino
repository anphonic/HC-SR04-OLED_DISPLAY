;#include <Adafruit_ESP8266.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
//#include <ESP8266_Simple.h>

#define SSID""
#define PASS ""

Adafruit_ESP8266 wifi(8,9);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("ESP8266 Demo Sketch");

  wifi.begin(9600);
  wifi.setupAsWifiStation(SSID,PASS,&Serial);

}

void loop() {
  // put your main code here, to run repeatedly:

}
