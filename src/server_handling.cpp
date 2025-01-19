// server_handling.cpp
#include <Arduino.h>
#include "logging.h"
extern LoggerClass Logger;
#include "server_handling.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>



#define WIFI_STATUS_REFRESH_DELAY 100


ESP8266WebServer ESPServerClass::_server(80);  

ESPServerClass::ESPServerClass(float* measurementValue) {
  _measurementValue = measurementValue; // To rework, temporary test
}

wl_status_t ESPServerClass::getWifiStatus() {
  return WiFi.status();
}


bool ESPServerClass::connectToWifi(char* ssid, char* password, int maxDelay) {
  uint16_t connectingTimer = 0;
  bool isPassword;
  IPAddress ip;

  Logger.log("Connecting to " + String(ssid));
  WiFi.begin(ssid, password);

  while (connectingTimer * WIFI_STATUS_REFRESH_DELAY < maxDelay * 1000) {
    switch (getWifiStatus()) {
      case WL_CONNECTED:
        Logger.log(" WiFi Connected");
        ip = WiFi.localIP();
        Logger.log(" Adres IP: " + ip.toString());
        return true;
      case WL_NO_SSID_AVAIL:
        Logger.log(" SSID not available.");
        return false;
      case WL_CONNECT_FAILED:
        Logger.log(" WiFi Connection Failed.");
        return false;
      case WL_WRONG_PASSWORD:
        Logger.log(" WiFi Incorrect Password.");
        return false;
      default:
        Logger.log(".", false);
        delay(WIFI_STATUS_REFRESH_DELAY);
        connectingTimer++;
    }
  }
  Logger.log("\nConnection Timedout.");
  return false;
}

void ESPServerClass::runServer() {
  _server.on("/", [this]() {
    _printHtmlData();
  }); 
  _server.begin();
  Logger.log("HTTP Server is running!");
}



void ESPServerClass::_printHtmlData() {
  if (_measurementValue != nullptr) {
    WiFiClient client = _server.client();  
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/plain");
    client.println("Connection: close");
    client.println();
    client.println("Hello from client.print!");
    client.println("Current Humidity:");
    client.println(String(*_measurementValue));  
  } else {
    Logger.log("Measurement value is not available.");
  }
}


void ESPServerClass::handleRequests() {
  _server.handleClient();
}
