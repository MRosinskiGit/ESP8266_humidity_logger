// humidity_sensor.cpp
#include <Arduino.h>
#include "logging.h"
extern LoggerClass Logger;
#include <DHT.h>
#include "humidity_sensor.h"


HumiditySensorClass::HumiditySensorClass(int dataGPIO, int dhtType)
  : _dhtObject(dataGPIO, dhtType)  // Initialization of sensor object
{
  _dhtObject.begin();  // Begin communiaction
  Logger.log("Humidity sensor initialized.");
}

void HumiditySensorClass::perforMeasurement() {
  // Reading measurements
  _humidity = _dhtObject.readHumidity();
  _temperature = _dhtObject.readTemperature();

  // Check if data are not error
  if (isnan(_humidity) || isnan(_temperature)) {
    Logger.log("ERRPR: Reading Error!");
  } else {
    Logger.log("Measurement performed.");
  }
}

float HumiditySensorClass::getHumidity() {
  return _humidity;
}

float HumiditySensorClass::getTemperature() {
  return _temperature;
}
