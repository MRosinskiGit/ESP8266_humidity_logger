// server_handling.cpp
#include <Arduino.h>
#include "logging.h"
#include "server_handling.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


extern LoggerClass Logger;

ESPServerClass::ESPServerClass() {
  static ESP8266WebServer _server(80);
}

bool ESPServerClass::connectToWifi(char* ssid, char* password, int maxDelay) {
  Logger.log("Connecting to " + String(ssid));
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    // Logger.log(".", newLine=false);
  }
  Logger.log("\nWiFi Connected!");
  // Logger.log("Adres IP: "+String(WiFi.localIP()));
  return true;
}

void ESPServerClass::runServer() {
  // _server.on("/", _printHtmlData);
  // _server.on("/",     [](){    _server.send(200, "text/plain", "Hello World");  });
  _server.begin();
  Logger.log("Serwer HTTP is running!");
}
// void ESPServerClass::_printHtmlData() {
//   _server.send(200, "text/plain", "Hello World");
// }

void ESPServerClass::handleRequests() {
  _server.handleClient();
}
