// server_handling.h
#ifndef SERVER_HANDLING_H
#define SERVER_HANDLING_H
#include <Arduino.h>
#include "logging.h"
extern LoggerClass Logger;
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


class ESPServerClass {
public:
  ESPServerClass(float* measurementValue);
  bool connectToWifi(char* ssid, char* password, int maxDelay);
  void runServer();
  wl_status_t getWifiStatus();
  void handleRequests();



private:
  void _printHtmlData();
  bool _isWifiConnected = false;
  static ESP8266WebServer _server;
  float* _measurementValue;
};


#endif
