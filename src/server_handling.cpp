// server_handling.cpp
#include <Arduino.h>
#include "logging.h"
#include "server_handling.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


extern LoggerClass Logger;

ESP8266WebServer ESPServerClass::_server(80); //Declared private static variable

ESPServerClass::ESPServerClass() {
}

bool ESPServerClass::connectToWifi(char* ssid, char* password, int maxDelay) {
  Logger.log("Connecting to " + String(ssid));
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Logger.log(".", false);
  }
  Logger.log("\nWiFi Connected!");
  String ip = WiFi.localIP().toString();
  Logger.log("Adres IP: " + ip);
  return true;
}

void ESPServerClass::runServer() {
  _server.on("/", _printHtmlData);
  _server.begin();
  Logger.log("Serwer HTTP is running!");
}
void ESPServerClass::_printHtmlData() {
  _server.send(200, "text/plain", "Hello World");
}

void ESPServerClass::handleRequests() {
  _server.handleClient();
}
