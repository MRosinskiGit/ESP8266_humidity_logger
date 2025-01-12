// server_handling.h
#ifndef SERVER_HANDLING_H
#define SERVER_HANDLING_H
#include <Arduino.h>
#include "logging.h"
#include <ESP8266WiFi.h>    
#include <ESP8266WebServer.h> 

extern LoggerClass Logger;

class ESPServerClass {
public:
  ESPServerClass();
  bool connectToWifi(char* ssid, char* password, int maxDelay);
  void runServer();
  void handleRequests();


private:
  static void _printHtmlData();
  bool _isWifiConnected = false;
  static ESP8266WebServer _server;
};


#endif
