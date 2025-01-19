#include "src/logging.h"
#include "src/server_handling.h"
#include "src/humidity_sensor.h"
#include "src/memory_management.h"

//############### DEFINITIIONS ###############
#define DHTPIN D2      
#define DHTTYPE DHT11 
#define BAUD_RATE_UART 115200

//############### GLOBAL PARAMETERS ###############
char ssid[] = "";  
char password[] = "";   
char* ptrSsid = ssid;
char* ptrPassword = password;
float current_humidity = 0.0;

LoggerClass Logger(BAUD_RATE_UART);

MemoryManager Memory;

HumiditySensorClass HumiditySensor(DHTPIN, DHTTYPE);

ESPServerClass ESPServer(&current_humidity);

void setup() {

  ESPServer.connectToWifi(ptrSsid, ptrPassword, 30);
  ESPServer.runServer();
}

void loop() {

  HumiditySensor.perforMeasurement();
  Memory.addSampleToMemory({ "Datetest",
                             HumiditySensor.getHumidity(),
                             HumiditySensor.getTemperature() });
  current_humidity = HumiditySensor.getHumidity();
  ESPServer.handleRequests();
}
