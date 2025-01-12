#include "src/logging.h"
#include "src/server_handling.h"


char ssid[] = "";
char password[] = "";
char* ptrSsid = ssid;
char* ptrPassword = password;
LoggerClass Logger;

ESPServerClass ESPServer;


void setup() {

  ESPServer.connectToWifi(ptrSsid, ptrPassword, 10);
  ESPServer.runServer();

}

void loop() {
    ESPServer.handleRequests();

}

